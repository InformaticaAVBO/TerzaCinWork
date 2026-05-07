/*
** Biblioteca.cpp
*/

#include <iostream>
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    for (int i=0; i<MAXLIBRI; i++) libro[i].codice=0;
    n=0;
}

void Biblioteca::aggiungi() {
    int c;
    float p;
    string t;
    if (n>=MAXLIBRI-1) { cout<<"Biblioteca piena!"<<endl; return; }
    cout << "Inserisci il codice del nuovo libro: ";
    cin >> c;
    cout << "Inserisci il titolo del nuovo libro: ";
    cin >> t;
    cout << "Inserisci il prezzo del nuovo libro: ";
    cin >> p;
    libro[n++].inizializza(c,t,p);
}

void Biblioteca::catalogo() {
    for (int i=0; i<n; i++)
        libro[i].visualizza();
}

float Biblioteca::getPrezzo( int c ) {
    for (int i=0; i<n; i++)
        if (libro[i].codice==c) return libro[i].getPrezzo();
    return -1;
}
