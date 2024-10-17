#ifndef FUNKC_H_INCLUDED
#define FUNKC_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <chrono>
#include <random>
#include <unordered_map>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

class Vartotojas {
private:
    string vardas;
    string publicKey;
    int balansas;

public:
    // Constructor
    Vartotojas(const string& vardas, const string& publicKey, int balansas);

    // Getters
    string getVardas() const;
    string getPublicKey() const;
    int getBalansas() const;

    static string vardoskaitymas(const string& failiukas, int i);
    static int generuojambalansa(int i);
    static string createPublicKey();
};

string skaiciavimas(const string& input);
vector<uint32_t> hashblokai(const vector<string>& blocks);
string padMessage(const string& input);
uint32_t rightRotate(uint32_t n, unsigned int d);
string hashToString(const vector<uint32_t>& hash);

#endif // FUNKC_H_INCLUDED
