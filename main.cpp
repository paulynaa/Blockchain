#include "funkc.h"

int main() {
    string failas = "vardai.txt";
    vector<Vartotojas> vartotojai;

    for (int i = 0; i < 10; i++) {
        string vardas = Vartotojas::vardoskaitymas(failas,i);
        string publicKey = Vartotojas::createPublicKey();
        int balansas = Vartotojas::generuojambalansa(i);

        Vartotojas vartotojas(vardas, publicKey, balansas);
        vartotojai.push_back(vartotojas);
    }

    for (const auto& vartotojas : vartotojai) {
        cout << "Vardas: " << vartotojas.getVardas() << endl;
        cout << "Public Key: " << vartotojas.getPublicKey() << endl;
        cout << "Balansas: " << vartotojas.getBalansas() << endl;
        cout << endl;
    }

    return 0;
}
