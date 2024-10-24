#include "funkc.h"

Vartotojas::Vartotojas(const string& vardas, const string& publicKey, int balansas)
    : vardas(vardas), publicKey(publicKey), balansas(balansas) {}

string Vartotojas::getVardas() const { return vardas; }
string Vartotojas::getPublicKey() const { return publicKey; }
int Vartotojas::getBalansas() const { return balansas; }

void Vartotojas::atnaujintiBalansa(int suma) { balansas += suma; }

string Vartotojas::vardoskaitymas(const string& failiukas, int i) {
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
    srand(time(0) * i);
    return names[rand() % names.size()];
}

int Vartotojas::generuojambalansa(int i) {
    srand(time(0) * i);
    return rand() % 1000000 + 100;
}

string Vartotojas::createPublicKey() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string s;
    for (int i = 0; i < 32; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return s;
}

Transakcija::Transakcija(const string& siuntejas, const string& gavejas, int suma)
    : siuntejas(siuntejas), gavejas(gavejas), suma(suma) {
    transakcijosID = sukurtiTransakcijosID(siuntejas, gavejas, suma);
}

string Transakcija::sukurtiTransakcijosID(const string& siuntejas, const string& gavejas, int suma) {
    stringstream ss;
    ss << siuntejas << gavejas << suma << time(0);
    return skaiciavimas(ss.str());
}

// Merkle root skaiciavimas
string Transakcija::calculateMerkleRoot(const vector<Transakcija>& transakcijos) {
    vector<string> hashes;
    for (const auto& t : transakcijos) {
        hashes.push_back(t.transakcijosID);
    }

    while (hashes.size() > 1) {
        if (hashes.size() % 2 != 0) {
            hashes.push_back(hashes.back());  // Jei poru nelyginis skaicius, padvigubiname paskutine reiksme
        }

        vector<string> new_hashes;
        for (size_t i = 0; i < hashes.size(); i += 2) {
            new_hashes.push_back(skaiciavimas(hashes[i] + hashes[i + 1]));
        }
        hashes = new_hashes;
    }

    return hashes.front();  // Graziname saknies maisa
}

// SHA-256 (Proof-of-Work)
uint32_t rightRotate(uint32_t n, unsigned int d) {
    return (n >> d) | (n << (32 - d));
}

string padMessage(const string& input) {
    uint64_t messageLength = input.size() * 8;
    string padded = input + (char)0x80;
    while ((padded.size() * 8) % 512 != 448) {
        padded += (char)0x00;
    }
    for (int i = 7; i >= 0; i--) {
        padded += (char)((messageLength >> (i * 8)) & 0xFF);
    }
    return padded;
}

string skaiciavimas(const string& input) { // prapali keys
    string paddedInput = padMessage(input);
    uint32_t h0 = 0x6a09e667, h1 = 0xbb67ae85, h2 = 0x3c6ef372, h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f, h5 = 0x9b05688c, h6 = 0x1f83d9ab, h7 = 0x5be0cd19;

    for (size_t chunkIndex = 0; chunkIndex < paddedInput.size(); chunkIndex += 64) {
        uint32_t w[64] = {0};
        for (int i = 0; i < 16; i++) {
            w[i] = (paddedInput[chunkIndex + i * 4 + 0] & 0xFF) << 24 |
                   (paddedInput[chunkIndex + i * 4 + 1] & 0xFF) << 16 |
                   (paddedInput[chunkIndex + i * 4 + 2] & 0xFF) << 8 |
                   (paddedInput[chunkIndex + i * 4 + 3] & 0xFF);
        }

        for (int i = 16; i < 64; i++) {
            uint32_t s0 = rightRotate(w[i - 15], 7) ^ rightRotate(w[i - 15], 18) ^ (w[i - 15] >> 3);
            uint32_t s1 = rightRotate(w[i - 2], 17) ^ rightRotate(w[i - 2], 19) ^ (w[i - 2] >> 10);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }

        uint32_t a = h0, b = h1, c = h2, d = h3;
        uint32_t e = h4, f = h5, g = h6, h = h7;

        for (int i = 0; i < 64; i++) {
            uint32_t S1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25);
            uint32_t ch = (e & f) ^ (~e & g);
            uint32_t temp1 = h + S1 + ch + 0x428a2f98 + w[i];
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

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    return hashToString({h0, h1, h2, h3, h4, h5, h6, h7});
}

string hashToString(const vector<uint32_t>& hash) {
    stringstream ss;
    for (const auto& part : hash) {
        ss << hex << setw(8) << setfill('0') << part;
    }
    return ss.str();
}
