#include "funkc.h"
#include "blokas.h"
#include <set>
#include <random>
#include <ctime>
#include <iostream>

int main() {
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> balansopaskirtymas(100, 1000000);
    std::uniform_int_distribution<int> transakcijossumpas(200, 20000);
    std::uniform_int_distribution<int> vartindexpask(0, 999);

    // Generuojam vartotojus
    std::string failas = "vardai.txt";
    std::vector<Vartotojas> vartotojai;
    std::vector<UTXO> utxoPool;

    for (int i = 0; i < 1000; i++) {
        std::string vardas = Vartotojas::vardoskaitymas(failas, i);
        std::string publicKey = Vartotojas::createPublicKey();
        int pradinisbalansas = balansopaskirtymas(generator);
        vartotojai.push_back(Vartotojas(vardas, publicKey, pradinisbalansas));

        utxoPool.push_back(UTXO(publicKey, pradinisbalansas, "genesis_" + std::to_string(i)));
    }

    // Generuojam transakcijas
    std::vector<Transakcija> transakcijos;
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
            std::cerr << "Klaida: Transakcijos ID nesutampa su maiðos reikðme." << std::endl;
            trnesekminga++;
            continue;
        }
        // Tik sekmingas prie bloko
        trsekminga++;
        transakcijos.push_back(newTransaction);
        vartotojai[siuntejas_idx].atnaujintiBalansa(-suma);
        vartotojai[gavejas_idx].atnaujintiBalansa(suma);
    }

    std::cout << "--- Transakciju apzvalga ---\n";
    std::cout << "Sekmingos transakcijos: " << trsekminga << "\n";
    std::cout << "Atmestos transakcijos: " << trnesekminga << "\n";
    std::cout << "------------------------------------------------------------\n";

    // Kuriam blokus
    std::string prev_block_hash = "0000000000000000";
    int kelintasBlokas = 0;
    int difficulty = 3;
    std::vector<Blokas> blokai;

    while (!transakcijos.empty()) {
        std::vector<Transakcija> blokas;
        int numTransactions = std::min(100, static_cast<int>(transakcijos.size()));
        std::set<int> usedIndexes;

        while (usedIndexes.size() < numTransactions) {
            int randIndex = rand() % transakcijos.size();
            if (usedIndexes.insert(randIndex).second) {
                blokas.push_back(transakcijos[randIndex]);
            }
        }

        // Calculate Merkle root
        std::string merkle_root = Transakcija::calculateMerkleRoot(blokas);
        std::string block_hash;
        int nonce = 0;

        do {
            block_hash = skaiciavimas(merkle_root + std::to_string(nonce));
            nonce++;
        } while (block_hash.substr(0, difficulty) != std::string(difficulty, '0'));

        // Ekranizuojam detales
        Blokas naujasBlokas(kelintasBlokas, prev_block_hash, difficulty, merkle_root, nonce, 1, blokas, "Paulina");
        naujasBlokas.block_hash = block_hash;
        naujasBlokas.spausdintiInfo();
        blokai.push_back(naujasBlokas);

        for (const auto& t : blokas) {
            std::vector<UTXO> siuntejoUTXO;
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
        std::cout << "Iveskite bloko numeri, kurio transakcijas norite pamatyti: ";
        std::cin >> blokas_nr;

        if (blokas_nr >= 0 && blokas_nr < blokai.size()) {
            blokai[blokas_nr].spausdintiTransakcijas();
        } else {
            std::cout << "Neteisingas bloko numeris.\n";
        }

        std::cout << "Ar norite pamatyti kito bloko transakcijas? (y=taip/n=ne): ";
        std::cin >> pasirinkimas;
    } while (pasirinkimas == 'y');

    return 0;
}
