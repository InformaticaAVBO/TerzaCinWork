/*
** Libro.h
*/

#include <string>
using namespace std;

class Libro {

private:
    string titolo;
    float prezzo;

public:
    int codice;
    Libro();
    Libro(int c, string t, float p);
    void inizializza(int c, string t, float p);
    void visualizza();
    float getPrezzo();
};
