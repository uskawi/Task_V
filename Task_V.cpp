#include <iostream>

using namespace std;

struct naglowekPliku {    // dane naglowka pliku
    short typ;
    int rozmiarPliku;
    short zarezerwowane1;
    short zarezerwowane2;
    int pozycjaDanych;
} Plik;