#include "blokas.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

Blokas::Blokas(int blokoNr, const string& prev_block_hash, int difficulty, const string& merkle_root, int nonce,
               int versija, const vector<Transakcija>& transakcijos, const string& miner)
    : blokoNr(blokoNr), prev_block_hash(prev_block_hash), block_hash(""), difficulty(difficulty),
      timestamp(""), merkle_root(merkle_root), nonce(nonce), versija(versija),
      transakcijuKiekis(transakcijos.size()), miner(miner), transakcijos(transakcijos) {
    time_t now = time(nullptr);
    now += 2 * 3600;
    stringstream ss;
    ss << put_time(gmtime(&now), "%Y-%m-%d %H:%M:%S");
    timestamp = ss.str();
}

void Blokas::spausdintiInfo() const {
    cout << "Bloko Nr.: " << blokoNr << "\n"
         << "Praeito Bloko Hash: " << prev_block_hash << "\n"
         << "Dabartinio Bloko Hash: " << block_hash << "\n"
         << "Difficulty Target: " << difficulty << "\n"
         << "Laiko zyma: " << timestamp << "\n"
         << "Merkle Root Hash: " << merkle_root << "\n"
         << "Nonce: " << nonce << "\n"
         << "Versija: " << versija << "\n"
         << "Transakciju kiekis: " << transakcijuKiekis << "\n"
         << "Miner: " << miner << "\n";
}

void Blokas::spausdintiTransakcijas() const {
    int nr = 1;
    for (const auto& t : transakcijos) {
        cout << "Nr: " << nr++ << " Siuntejas: " << t.siuntejas << ", Gavejas: " << t.gavejas
             << ", Suma: " << t.suma << "\n" << "    ID: " << t.transakcijosID << "\n";
    }
}
