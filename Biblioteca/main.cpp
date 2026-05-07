/*
** Main di Biblioteca
*/

#include <iostream>
#include <string>

#include "Biblioteca.h"

using namespace std;

int main()
{
    Biblioteca b;
    int scelta=0, codice;
    do {
        cout << "\nMenu\n1 Aggiungi libro\n2 Catalogo\n3 Prezzo\n4 Esci\nScegli:" << endl;
        cin >> scelta;
        switch (scelta) {
            case 1:
                b.aggiungi();
                break;
            case 2:
                b.catalogo();
                break;
            case 3:
                cout << "Inserisci il codice del libro: ";
                cin >> codice;
                cout << "Il prezzo del libro è: " << b.getPrezzo(codice) << endl;
                break;
            case 4:
                cout << "Ok, usciamo dal programma." << endl;
                break;
            default:
                cout << "Scelta non valida" << endl;
        }
    } while (scelta!=4);

    return 0;
}
