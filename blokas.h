#ifndef BLOKAS_H_INCLUDED
#define BLOKAS_H_INCLUDED

#include <string>
#include <vector>
#include <ctime>
#include "funkc.h"
using namespace std;

class Blokas {
public:
    int blokoNr;
    string prev_block_hash;
    string block_hash;
    int difficulty;
    string timestamp;
    string merkle_root;
    int nonce;
    int versija;
    int transakcijuKiekis;
    string miner;
    vector<Transakcija> transakcijos;

    Blokas(int blokoNr, const string& prev_block_hash, int difficulty, const string& merkle_root, int nonce,
           int versija, const vector<Transakcija>& transakcijos, const string& miner);

    void spausdintiInfo() const;
    void spausdintiTransakcijas() const;
};

#endif

