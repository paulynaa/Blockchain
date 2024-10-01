#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <chrono>

using namespace std;

// Bitwise rotation (right shift)
uint32_t rightRotate(uint32_t n, unsigned int d) {
    return (n >> d) | (n << (32 - d));
}

// Padding function to make the message length a multiple of 512 bits
string padMessage(string input) {
    uint64_t messageLength = input.size() * 8;  // Size in bits
    input += (char)0x80;  // Add a single '1' bit (0x80 in hex)

    // Add zero bytes until the message length is 448 mod 512 (so the total will be 512 after adding length)
    while ((input.size() * 8) % 512 != 448) {
        input += (char)0x00;
    }

    // Append the original message length as a 64-bit integer
    for (int i = 7; i >= 0; --i) {
        input += (char)((messageLength >> (i * 8)) & 0xFF);
    }

    return input;
}

// Basic hash function (this can be made more complex to resemble SHA)
vector<uint32_t> hashBlocks(const vector<string>& blocks) {
    // Initial hash values (in SHA-256, these are specific constants)
    uint32_t H[8] = {
        0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
        0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
    };

    // Example constants and operations similar to those used in SHA-256
    for (const string& block : blocks) {
        uint32_t W[16];
        for (int i = 0; i < 16; ++i) {
            W[i] = 0;
            for (int j = 0; j < 4; ++j) {
                W[i] = (W[i] << 8) | (unsigned char)block[i * 4 + j];
            }
        }

        // Simple example of compression and data mixing
        for (int i = 0; i < 16; ++i) {
            H[i % 8] ^= rightRotate(W[i], i % 32);
            H[(i + 1) % 8] += W[i] ^ H[i % 8];
        }
    }

    // Return the final hash
    return vector<uint32_t>(H, H + 8);
}

void printHash(const vector<uint32_t>& hash) {
    for (uint32_t part : hash) {
        cout << hex << setw(8) << setfill('0') << part;
    }
    cout << endl;
}

void skaiciavimas(string h, char H[], char b[], char N[], char L[]) {
    // Step 1: Pad the message
    string paddedInput = padMessage(h);

    // Step 2: Split into 512-bit (64-byte) blocks
    vector<string> blocks;
    for (size_t i = 0; i < paddedInput.size(); i += 64) {
        blocks.push_back(paddedInput.substr(i, 64));
    }

    // Step 3: Hash the blocks using the new hash function
    vector<uint32_t> hashResult = hashBlocks(blocks);

    // Step 4: Output the hash result
    cout << "Hash: ";
    printHash(hashResult);
}

void failogeneratorius(string failopav, int simboliukiek) {
    ofstream F(failopav);
    if (!F.is_open()) {
        cout << "Nepavyko sukurti failo: " << failopav << endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < simboliukiek; i++) {
        char randsimb = rand() % 93 + 33;
        F << randsimb;
    }

    F.close();
    cout << "Sugeneruotas failas: " << failopav << endl;
}

string failoskaitytuvas(string failopav) {
    ifstream failas(failopav);
    if (!failas.is_open()) {
        cout << "Nepavyko atidaryti failo: " << failopav << endl;
        return "";
    }

    string eil;
    stringstream ss;
    while (getline(failas, eil)) {
        ss << eil;
    }
    failas.close();
    return ss.str();
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
        char randsimb = rand() % 93 + 33;
        F1 << randsimb;
        F2 << randsimb;
    }
    int r = rand() % 92 + 33;
    char randsimb = r;
    F1 << randsimb;
    F2 << "~";
    F1.close();
    F2.close();
    cout << "Failai su vienu simbolio skirtumu: " << failas1 << ", " << failas2 << endl;
}

int main() {
    int q;
    string h;
    char H[64];
    char L[64];
    char N[1200];
    char b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int variantas;

    cout << "Pasirinkite norima veiksma: " << endl;
    cout << "1. Ivesti ranka." << endl;
    cout << "2. Tikrinti failus, sudarytus tik is vieno simbolio." << endl;
    cout << "3. Tikrinti failus, kuriuose yra > 1000 simboliu." << endl;
    cout << "4. Tikrinti failus su 1000 simboliais, kurie skiriasi tik 1 simboliu." << endl;
    cout << "5. Baigti darba." << endl;
    cout << "Jusu pasirinkimas: ";
    cin >> variantas;

    switch (variantas) {
        case 1: {
            cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: ";
            cin >> h;
            skaiciavimas(h, H, b, N, L);
            break;
        }

        case 2: {
            cout << "Nuskaitomi failai su vienu simboliu." << endl;
            string simbolis1 = failoskaitytuvas("simbolis1.txt");
            cout << "Failo simbolis1.txt hashas: " << endl;
            skaiciavimas(simbolis1, H, b, N, L);
            string simbolis2 = failoskaitytuvas("simbolis2.txt");
            cout << endl << "Failo simbolis2.txt hashas: " << endl;
            skaiciavimas(simbolis2, H, b, N, L);
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
            cout << "Failo 1random1000.txt hashas: " << endl;
            skaiciavimas(failas1, H, b, N, L);
            cout << endl << "Failo 2random1000.txt hashas: " << endl;
            skaiciavimas(failas2, H, b, N, L);
            break;
        }

        case 4: {
            cout << "Generuojami du failai, kurie skiriasi tik vienu simboliu." << endl;
            failai1simbdiff("1001simboliai1.txt", "1001simboliai2.txt", 1000);
            string failas1 = failoskaitytuvas("1001simboliai1.txt");
            string failas2 = failoskaitytuvas("1001simboliai2.txt");
            cout << "Failo 1001simboliai1.txt hashas: " << endl;
            skaiciavimas(failas1, H, b, N, L);
            cout << endl << "Failo 1001simboliai2.txt hashas: " << endl;
            skaiciavimas(failas2, H, b, N, L);
            break;
        }

        case 5:
            return 0;

        default:
            cout << "Tokio pasirinkimo nera." << endl;
            return 0;
    }

    return 0;
}
