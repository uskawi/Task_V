#include <iostream>
#pragma warning(disable:4996)

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

    FILE* negatyw = fopen("negatyw.bmp", "wb");  // tworzenie negatywu obrazu
    if (negatyw == nullptr)
    {
        cout << "Blad! Nie mozna utworzyc negatywu...!";
        return -1;
    }
    else
    {
        cout << "\nTrwa tworzenie negatywu obrazu...\n";
    }

    fseek(negatyw, 0, SEEK_SET);   // tworzenie negatywu obrazu (dane pliku)
    fwrite(&Plik.typ, sizeof(Plik.typ), 1, negatyw);
    fwrite(&Plik.rozmiarPliku, sizeof(Plik.rozmiarPliku), 1, negatyw);
    fwrite(&Plik.zarezerwowane1, sizeof(Plik.zarezerwowane1), 1, negatyw);
    fwrite(&Plik.zarezerwowane2, sizeof(Plik.zarezerwowane2), 1, negatyw);
    fwrite(&Plik.pozycjaDanych, sizeof(Plik.pozycjaDanych), 1, negatyw);

    fseek(negatyw, 14, SEEK_SET);  // // tworzenie negatywu obrazu (dane obrazu)
    fwrite(&Obraz.wieloscNaglowkaInfo, sizeof(Obraz.wieloscNaglowkaInfo), 1, negatyw);
    fwrite(&Obraz.szerokoscObrazu, sizeof(Obraz.szerokoscObrazu), 1, negatyw);
    fwrite(&Obraz.wysokoscObrazu, sizeof(Obraz.wysokoscObrazu), 1, negatyw);
    fwrite(&Obraz.liczbaWarstKol, sizeof(Obraz.liczbaWarstKol), 1, negatyw);
    fwrite(&Obraz.liczbaBitow, sizeof(Obraz.liczbaBitow), 1, negatyw);
    fwrite(&Obraz.algorytmKompresji, sizeof(Obraz.algorytmKompresji), 1, negatyw);
    fwrite(&Obraz.rozmiarRysunku, sizeof(Obraz.rozmiarRysunku), 1, negatyw);
    fwrite(&Obraz.rozdzielczoscPozioma, sizeof(Obraz.rozdzielczoscPozioma), 1, negatyw);
    fwrite(&Obraz.rozdzielczoscPionowa, sizeof(Obraz.rozdzielczoscPionowa), 1, negatyw);
    fwrite(&Obraz.liczbaKolorowPaleta, sizeof(Obraz.liczbaKolorowPaleta), 1, negatyw);
    fwrite(&Obraz.wazneKolory, sizeof(Obraz.wazneKolory), 1, negatyw);
    fseek(negatyw, sizeof(Plik.pozycjaDanych), SEEK_SET);

    int negatywObraz;
    for (int i = Plik.pozycjaDanych; i < Plik.rozmiarPliku; i++)
    {
        fseek(plik, i, SEEK_SET);
        fseek(negatyw, i, SEEK_SET);
        fread(&negatywObraz, 3, 1, plik);
        negatywObraz = INT_MAX - negatywObraz;
        fwrite(&negatywObraz, 3, 1, negatyw);

        fclose(plik);     // zamkniecie plikow
        fclose(negatyw);

        cout << "\n>>>Utworzono negatyw obrazu." << endl; // wyswietlenie informacji o utworzeniu negatywu
    }


    return 0;
}