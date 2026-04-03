/*
** header file della classe Bici
*/

#include <iostream>
#include <cstring>

using namespace std;


class Bici {
    
    float diametro, km;
    string colore;

public:

    void pedala();
    void presentati();
    Bici( float d, string c );
    
    void dipingiti( string nuovoColore );
};
