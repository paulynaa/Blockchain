#include "funkc.h"
#include "blokas.h"
#include <set>
#include <random>
#include <ctime>
#include <iostream>

int main() {
    default_random_engine generator(time(0));
    uniform_int_distribution<int> balansopaskirtymas(100, 1000000);
    uniform_int_distribution<int> transakcijossumpas(200, 20000);
    uniform_int_distribution<int> vartindexpask(0, 999);

    // Generuojam vartotojus
    string failas = "vardai.txt";
    vector<Vartotojas> vartotojai;
    vector<UTXO> utxoPool;

    for (int i = 0; i < 1000; i++) {
        string vardas = Vartotojas::vardoskaitymas(failas, i);
        string publicKey = Vartotojas::createPublicKey();
        int pradinisbalansas = balansopaskirtymas(generator);
        vartotojai.push_back(Vartotojas(vardas, publicKey, pradinisbalansas));

        utxoPool.push_back(UTXO(publicKey, pradinisbalansas, "genesis_" + to_string(i)));
    }

    // Generuojam transakcijas
    vector<Transakcija> transakcijos;
    int trsekminga = 0;
    int trnesekminga = 0;

    for (int i = 0; i < 10000; i++) {
        int siuntejas_idx = vartindexpask(generator);
        int gavejas_idx;
        do {
            gavejas_idx = vartindexpask(generator);
        } while (gavejas_idx == siuntejas_idx);

        int suma = transakcijossumpas(generator);
        int siuntejobalansas = vartotojai[siuntejas_idx].getBalansas();

        if (siuntejobalansas < suma) {
            trnesekminga++;
            continue;
        }

        Transakcija newTransaction(vartotojai[siuntejas_idx].getPublicKey(), vartotojai[gavejas_idx].getPublicKey(), suma);
        if (!newTransaction.patikrintiID()) {
            cerr << "Klaida: Transakcijos ID nesutampa su maiðos reikðme." << endl;
            trnesekminga++;
            continue;
        }
        // Tik sekmingas prie bloko
        trsekminga++;
        transakcijos.push_back(newTransaction);
        vartotojai[siuntejas_idx].atnaujintiBalansa(-suma);
        vartotojai[gavejas_idx].atnaujintiBalansa(suma);
    }

    cout << "--- Transakciju apzvalga ---\n";
    cout << "Sekmingos transakcijos: " << trsekminga << "\n";
    cout << "Atmestos transakcijos: " << trnesekminga << "\n";
    cout << "------------------------------------------------------------\n";

    // Kuriam blokus
    string prev_block_hash = "0000000000000000";
    int kelintasBlokas = 0;
    int difficulty = 3;
    vector<Blokas> blokai;

    while (!transakcijos.empty()) {
        vector<Transakcija> blokas;
        int numTransactions = min(100, static_cast<int>(transakcijos.size()));
        set<int> usedIndexes;

        while (usedIndexes.size() < numTransactions) {
            int randIndex = rand() % transakcijos.size();
            if (usedIndexes.insert(randIndex).second) {
                blokas.push_back(transakcijos[randIndex]);
            }
        }

        // Calculate Merkle root
        string merkle_root = Transakcija::calculateMerkleRoot(blokas);
        string block_hash;
        int nonce = 0;

        do {
            block_hash = skaiciavimas(merkle_root + to_string(nonce));
            nonce++;
        } while (block_hash.substr(0, difficulty) != string(difficulty, '0'));

        // Ekranizuojam detales
        Blokas naujasBlokas(kelintasBlokas, prev_block_hash, difficulty, merkle_root, nonce, 1, blokas, "Paulina");
        naujasBlokas.block_hash = block_hash;
        naujasBlokas.spausdintiInfo();
        blokai.push_back(naujasBlokas);

        for (const auto& t : blokas) {
            vector<UTXO> siuntejoUTXO;
            int likonepanaudota = 0;

            for (auto it = utxoPool.begin(); it != utxoPool.end();) {
                if (it->address == t.siuntejas) {
                    siuntejoUTXO.push_back(*it);
                    likonepanaudota += it->value;
                    it = utxoPool.erase(it);
                } else {
                    ++it;
                }
                if (likonepanaudota >= t.suma) break;
            }

            if (likonepanaudota >= t.suma) {
                utxoPool.push_back(UTXO(t.gavejas, t.suma, t.transakcijosID));
                if (likonepanaudota > t.suma) {
                    utxoPool.push_back(UTXO(t.siuntejas, likonepanaudota - t.suma, t.transakcijosID + "_change"));
                }
            }
        }

        for (const auto& index : usedIndexes) {
            transakcijos.erase(transakcijos.begin() + index);
        }

        prev_block_hash = block_hash;
        kelintasBlokas++;
    }

    //
    char pasirinkimas;
    do {
        int blokas_nr;
        cout << "Iveskite bloko numeri, kurio transakcijas norite pamatyti: ";
        cin >> blokas_nr;
        blokas_nr-=1;
        if (blokas_nr >= 0 && blokas_nr < blokai.size()) {
            blokai[blokas_nr].spausdintiTransakcijas();
        } else {
            cout << "Neteisingas bloko numeris.\n";
        }

        cout << "Ar norite pamatyti kito bloko transakcijas? (y=taip/n=ne): ";
        cin >> pasirinkimas;
    } while (pasirinkimas == 'y');

    return 0;
}
