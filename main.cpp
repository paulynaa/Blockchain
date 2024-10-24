#include "funkc.h"

int main() {
    // Generuojame 1000 vartotoju
    string failas = "vardai.txt";
    vector<Vartotojas> vartotojai;

    for (int i = 0; i < 1000; i++) {
        string vardas = Vartotojas::vardoskaitymas(failas, i);
        string publicKey = Vartotojas::createPublicKey();
        int balansas = Vartotojas::generuojambalansa(i);
        Vartotojas vartotojas(vardas, publicKey, balansas);
        vartotojai.push_back(vartotojas);
    }

    // Generuojame 10000 transakciju
    vector<Transakcija> transakcijos;
    for (int i = 0; i < 10000; i++) {
        int siuntejas_idx = rand() % vartotojai.size();
        int gavejas_idx;
        do {
            gavejas_idx = rand() % vartotojai.size();
        } while (gavejas_idx == siuntejas_idx);

        int suma = rand() % 1000 + 1;
        Transakcija transakcija(vartotojai[siuntejas_idx].getPublicKey(), vartotojai[gavejas_idx].getPublicKey(), suma);
        transakcijos.push_back(transakcija);
    }

    // Isrenkame 100 transakciju ir itraukiame i bloka
    vector<Transakcija> blokas;
    for (int i = 0; i < 100; i++) {
        int atsitiktinis_indeksas = rand() % transakcijos.size();
        blokas.push_back(transakcijos[atsitiktinis_indeksas]);
        transakcijos.erase(transakcijos.begin() + atsitiktinis_indeksas);
    }

    // Sukuriame bloko duomenis (Merkle root)
    string blokas_data = Transakcija::calculateMerkleRoot(blokas);

    // Kasame bloka su Proof-of-Work algoritmu
    int nonce = 0;
    string block_hash;
    do {
        block_hash = skaiciavimas(blokas_data + to_string(nonce));
        nonce++;
    } while (block_hash.substr(0, 4) != "0000"); // mnie to nenravitsa

    cout << "Blokas sukurtas, nonce: " << nonce << ", maisa: " << block_hash << endl;

    // Atnaujiname vartotoju balansus pagal transakcijas
    for (const auto& t : blokas) {
        auto siuntejas = find_if(vartotojai.begin(), vartotojai.end(),
                                 [&t](const Vartotojas& v) { return v.getPublicKey() == t.siuntejas; });
        auto gavejas = find_if(vartotojai.begin(), vartotojai.end(),
                               [&t](const Vartotojas& v) { return v.getPublicKey() == t.gavejas; });

        siuntejas->atnaujintiBalansa(-t.suma);
        gavejas->atnaujintiBalansa(t.suma);
    }
// i konsole vesti??
    return 0;
}
