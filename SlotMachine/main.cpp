/*
SLOT MACHINE
Creare una classe che permetta di rappresentare una slot machine,
con gli attributi e i metodi necessari per gestire l'estrazione casuale di 3 lettere dell'alfabeto,
ripetibile altre due volte con l'opzione di tenere ferme una o più delle lettere già estratte.
Utilizzare la classe in un main che, partendo da un montepremi predefinito, deve funzionare così:
inserita una puntata girano le tre rotelle della slot machine e appaiono i tre simboli (nel nostro caso tre lettere),
l’utente per due volte può decidere di tenere una o più lettere apparse o fermarsi,
una volta che si ferma se c’è una coppia si vince il doppio della puntata,
se c’è un tris di lettere uguali si vincono un numero di monete pari alla puntata
moltiplicata per la posizione in ordine alfabetico della lettera del tris.
*/

#include <iostream>
#include "SlotMachine.h"
using namespace std;


int main() {

  int montepremi = 1000; // Montepremi predefinito
  srand(time(NULL));

  cout << "Montepremi iniziale: " << montepremi << endl;
  while (true) {
    int puntata;
    cout << "Inserisci la tua puntata (0 per uscire): ";
    cin >> puntata;
    if (puntata == 0) {
      break; // Esci dal ciclo se l'utente inserisce 0
    }
    SlotMachine slot(puntata);
    cout << "Lettere estratte: " << slot.estrai() << endl; // Estrarre le lettere
    for (int i = 0; i < 3; i++) { // Permetti all'utente di tenere le lettere per due volte
      cout << "Indica Y o N per ognuna delle tre lettere che vuoi tenere (es. YNY): ";
      string tenute;
      cin >> tenute;
      if (tenute.length() != 3) {
        cout << "Input non valido. Inserisci esattamente 3 caratteri (Y o N)." << endl;
        i--; // Ripeti l'iterazione corrente
        continue;
      }
      if (tenute.compare("YYY") == 0) {
        cout << "Hai deciso di tenere tutte le lettere. Fermati." << endl;
        break; // L'utente ha deciso di tenere tutte le lettere, esci dal ciclo
      }
      slot.setTenute(tenute[0] == 'Y', tenute[1] == 'Y', tenute[2] == 'Y'); // Imposta le tenute
      cout << "Lettere estratte: " << slot.estrai() << endl; // Estrarre nuovamente le lettere
    }
    // calcola il premio in base alle lettere estratte e alla puntata
    int premio = slot.calcolaPremio();
    cout << "Premio ottenuto: " << premio << endl;
    montepremi += premio;
    if (premio==0) montepremi -= puntata;
    cout << "Montepremi attuale: " << montepremi << endl;
  }
  cout << "Montepremi finale: " << montepremi << endl;
  return 0;
}
