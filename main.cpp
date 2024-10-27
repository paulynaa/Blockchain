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

    // padaryti dar viena klase su bloku info, perziuret antraste. irasyti ten: difficulty 1, timestamp, prev_block_hash, merkel root hash, sito bloko hasha,
    // versija 1, nonce, transakciju kiekis(galimybe perziureti transakcijas), bloko eiles numeris, miner: Paulina!.
    // utxo modelis
    // detalus isvedimas

        vector<Transakcija> blokas;
        int atsitiktinis_indeksas[100];
        for (int i = 0; i < 100; i++) {
            atsitiktinis_indeksas[i] = rand() % transakcijos.size();
            blokas.push_back(transakcijos[atsitiktinis_indeksas[i]]);
        }
// difficulty 1, nes programa nerunina pakankamai ilgai kad padaryti difficulty, bet jei runnintu, tai w srednik blok za (9,2sek) to w tydzien
// wychodzi +- 65 739 .
// priklausomai nuo to keisti difficulty. greiciausiai po pirmos savaites reiktu ji padidint, nes pow reikalauja mazai resursu, ty daro blokus per greitai.
//
        // Sukuriame bloko duomenis (Merkle root)
        string blokas_data = Transakcija::calculateMerkleRoot(blokas);

        // Kasame bloka su Proof-of-Work algoritmu
        string block_hash;
        do {
            block_hash = skaiciavimas(blokas_data + to_string(nonce));
            nonce++;
        } while (block_hash.substr(0, 6) != "000000"); // mnie to nenravitsa
        // kaip nuliu skaicius priklauso nuo maisos funkcijos?

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
        string prev_block_hash = skaiciavimas(block_hash + blokas_data + prev_block_hash); // wypisywac przed tym jak funkcija suveiks
    }
    return 0;
}
