#include "funkc.h"
#include "blokas.h"

int main() {
    // Generuojame 1000 vartotoju
    string failas = "vardai.txt";
    vector<Vartotojas> vartotojai;
    for (int i = 0; i < 1000; i++) {
        string vardas = Vartotojas::vardoskaitymas(failas, i);
        string publicKey = Vartotojas::createPublicKey();
        int balansas = Vartotojas::generuojambalansa(i);
        vartotojai.push_back(Vartotojas(vardas, publicKey, balansas));
    }

    // Generuojame 10 000 transakciju
    vector<Transakcija> transakcijos;
    for (int i = 0; i < 10000; i++) {
        srand(time(0) * i);
        int siuntejas_idx = rand() % vartotojai.size();
        int gavejas_idx;
        do {
            gavejas_idx = rand() % vartotojai.size();
        } while (gavejas_idx == siuntejas_idx);
        int suma = rand() % 100000 + 200;

        if (i % 1000 == 0) {
            cout << "Kuriama transakcija " << i + 1 << " is 10000..." << endl;
        }

        transakcijos.push_back(Transakcija(vartotojai[siuntejas_idx].getPublicKey(), vartotojai[gavejas_idx].getPublicKey(), suma));
    }

    string prev_block_hash = "0000000000000000";
    int kelintasBlokas = 0;
    int difficulty = 1;
    vector<Blokas> blokai;

    while (transakcijos.size() > 0) {
        vector<Transakcija> blokas;
        int atsitiktinis_indeksas[100];
        for (int i = 0; i < 100; i++) {
            atsitiktinis_indeksas[i] = rand() % transakcijos.size();
            blokas.push_back(transakcijos[atsitiktinis_indeksas[i]]);
        }

        // Merkle Root hash
        string merkle_root = Transakcija::calculateMerkleRoot(blokas);

        // Proof-of-Work process
        string block_hash;
        int nonce = 0;
        do {
            block_hash = skaiciavimas(merkle_root + to_string(nonce));
            nonce++;
        } while (block_hash.substr(0, difficulty) != string(difficulty, '0'));

        // Create and print block
        Blokas naujasBlokas(kelintasBlokas, prev_block_hash, difficulty, merkle_root, nonce, 1, blokas, "Paulina");
        naujasBlokas.block_hash = block_hash;
        naujasBlokas.spausdintiInfo();
        blokai.push_back(naujasBlokas);

        for (const auto& t : blokas) {
            auto siuntejas = find_if(vartotojai.begin(), vartotojai.end(), [&](const Vartotojas& v) { return v.getPublicKey() == t.siuntejas; });
            auto gavejas = find_if(vartotojai.begin(), vartotojai.end(), [&](const Vartotojas& v) { return v.getPublicKey() == t.gavejas; });

            if (siuntejas != vartotojai.end() && gavejas != vartotojai.end()) {
                siuntejas->atnaujintiBalansa(-t.suma);
                gavejas->atnaujintiBalansa(t.suma);
            }
        }

        for (int i = 0; i < 100; i++) {
            transakcijos.erase(transakcijos.begin() + atsitiktinis_indeksas[i]);
        }

        prev_block_hash = block_hash;
        kelintasBlokas++;
    }

    char pasirinkimas;
    do {
        int blokas_nr;
        cout << "Iveskite bloko numeri, kurio transakcijas norite pamatyti: ";
        cin >> blokas_nr;

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
