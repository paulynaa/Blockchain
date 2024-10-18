#include "funkc.h"

int main() {
    string failas = "vardai.txt";
    vector<Vartotojas> vartotojai;

    for (int i = 0; i < 1000; i++) {
        string vardas = Vartotojas::vardoskaitymas(failas, i);
        string publicKey = Vartotojas::createPublicKey();
        int balansas = Vartotojas::generuojambalansa(i);

        Vartotojas vartotojas(vardas, publicKey, balansas);
        vartotojai.push_back(vartotojas);
    }

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

    vector<Transakcija> blokas;
    for (int i = 0; i < 100; i++) {
        int atsitiktinis_indeksas = rand() % transakcijos.size();
        blokas.push_back(transakcijos[atsitiktinis_indeksas]);
        transakcijos.erase(transakcijos.begin() + atsitiktinis_indeksas);
    }

    string blokas_data = "";
    for (const auto& t : blokas) {
        blokas_data += t.transakcijosID;
    }

    int nonce = 0;
    string block_hash;
    do {
        block_hash = skaiciavimas(blokas_data + to_string(nonce));
        nonce++;
    } while (block_hash.substr(0, 4) != "0000"); // trzeba zmienic mysla

    cout << "Blokas sukurtas, nonce: " << nonce << ", maiða: " << block_hash << endl;

    for (const auto& t : blokas) {
        auto siuntejas = find_if(vartotojai.begin(), vartotojai.end(),
                                 [&t](const Vartotojas& v) { return v.getPublicKey() == t.siuntejas; });
        auto gavejas = find_if(vartotojai.begin(), vartotojai.end(),
                               [&t](const Vartotojas& v) { return v.getPublicKey() == t.gavejas; });

        siuntejas->atnaujintiBalansa(-t.suma);
        gavejas->atnaujintiBalansa(t.suma);
    }

    return 0;
}
