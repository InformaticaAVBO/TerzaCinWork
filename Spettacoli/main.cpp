#include <iostream>
#include <string>

using namespace std;

int menu( string[] opzioni, int totOpzioni ) {
    int numOpzione = 0;
    do {
        cout << "Scegli una voce dal menu:" << endl;
        cout << "0) Esci" << endl;
        for (int i=0; i<totOpzioni; i++) {
            cout << (i+1) << ") " << opzioni[i] << endl;
        }
        cin >> numOpzione;
    } while (numOpzione>=0 && numOpzione<=totOpzioni);
    return numOpzione;
}



int main() {

    string[] voci={"Uno", "Due", "Tre"};
    switch( menu(voci, 3) ) {
        case 0: break;
        case 1: cout << "Uno" << endl; break;
        case 2: cout << "Due" << endl; break;
        case 3: cout << "Tre" << endl; break;
    }

}


