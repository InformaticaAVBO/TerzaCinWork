/*
** Biblioteca.h
*/

#include "Libro.h"

#define MAXLIBRI 100

class Biblioteca {

private:
    Libro libro[MAXLIBRI];
    int n;

public:

    Biblioteca();
    
    void aggiungi();

    void catalogo();
    
    float getPrezzo( int c );

};
