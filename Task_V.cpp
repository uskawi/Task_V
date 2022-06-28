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

int main(int arc, char* argv[]) {    // glowny program
    FILE* plik = fopen("test.bmp", "rb");

    if (plik == nullptr)
    {
        cout << "Blad! Nie mozna otworzyc pliku!";
        return -1;
    }
    else
    {
        cout << "Plik zostal otwarty!\n";
    }

    cout << "\n-----INFORMACJE O PLIKU-----" << endl;  // wyswietlenie informacji o pliku
    fread(&Plik.typ, sizeof(Plik.typ), 1, plik);
    cout << "Typ pliku: " << hex << Plik.typ << endl;
    fread(&Plik.rozmiarPliku, sizeof(Plik.rozmiarPliku), 1, plik);
    cout << "Rozmiar pliku (w bajtach): " << dec << Plik.rozmiarPliku << endl;
    fread(&Plik.zarezerwowane1, sizeof(Plik.zarezerwowane1), 1, plik);
    cout << "Zarezerwowane 1: " << Plik.zarezerwowane1 << endl;
    fread(&Plik.zarezerwowane2, sizeof(Plik.zarezerwowane2), 1, plik);
    cout << "Zarezerwowane 2: " << Plik.zarezerwowane2 << endl;
    fread(&Plik.pozycjaDanych, sizeof(Plik.pozycjaDanych), 1, plik);
    cout << "Pozycja danych obrazkowych: " << Plik.pozycjaDanych << endl;


    return 0;
}