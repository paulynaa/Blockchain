#include "funkc.h"
#include "blokas.h"
#include <omp.h>
using namespace std;

int main() {
    int numatyta_threads = omp_get_max_threads();
    cout << "Maksimalus giju skaicius: " << numatyta_threads << endl;
    default_random_engine generator(time(0));
    uniform_int_distribution<int> balansopaskirtymas(100, 1000000);
    uniform_int_distribution<int> vartindexpask(0, 999);

    string failas = "vardai.txt";
    vector<Vartotojas> vartotojai;
    vector<UTXO> utxoPool;
    vector<Transakcija> mempool;

    for (int i = 0; i < 1000; i++) {
        string vardas = Vartotojas::vardoskaitymas(failas, i);
        string publicKey = Vartotojas::createPublicKey();
        int pradinisbalansas = balansopaskirtymas(generator);
        vartotojai.push_back(Vartotojas(vardas, publicKey, pradinisbalansas));
        utxoPool.push_back(UTXO(publicKey, pradinisbalansas, "genesis_" + to_string(i)));
    }

    int trsekminga = 0;
    int trnesekminga = 0;
    for (int i = 0; i < 10000; i++) {
        int siuntejas_idx = vartindexpask(generator);
        int gavejas_idx;
        do {
            gavejas_idx = vartindexpask(generator);
        } while (gavejas_idx == siuntejas_idx);

        int totalAvailable = vartotojai[siuntejas_idx].getBalansas();
        if (totalAvailable < 200) {
            trnesekminga++;
            continue;
        }
        uniform_int_distribution<int> transakcijossumpas(100000, min(600000, totalAvailable));
        int suma = transakcijossumpas(generator);
        vector<UTXO> senderUTXOs = getUTXOs(vartotojai[siuntejas_idx], utxoPool);

        if (senderUTXOs.empty()) {
        trnesekminga++;
        continue;
    }
        if (totalAvailable < suma) {
            trnesekminga++;
            continue;
        }

        Transakcija newTransaction(vartotojai[siuntejas_idx].getPublicKey(), vartotojai[gavejas_idx].getPublicKey(), suma);
        if (!newTransaction.patikrintiID()) {
            cerr << "Klaida: Transakcijos ID nesutampa su maisos reiksme." << endl;
            trnesekminga++;
            continue;
        }
        trsekminga++;
        mempool.push_back(newTransaction);
    }

    cout << "--- Transakciju apzvalga ---\n";
    cout << "Sekmingos transakcijos: " << trsekminga << "\n";
    cout << "Atmestos transakcijos: " << trnesekminga << "\n";
    cout << "------------------------------------------------------------\n";

    int pasirinkimas;
    cout << "Pasirinkite:\n";
    cout << "1 - Generuoti ir kasti visus blokus\n";
    cout << "2 - Kasti 5 bloku kandidatus\n";
    cout << "Iveskite pasirinkima: ";
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        string prev_block_hash = "0000000000000000";
        int kelintasBlokas = 0;
        int difficulty = 3;
        vector<Blokas> blokai;
        string merkle_root = "";
        string block_hash;
        int nonce = 0;

        do {
            block_hash = skaiciavimas(merkle_root + to_string(nonce));
            nonce++;
        } while (block_hash.substr(0, difficulty) != string(difficulty, '0'));

        Blokas genesisBlokas(kelintasBlokas, prev_block_hash, difficulty, merkle_root, nonce, 1, {}, "Paulina");
        genesisBlokas.block_hash = block_hash;
        genesisBlokas.spausdintiInfo();
        blokai.push_back(genesisBlokas);
        prev_block_hash = block_hash;
        kelintasBlokas++;

        while (!mempool.empty()) {
            vector<Transakcija> blokas;
            int numTransactions = min(100, static_cast<int>(mempool.size()));
            unordered_set<int> usedIndexes;
            while (usedIndexes.size() < numTransactions) {
                int randIndex = rand() % mempool.size();
                if (usedIndexes.insert(randIndex).second) {
                    blokas.push_back(mempool[randIndex]);
                }
            }

            merkle_root = Transakcija::calculateMerkleRoot(blokas);
            nonce = 0;
            do {
                block_hash = skaiciavimas(merkle_root + to_string(nonce));
                nonce++;
            } while (block_hash.substr(0, difficulty) != string(difficulty, '0'));

            Blokas naujasBlokas(kelintasBlokas, prev_block_hash, difficulty, merkle_root, nonce, 1, blokas, "Paulina");
            naujasBlokas.block_hash = block_hash;
            naujasBlokas.spausdintiInfo();
            blokai.push_back(naujasBlokas);

            for (const auto& tx : blokas) {
                auto siuntejas = find_if(vartotojai.begin(), vartotojai.end(), [&](Vartotojas& v) {
                    return v.getPublicKey() == tx.siuntejas;
                });
                auto gavejas = find_if(vartotojai.begin(), vartotojai.end(), [&](Vartotojas& v) {
                    return v.getPublicKey() == tx.gavejas;
                });

                vector<UTXO> senderUTXOs = getUTXOs(*siuntejas, utxoPool);
                spendUTXOs(senderUTXOs, tx.suma, utxoPool);
                siuntejas->atnaujintiBalansa(-tx.suma);
                gavejas->atnaujintiBalansa(tx.suma);
                utxoPool.push_back(UTXO(gavejas->getPublicKey(), tx.suma, tx.transakcijosID));
            }

            for (const auto& index : usedIndexes) {
                mempool.erase(mempool.begin() + index);
            }
            prev_block_hash = block_hash;
            kelintasBlokas++;

        }
        char pasirinkimas;
            do {
                int blokas_nr;
                cout << "Iveskite bloko numeri, kurio transakcijas norite pamatyti: ";
                cin >> blokas_nr;
                blokas_nr =1;
                if (blokas_nr >= 0 && blokas_nr < blokai.size()) {
                    blokai[blokas_nr].spausdintiTransakcijas();
                } else {
                    cout << "Neteisingas bloko numeris.\n";
                }

                cout << "Ar norite pamatyti kito bloko transakcijas? (y=taip/n=ne): ";
                cin >> pasirinkimas;
            } while (pasirinkimas == 'y');

    } else if (pasirinkimas == 2) {
        int difficulty = 5;
        int numThreads = 1;
        omp_set_num_threads(numThreads);
        vector<vector<Transakcija>> kandidatai;

        for (int i = 0; i < 5; i++) {
            vector<Transakcija> blokas;
            for (int j = 0; j < 100; j++) {
                int randIndex = rand() % mempool.size();
                blokas.push_back(mempool[randIndex]);
            }
            kandidatai.push_back(blokas);
        }

        bool iskastas = false;
        chrono::seconds maxlaikas(5);
        int maxbandymu = 100000;

        while (!iskastas) {
            #pragma omp parallel for shared(iskastas)
            for (int i = 0; i < kandidatai.size(); i++) {
                if (iskastas) continue;

                vector<Transakcija>& blokas = kandidatai[i];
                string merkle_root = Transakcija::calculateMerkleRoot(blokas);
                string block_hash;
                int nonce = 0;
                bool sekmingaiIskastas = false;

                while (!iskastas && nonce < maxbandymu) {
                    block_hash = skaiciavimas(merkle_root + to_string(nonce));
                    if (block_hash.substr(0, difficulty) == string(difficulty, '0')) {
                        #pragma omp critical
                        {
                            if (!iskastas) {
                                iskastas = true;
                                sekmingaiIskastas = true;
                                cout << "Kandidatas Nr. " << (i + 1) << " sekmingai iskastas gijos ID "
                                     << omp_get_thread_num() << " su nonce: " << nonce << endl;

                                for (const auto& tx : blokas) {
                                    auto siuntejas = find_if(vartotojai.begin(), vartotojai.end(), [&](Vartotojas& v) {
                                        return v.getPublicKey() == tx.siuntejas;
                                    });
                                    auto gavejas = find_if(vartotojai.begin(), vartotojai.end(), [&](Vartotojas& v) {
                                        return v.getPublicKey() == tx.gavejas;
                                    });

                                    vector<UTXO> senderUTXOs = getUTXOs(*siuntejas, utxoPool);
                                    spendUTXOs(senderUTXOs, tx.suma, utxoPool);
                                    siuntejas->atnaujintiBalansa(-tx.suma);
                                    gavejas->atnaujintiBalansa(tx.suma);
                                    utxoPool.push_back(UTXO(gavejas->getPublicKey(), tx.suma, tx.transakcijosID));
                                }
                            }
                        }
                        break;
                    }
                    nonce++;
                }
                if (!sekmingaiIskastas && nonce >= maxbandymu) {
                    #pragma omp critical
                    {
                        cout << "Pasiektas bandymu limitas: " << maxbandymu << " kandidato Nr. " << (i + 1) << " kasimui." << endl;
                    }
                }
            }
            if (!iskastas) {
                maxlaikas *= 2;
                maxbandymu *= 2;
                cout << "Neiskastas joks blokas. Pratesiame laika iki " << maxlaikas.count()
                     << " sekundziu ir bandymu limita iki " << maxbandymu << "." << endl;
            }
        }
    } else {
        cout << "Neteisingas pasirinkimas." << endl;
    }

    return 0;
}
