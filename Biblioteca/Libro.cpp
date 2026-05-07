/*
** Libro.cpp
*/

#include <iostream>
#include "Libro.h"

Libro::Libro(){
    codice = 0;
}

Libro::Libro(int c, string t, float p){
    inizializza(c,t,p);
}

void Libro::inizializza(int c, string t, float p){
    codice = c;
    titolo = t;
    prezzo = p;
}

void Libro::visualizza(){
    cout << "Libro #" << codice << " - " << titolo << " - prezzo: " << prezzo << endl;
}

float Libro::getPrezzo() {
    return prezzo;
}
