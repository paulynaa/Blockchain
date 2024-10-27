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

    // Generuojame 10 000 transakciju dapuuuuuscim
    vector<Transakcija> transakcijos;
    for (int i = 0; i < 10000; i++) {
        srand(time(0)*i); // wsio dobrze pracuji ja poniala seed
        int siuntejas_idx = rand() % vartotojai.size();
        int gavejas_idx;

        do {
            gavejas_idx = rand() % vartotojai.size();
        } while (gavejas_idx == siuntejas_idx); // infinite loop?


        int suma = rand() % 1000 + 1;
        Transakcija transakcija(vartotojai[siuntejas_idx].getPublicKey(), vartotojai[gavejas_idx].getPublicKey(), suma);
        transakcijos.push_back(transakcija);
    }

    int nonce = 0;//
    int kelintasblokas=0;
    while(transakcijos.size() > 0){
    // Isrenkame 100 transakciju ir itraukiame i bloka

        vector<Transakcija> blokas;
        int atsitiktinis_indeksas[100];
        for (int i = 0; i < 100; i++) {
            atsitiktinis_indeksas[i] = rand() % transakcijos.size();
            blokas.push_back(transakcijos[atsitiktinis_indeksas[i]]);
            //transakcijos.erase(transakcijos.begin() + atsitiktinis_indeksas);
        }

        //reikia bloka pridet
        // Sukuriame bloko duomenis (Merkle root)
        string blokas_data = Transakcija::calculateMerkleRoot(blokas);

        // Kasame bloka su Proof-of-Work algoritmu
        string block_hash;
        do {
            block_hash = skaiciavimas(blokas_data + to_string(nonce));
            nonce++;
        } while (block_hash.substr(0, 5) != "00000"); // mnie to nenravitsa
        // kaip nuliu skaicius priklauso nuo maisos funkcijos?
        // kad greiciau patikrinti mes ieskom hasha kuris turi 6 nulius, ir tai uztrunka ~1min per bloka,

        cout << "Blokas sukurtas, nonce: " << nonce << ", maisa: " << block_hash << endl;
        cout << "Kelintas blokas " << kelintasblokas << endl;

        for (int i = 0; i < 100; i++) {
            transakcijos.erase(transakcijos.begin() + atsitiktinis_indeksas[i]);
        }
        // Atnaujiname vartotoju balansus pagal transakcijas
        for (const auto& t : blokas) {
            auto siuntejas = find_if(vartotojai.begin(), vartotojai.end(),
                                     [&t](const Vartotojas& v) { return v.getPublicKey() == t.siuntejas; });
            auto gavejas = find_if(vartotojai.begin(), vartotojai.end(),
                                   [&t](const Vartotojas& v) { return v.getPublicKey() == t.gavejas; });

            siuntejas->atnaujintiBalansa(-t.suma);
            gavejas->atnaujintiBalansa(t.suma);
        }
        kelintasblokas++;
    }
// i konsole vesti??
    return 0;
}
