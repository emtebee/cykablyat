#include <iostream>
#include <ctime>
#include <cstdlib>
#include<cmath>
using namespace std;

int main()
{
    const int ROZMIAR = 100;
    int Z[ROZMIAR];
    srand(time(NULL));

    for (int i = 0; i < ROZMIAR; i++) {
        Z[i] = rand() % 10;
    }

    int szukana = rand() % 10;
    cout << "Poszukiwana liczba: " << szukana << endl;

    cout << "Tablica Z z zaznaczonymi wystapieniami liczby " << szukana << ":" << endl;
    for (int i = 0; i < ROZMIAR; i++)
    {
        if (Z[i] == szukana)
        {
            cout << "[" << Z[i] << "]\t"; 
        }
        else
        {
            cout << Z[i] << "\t";
        }
    }
    cout << endl;

    int liczbaWystapien = 0;
    for (int i = 0; i < ROZMIAR; i++) 
    {
        if (Z[i] == szukana) 
        {
            liczbaWystapien++;
        }
    }

    int *P = new int[liczbaWystapien];
    int indeksP = 0;
    
    for (int i = 0; i < ROZMIAR; i++) 
    {
        if (Z[i] == szukana) 
        {
            P[indeksP++] = i;
        }
    }

    cout << "Indeksy wystapien liczby " << szukana << " w tablicy Z: ";
    for (int i = 0; i < liczbaWystapien; i++)
    {
        cout << P[i] << " ";
    }
    cout << endl;

    delete[] P;

    return 0;
}
