#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int A[10];  // Tablica 10 elementów
int klucz;  // Klucz do wyszukiwania
int maks;   // Największa wartość
int minn;   // Najmniejsza wartość
int np1 = -1;    // Pierwsza liczba nieparzysta
int np2 = -1;    // Druga liczba nieparzysta
int pozycja = -1;  // Pozycja klucza (jeżeli zostanie znaleziona)

int main() {
    srand(time(NULL));  // Losowanie liczb zależne od czasu

    // Pobieranie klucza od użytkownika
    cout << "Podaj klucz: ";
    cin >> klucz;

    // Wypełnianie tablicy losowymi liczbami z przedziału [-10, 9]
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 20 - 10;  // Losowe liczby od -10 do 9
    }

    // Inicjalizacja maksymalnej i minimalnej wartości pierwszym elementem tablicy
    maks = A[0];
    minn = A[0];

    // Szukanie maksymalnej wartości
    for (int i = 0; i < 10; i++) {
        if (A[i] > maks) {
            maks = A[i];
        }
    }

    // Szukanie minimalnej wartości
    for (int i = 0; i < 10; i++) {
        if (A[i] < minn) {
            minn = A[i];
        }
    }

    // Szukanie pozycji klucza
    for (int i = 0; i < 10; i++) {
        if (A[i] == klucz) {
            pozycja = i + 1;  // Zapisanie pozycji (indeks + 1)
            break;  // Przerwanie pętli po znalezieniu
        }
    }

    // Szukanie pierwszej liczby nieparzystej
    for (int i = 0; i < 10; i++) {
        if ((A[i] % 2) != 0) { // Jeżeli liczba nieparzysta
            if (np1 == -1) { // Znajdujemy pierwszą liczbę nieparzystą
                np1 = A[i];
            }
            else { // Znajdujemy drugą liczbę nieparzystą
                np2 = A[i];
                break;  // Kończymy po znalezieniu drugiej liczby
            }
        }
    }

    // Wyświetlanie zawartości tablicy
    cout << "Zawartosc tablicy: ";
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Wyświetlanie wyników
    if (pozycja != -1) {
        cout << "Pozycja klucza to: " << pozycja << endl;
    }
    else {
        cout << "Klucz nie zostal znaleziony w tablicy." << endl;
    }

    cout << "Najwieksza wartosc: " << maks << endl;
    cout << "Najmniejsza wartosc: " << minn << endl;

    if (np1 != -1) {
        cout << "Pierwsza liczba nieparzysta: " << np1 << endl;
    }
    else {
        cout << "Nie znaleziono liczby nieparzystej." << endl;
    }

    if (np2 != -1) {
        cout << "Druga liczba nieparzysta: " << np2 << endl;
    }
    else {
        cout << "Nie znaleziono drugiej liczby nieparzystej." << endl;
    }

    return 0;
}

