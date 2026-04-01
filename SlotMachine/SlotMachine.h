/*
** SlotMachine.h
*/

#include <string>
#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
using namespace std;

class SlotMachine {

private:

  char rotelle[3]; // Le tre rotelle della slot machine
  bool tenute[3]; // Indica se le rotelle sono tenute ferme o meno
  int puntata; // La puntata dell'utente
  int tentativi; // Il numero di tentativi effettuati

public:

    SlotMachine( int puntata );
    void setTenute(bool t1, bool t2, bool t3);
    int calcolaPremio();
    string estrai();

};

#endif // SLOTMACHINE_H
