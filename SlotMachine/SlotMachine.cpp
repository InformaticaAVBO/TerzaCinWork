/*
Classe SLOT MACHINE
*/

#include "SlotMachine.h"
#include <cstdlib>
using namespace std;

  SlotMachine::SlotMachine( int puntata ) {
    this->puntata = puntata;
    this->tentativi = 0;
    for (int i = 0; i < 3; i++) {
        tenute[i] = false; // Inizializza le tenute a false
    }
  }

  void SlotMachine::setTenute(bool t1, bool t2, bool t3) {
      tenute[0] = t1;
      tenute[1] = t2;
      tenute[2] = t3;
  }

  // Metodo per estrarre casualmente le lettere
  string SlotMachine::estrai() {
      // Codice per estrarre casualmente le lettere e assegnarle alle rotelle
      for (int i = 0; i < 3; i++) {
          if (!tenute[i]) {
              rotelle[i] = 'A' + rand() % 26; // Estrae una lettera casuale tra A e Z
          }
      }
      return string(rotelle, 3); // Restituisce le lettere estratte come stringa
  }

  int SlotMachine::calcolaPremio() {
      // Codice per calcolare il premio in base alle lettere estratte e alla puntata
      if (rotelle[0] == rotelle[1] && rotelle[1] == rotelle[2]) {
          // Tris di lettere uguali
          return puntata * (rotelle[0] - 'A' + 1); // Premio basato sulla posizione alfabetica della lettera
      } else if (rotelle[0] == rotelle[1] || rotelle[1] == rotelle[2] || rotelle[0] == rotelle[2]) {
          // Coppia di lettere uguali
          return puntata * 2; // Doppio della puntata
      } else {
          return 0; // Nessun premio
      }
  }
