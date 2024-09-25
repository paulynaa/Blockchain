#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;

string failoskaitytuvas(string failopav) {
    ifstream failas(failopav);
    if (!failas.is_open()) {
        cout << "Nepavyko atidaryti failo: " << failopav << endl;
        return "";
    }

    string eil;
    stringstream ss;
    while (getline(failas, eil)){
        ss << eil;
    }

    failas.close();
    return ss.str();
}

void failogeneratorius(string failopav, int simboliukiek) {
    ofstream F(failopav);
    if (!F.is_open()) {
        cout << "Nepavyko sukurti failo: " << failopav << endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < simboliukiek; i++) {
        char randsimb = rand() ;
        F << randsimb;
    }

    F.close();
    cout << "Sugeneruotas failas: " << failopav << endl;
}

void failai1simbdiff(string failas1, string failas2, int simboliukiek) {
    ofstream F1(failas1);
    ofstream F2(failas2);
    if (!F1.is_open() || !F2.is_open()) {
        cout << "Ivyko klaida." << endl;
        return;
    }

    srand(time(0));

    for (int i = 0; i < simboliukiek; i++) {
        char randsimb = rand() ;
        F1 << randsimb;
        F2 << randsimb;
    }
// nwm jak zmienic

    F1.close();
    F2.close();
    cout << "Failai su vienu simbolio skirtumu: " << failas1 << ", " << failas2 << endl;
}

void konstitucija(string konst) {
    ifstream kons(konst);
    if (!kons.is_open()) {
        cout << "Ivyko klaida. " << endl;
        return;
    }

    string eilut;
    int eilkiek = 1;
    int visoeil = 0;

    while (!kons.eof()) {
        int eilnuskaityta = 0;

        auto start = chrono::high_resolution_clock::now();

        while (eilnuskaityta < eilkiek && getline(kons, eilut)) {
            eilnuskaityta++;
            visoeil++;
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        cout << eilkiek << " nuskaite per "
                  << elapsed.count() << " sek " << endl;

        eilkiek *= 2;

        if (kons.eof()) {
            break;
        }
    }

    kons.close();
}


int main() {
    int variantas;
    cout << "Pasirinkite norima veiksma: " << endl;
    cout << "1. Ivesti ranka." << endl;
    cout << "2. Tikrinti failus, sudarytus tik is vieno simbolio." << endl;
    cout << "3. Tikrinti failus, kuriuose yra > 1000 simboliu." << endl;
    cout << "4. Tikrinti failus su 1000 simboliais, kurie skiriasi tik 1 simboliu." << endl;
    cout << "5. Atidaryti faila 'tuscias.txt'." << endl;
    cout << "6. Skaiciuoti faila 'konstitucija.txt'." << endl;
    cout << "7. Baigti darba." << endl;
    cout << "Jusu pasirinkimas: "; cin >> variantas;

    switch (variantas) {
        case 1: {
            string ivestis;
            cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: ";
            cin>>ivestis;
            break;
        }

        case 2: {
            cout << "Nuskaitomi failai su vienu simboliu." << endl;
            string simbolis1 = failoskaitytuvas("simbolis1.txt");
            string simbolis2 = failoskaitytuvas("simbolis2.txt");
            break;
        }

        case 3: {
            int pasirinkimas;
            cout << "Ar norite sugeneruoti du naujus failus? Spauskite 1, jei taip. Bet koks kitas skaicius - ne." << endl;
            cin >> pasirinkimas;
            if (pasirinkimas == 1) {
                failogeneratorius("1random1000.txt", 1050);
                failogeneratorius("2random1000.txt", 1050);
            }

            string failas1 = failoskaitytuvas("1random1000.txt");
            string failas2 = failoskaitytuvas("2random1000.txt");
            break;
        }

        case 4: {
            cout << "Generuojami du failai, kurie skiriasi tik vienu simboliu." << endl;
            failai1simbdiff("1000.txt", "1000skirtumas.txt", 1000);

            string tekstas1 = failoskaitytuvas("1000.txt");
            string tekstas2 = failoskaitytuvas("1000skirtumas.txt");
            break;
        }

        case 5: {
            cout << "Nuskaitomas tuscias failas." << endl;
            ofstream tuscias("tuscias.txt");
            tuscias.close();
            string tuscias_failas = failoskaitytuvas("tuscias.txt");
            break;
        }

        case 6: {
            //string konsti = konstitucija("konstitucija.txt");

        break;
        }

        case 7: {
            cout << "Darbas baigtas." << endl;
            break;
        }

        default: {
            cout << "Ivedete neteisinga skaiciu. Bandykite dar karta." << endl;
            break;
        }
    }

    return 0;
}
