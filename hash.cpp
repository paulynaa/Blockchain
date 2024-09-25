#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;


void wypisywanie(char H[]){
    int x=0;
    for(int j=0;j<4;j++){
        for(int i=0;i<16;i++)
        {
            cout<<H[x]<<" ";x++;
        }
        cout<<endl;
    }
}

void darom64Key(char H[],char b[],int q){
    int x=0,qq=q;
    for(int j=0;j<4;j++){
        for(int i=0;i<16;i++)
        {
            H[x]=b[(i+qq)%16];x++;
        }
        qq+=qq;
    }
    if(q>64){
    q=q-64;
    qq=q;
    x=0;
    for(int j=0;j<q/16;j++){
        for(int i=0;i<q/4;i+=q/16)
        {
            H[x]=b[(qq^2)%16];x++;
        }
        qq+=qq;
    }
    q=q+64;
    }

}

void kopijuojam(char H[],char L[]){
    for(int i=0;i<64;i++){
        L[i]=H[i];
    }
}

void Haszinimas1(char H[],char b[],int q){
    int qq=q;
    if(q>64)
        {qq=q-64+1;}
    for(int i=0;i<64;i=i+qq+1){
        H[i]=b[i%16];
    }
}

void Haszinimas2(char H[],char b[],int q){
    int qq=q%16;
    for(int i=0;i<64;i+=qq+1){
        H[i]=b[i%16];
    }
}

void Haszinimas3(char H[],char b[],int q,char L[]){
    int qq=q;
    if(q>64){qq=q-64+1;}
    for(int i=0;i<64;i+=qq+1){
        if(2*i<64){H[i]=L[2*i];}
        else{H[i]=L[(2*i)%64];}
    }
}

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
    //cout<< eil <<endl;
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
        char randsimb = rand()%93+33;
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
        char randsimb = rand()%93+33;
        F1 << randsimb;
        F2 << randsimb;
    }
    int r= rand()%92+33;
    char randsimb = r;
    F1<<randsimb;
    F2<<"~";
    F1.close();
    F2.close();
    cout << "Failai su vienu simbolio skirtumu: " << failas1 << ", " << failas2 << endl;
}

void skaiciavimas(string h, int q, char H[], char b[], char N[], char L[]){

    int Skaicius=h.size();
    for(int i=0;i<Skaicius;i++){
        q =(int)h[i];
        if(i==0){darom64Key(H,b,q);}

        if(i>1){
            kopijuojam(H,N);
            Haszinimas1(H,N,q);
            Haszinimas2(H,N,q);
            kopijuojam(H,L);
            Haszinimas3(H,N,q,L);
        }
    }
    wypisywanie(H);

}

void skaiciavimas2(string h, int q, char H[], char b[], char N[], char L[]){

    int Skaicius=h.size();
    for(int i=0;i<Skaicius;i++){
        q =(int)h[i];
        if(i==0){darom64Key(H,b,q);}

        if(i>1){
            kopijuojam(H,N);
            Haszinimas1(H,b,q);
            Haszinimas2(H,b,q);
            kopijuojam(H,L);
            Haszinimas3(H,N,q,L);
        }
    }
    wypisywanie(H);

}

void konstitucija(string konst, int q, char H[], char b[], char N[], char L[] ) {
    ifstream kons(konst);
    if (!kons.is_open()) {
        cout << "Ivyko klaida. " << endl;
        return;
    }

    string eilut;
    int eilkiek = 1;
    int visoeil = 0;

    while (!kons.eof() && eilkiek!= 512) {
        int eilnuskaityta = 0;
        auto start = chrono::high_resolution_clock::now();
        while (eilnuskaityta < eilkiek && getline(kons, eilut)) {
            eilnuskaityta++;
            visoeil++;
            string laikinas=eilut;
            skaiciavimas(laikinas,q,H,b,N,L);
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << eilkiek << " nuskaite per "<< elapsed.count() << " sek " << endl;
        eilkiek *= 2;

        if (kons.eof()) {
            break;
        }
    }
    wypisywanie(H);
    kons.close();
}

int main() {

    int q,y,laikinas,z;
    string h,c,p;
    char b[17]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char H[64];
    char L[64];
    char N[1200];
    char Laikinas[1200];
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
            cin>>h;
            skaiciavimas(h, q, H, b , N, L);
            break;
        }

        case 2: {
            cout << "Nuskaitomi failai su vienu simboliu." << endl;
            string simbolis1 = failoskaitytuvas("simbolis1.txt");
            cout << "Failo simbolis1.txt hashas: "  << endl;
            skaiciavimas(simbolis1, q,H,b,N,L);
            string simbolis2 = failoskaitytuvas("simbolis2.txt");
            cout<< endl;
            cout << "Failo simbolis2.txt hashas: "  << endl;
            skaiciavimas(simbolis2, q,H,b,N,L);
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
            cout << "Failo 1random1000.txt hashas: "  << endl;
            skaiciavimas2(failas1, q,H,b,N,L);
            cout<< endl;
            cout << "Failo 2random1000.txt hashas: "  << endl;
            skaiciavimas2(failas2, q,H,b,N,L);
            break;
        }

        case 4: {
            cout << "Generuojami du failai, kurie skiriasi tik vienu simboliu." << endl;
            failai1simbdiff("1000.txt", "1000skirtumas.txt", 1000);
            string tekstas1 = failoskaitytuvas("1000.txt");
            string tekstas2 = failoskaitytuvas("1000skirtumas.txt");
            cout << "Failo 1000.txt hashas: "  << endl;
            skaiciavimas2(tekstas1, q,H,b,N,L);
            cout<< endl;
            cout << "Failo 1000skirtumas.txt hashas: "  << endl;
            skaiciavimas2(tekstas2, q,H,b,N,L);
            break;
        }

        case 5: {
            cout << "Nuskaitomas tuscias failas." << endl;
            ofstream tuscias("tuscias.txt");
            tuscias.close();
            string tusciasfailas = failoskaitytuvas("tuscias.txt");
            cout << "Failo tuscias.txt hashas: "  << endl;
            skaiciavimas(tusciasfailas, q,H,b,N,L);
            break;
        }

        case 6: {
            string konst = "konstitucija.txt";
            konstitucija(konst, q,H,b,N,L);


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
