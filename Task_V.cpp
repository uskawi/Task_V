#include <iostream>

using namespace std;

struct naglowekPliku {    // dane naglowka pliku
    short typ;
    int rozmiarPliku;
    short zarezerwowane1;
    short zarezerwowane2;
    int pozycjaDanych;
} Plik;

struct naglowekObrazu {    // dane naglowka obrazu
    int wieloscNaglowkaInfo;
    int szerokoscObrazu;
    int wysokoscObrazu;
    short liczbaWarstKol;
    short liczbaBitow;
    int algorytmKompresji;
    int rozmiarRysunku;
    int rozdzielczoscPozioma;
    int rozdzielczoscPionowa;
    int liczbaKolorowPaleta;
    int wazneKolory;
} Obraz;