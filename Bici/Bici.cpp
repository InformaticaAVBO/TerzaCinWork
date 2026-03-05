/*
** definizione della classe Bici
*/

#include <iostream>
#include <cstring>
#include "Bici.h"

using namespace std;

// definisco i metodi della classe Bici

Bici::Bici( float d, string c ) {
    diametro = d;
    colore = c;
    km = 0;
}
    
void Bici::pedala()
{
    km++;     
}

void Bici::presentati()
{
    cout<<"Sono una bici di colore " << colore << " e con due ruote di diametro " << diametro << " ed ho fatto " << km << " chilometri" << endl;
}

void Bici::dipingiti( string nuovoColore ) {
    colore = nuovoColore;
}
