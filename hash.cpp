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

// Enhanced hash function (similar to SHA-256 structure)
vector<uint32_t> enhancedHashBlocks(const vector<string> &blocks) {
    // Initial hash values (similar to SHA-256)
    uint32_t H[8] = {
        0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
        0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
    };

    // Constants (similar to SHA-256)
    const uint32_t K[64] = {
        0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
        0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
        0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
        0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
        0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
        0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
        0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
        0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
    };

    // Process each block
    for (const string &block : blocks) {
        uint32_t W[64];

        // Prepare message schedule (similar to SHA-256)
        for (int i = 0; i < 16; ++i) {
            W[i] = 0;
            for (int j = 0; j < 4; ++j) {
                W[i] = (W[i] << 8) | (unsigned char)block[i * 4 + j];
            }
        }
        for (int i = 16; i < 64; ++i) {
            uint32_t s0 = rightRotate(W[i - 15], 7) ^ rightRotate(W[i - 15], 18) ^ (W[i - 15] >> 3);
            uint32_t s1 = rightRotate(W[i - 2], 17) ^ rightRotate(W[i - 2], 19) ^ (W[i - 2] >> 10);
            W[i] = W[i - 16] + s0 + W[i - 7] + s1;
        }

        // Initialize working variables
        uint32_t a = H[0], b = H[1], c = H[2], d = H[3];
        uint32_t e = H[4], f = H[5], g = H[6], h = H[7];

        // Main compression loop
        for (int i = 0; i < 64; ++i) {
            uint32_t S1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25);
            uint32_t ch = (e & f) ^ (~e & g);
            uint32_t temp1 = h + S1 + ch + K[i] + W[i];
            uint32_t S0 = rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Add this block's hash to the result
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    // Return the final hash (digest)
    return vector<uint32_t>(H, H + 8);
}

// Function to print the hash in hexadecimal format
void printHash(const vector<uint32_t>& hash) {
    for (uint32_t part : hash) {
        cout << hex << setw(8) << setfill('0') << part;
    }
    cout << endl;
}

// Hash calculation function using the enhanced hash
void skaiciavimas(string h, char H[], char b[], char N[], char L[]) {
    // Step 1: Pad the message
    string paddedInput = padMessage(h);

    // Step 2: Split into 512-bit (64-byte) blocks
    vector<string> blocks;
    for (size_t i = 0; i < paddedInput.size(); i += 64) {
        blocks.push_back(paddedInput.substr(i, 64));
    }

    // Step 3: Hash the blocks using the enhanced hash function
    vector<uint32_t> hashResult = enhancedHashBlocks(blocks);

    // Step 4: Output the hash result
    cout << "Hash: ";
    printHash(hashResult);
}

// Function to generate a file with random characters
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

// Function to read the contents of a file
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

// Function to generate two files with a 1-symbol difference
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
            string h;
            cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: ";
            cin >> h;
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            skaiciavimas(h, H, b, N, L);
            break;
        }

        case 2: {
            cout << "Nuskaitomi failai su vienu simboliu." << endl;
            string simbolis1 = failoskaitytuvas("simbolis1.txt");
            cout << "Failo simbolis1.txt hashas: " << endl;
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
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
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
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
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
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
