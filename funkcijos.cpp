#include "funkc.h"

Vartotojas::Vartotojas(const string& vardas, const string& publicKey, int balansas)
    : vardas(vardas), publicKey(publicKey), balansas(balansas) {}

// Getters
string Vartotojas::getVardas() const { return vardas; }
string Vartotojas::getPublicKey() const { return publicKey; }
int Vartotojas::getBalansas() const { return balansas; }

string Vartotojas::vardoskaitymas(const string& failiukas,int i) {
    ifstream file(failiukas);
    if (!file) {
        cerr << "Nepavyko atidaryti failo " << failiukas << endl;
        return "";
    }

    vector<string> names;
    string name;

    while (getline(file, name)) {
        if (!name.empty()) {
            names.push_back(name);
        }
    }
    file.close();

    if (names.empty()) {
        cerr << "Klaida " << failiukas << endl;
        return "";
    }
    srand(time(0)*i);
    return names[rand()%2942];
}

int Vartotojas::generuojambalansa(int i) {
    srand(time(0)*i^2);
    return rand()%1000000+100;
}

void createPrivateKey(char Prekey[], const char H[]) {
    for (int i = 0; i < 63; i++) {
        Prekey[i] = H[rand() % 16];
    }
    Prekey[64] = '\0';
}

string Vartotojas::createPublicKey() {
    char H[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    char Prekey[65];
    createPrivateKey(Prekey, H);
    string privk(Prekey);
    string publicKey = skaiciavimas(privk);
    return publicKey;
}

uint32_t rightRotate(uint32_t n, unsigned int d) {
    return (n >> d) | (n << (32 - d));
}

string padMessage(const string& input) {
    uint64_t messageLength = input.size() * 8;
    string padded = input + (char)0x80;
    while ((padded.size() * 8) % 512 != 448) {
        padded += (char)0x00;
    }
    for (int i = 7; i >= 0; --i) {
        padded += (char)((messageLength >> (i * 8)) & 0xFF);
    }
    return padded;
}

vector<uint32_t> hashblokai(const vector<string>& blocks) {
    uint32_t H[8] = {
        0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
        0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
    };

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

    for (const string& block : blocks) {
        uint32_t W[64];
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

        uint32_t a = H[0], b = H[1], c = H[2], d = H[3];
        uint32_t e = H[4], f = H[5], g = H[6], h = H[7];

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

        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    return vector<uint32_t>(H, H + 8);
}

string hashToString(const vector<uint32_t>& hash) {
    stringstream ss;
    for (uint32_t part : hash) {
        ss << hex << setw(8) << setfill('0') << part;
    }
    return ss.str();
}

string skaiciavimas(const string& input) {
    string paddedInput = padMessage(input);
    vector<string> blocks;
    for (size_t i = 0; i < paddedInput.size(); i += 64) {
        blocks.push_back(paddedInput.substr(i, 64));
    }
    vector<uint32_t> hashResult = hashblokai(blocks);
    return hashToString(hashResult);
}
