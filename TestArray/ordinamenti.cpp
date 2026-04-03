/*
* Ordinamento
*/
#include <iostream>
#include <ctime>

using namespace std;

void randomFill( int vett[], int len ) {
    for (int i=0; i<len; i++) vett[i] = rand()%100;
}

void stampa( int vett[], int len ) {
    for (int i=0; i<len; i++) cout << vett[i] << " ";
    cout << endl;
}

void clona( int vett1[], int vett2[], int len ) {
    for (int i=0; i<len; i++) vett2[i] = vett1[i];
}

void scambia( int& x, int& y ) {
    int tmp = x;
    x = y;
    y = tmp;
}

void bubblesort( int vett[], int len, int& confronti, int& scambi ) {
    confronti = scambi = 0;
    for (int i=0; i<len; i++)
        for (int j=0; j<len-1; j++, confronti++)
            if (vett[j]>vett[j+1]) {
                scambi++;
                scambia(vett[j], vett[j+1]);
            }
}

void bubblesort_con_guardia( int vett[], int len, int& confronti, int& scambi ) {
    confronti = scambi = 0;
    for (int i=0; i<len; i++) {
        bool sorted = true;
        for (int j=0; j<len-1; j++, confronti++) {
            if (vett[j]>vett[j+1]) {
                scambi++; sorted=false;
                scambia(vett[j], vett[j+1]);
            }
        }
        if (sorted) break;
    }
}

int main()
{
    const int N = 10;
    int v[N], w[N], c, s;
    srand(time(NULL));

    randomFill(v, N);
    stampa(v, N);
    clona(v, w, N);
    bubblesort(v, N, c, s);
    cout << "Bubblesort: " << c << " confronti e " << s << " scambi:" << endl;
    stampa(v, N);
    bubblesort_con_guardia(w, N, c, s);
    cout << "Bubblesort con guardia: " << c << " confronti e " << s << " scambi:" << endl;
    stampa(w, N);
    cout << endl;

    return 0;
}
