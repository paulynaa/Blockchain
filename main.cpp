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
        transakcijos.push_back(Transakcija(vartotojai[siuntejas_idx].getPublicKey(), vartotojai[gavejas_idx].getPublicKey(), suma));
    }

    string prev_block_hash = "0000000000000000";
    int kelintasBlokas = 0;
    int difficulty = 1;

    vector<Blokas> blokai;
    while (transakcijos.size() > 0) {
        // Atsitiktinai pasirenkame 100 transakciju
        vector<Transakcija> blokas;
        int atsitiktinis_indeksas[100];
        for (int i = 0; i < 100; i++) {
            atsitiktinis_indeksas[i] = rand() % transakcijos.size();
            blokas.push_back(transakcijos[atsitiktinis_indeksas[i]]);
        }

        //  Merkle Root hash
        string merkle_root = Transakcija::calculateMerkleRoot(blokas);

        // Proof-of-Work procesas
        string block_hash;
        int nonce = 0;
        do {
            block_hash = skaiciavimas(merkle_root + to_string(nonce));
            nonce++;
        } while (block_hash.substr(0, difficulty) != string(difficulty, '0'));

        // Sukuriame ir spausdiname bloka
        Blokas naujasBlokas(kelintasBlokas, prev_block_hash, difficulty, merkle_root, nonce, 1, blokas, "Paulina");
        naujasBlokas.block_hash = block_hash;
        naujasBlokas.spausdintiInfo();
        blokai.push_back(naujasBlokas);
        // Transakciju salinimas is saraso ir vartotoju balansu atnaujinimas
        for (int i = 0; i < 100; i++) {
            transakcijos.erase(transakcijos.begin() + atsitiktinis_indeksas[i]);
        }
        for (const auto& t : blokas) {
            auto siuntejas = find_if(vartotojai.begin(), vartotojai.end(),[&t](const Vartotojas& v) { return v.getPublicKey() == t.siuntejas; });
            auto gavejas = find_if(vartotojai.begin(), vartotojai.end(), [&t](const Vartotojas& v) { return v.getPublicKey() == t.gavejas; });

            siuntejas->atnaujintiBalansa(-t.suma);
            gavejas->atnaujintiBalansa(t.suma);
        }
        prev_block_hash = block_hash;
        kelintasBlokas++;
    }

    int blokas_nr;
    cout << "Iveskite bloko numeri, kurio transakcijas norite pamatyti: ";
    cin >> blokas_nr;

    if (blokas_nr >= 0 && blokas_nr < blokai.size()) {
        blokai[blokas_nr].spausdintiTransakcijas();
    } else {
        cout << "Neteisingas bloko numeris.\n";
    }

    return 0;
}
