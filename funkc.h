#ifndef FUNKC_H_INCLUDED
#define FUNKC_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

class Vartotojas {
private:
    string vardas;
    string publicKey;
    int balansas;

public:
    Vartotojas(const string& vardas, const string& publicKey, int balansas);
    string getVardas() const;
    string getPublicKey() const;
    int getBalansas() const;
    void atnaujintiBalansa(int suma);

    static string vardoskaitymas(const string& failiukas, int i);
    static int generuojambalansa(int i);
    static string createPublicKey();
};

class Transakcija {
public:
    string siuntejas;
    string gavejas;
    int suma;
    string transakcijosID;

    Transakcija(const string& siuntejas, const string& gavejas, int suma);
    static string sukurtiTransakcijosID(const string& siuntejas, const string& gavejas, int suma);
    static string calculateMerkleRoot(const vector<Transakcija>& transakcijos);
};

string skaiciavimas(const string& input);
vector<uint32_t> hashblokai(const vector<string>& blocks);
string padMessage(const string& input);
uint32_t rightRotate(uint32_t n, unsigned int d);
string hashToString(const vector<uint32_t>& hash);

#endif // FUNKC_H_INCLUDED
