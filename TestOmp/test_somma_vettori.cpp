
#include <iostream>
#include <omp.h>
using namespace std;

const int N = 200000000;

double elabora( int a[], int b[], int c[]) {
  double tick = omp_get_wtime();
  for (int i=0; i<N; i++) {
    c[i] = a[i] + b[i];
  }
  double tock = omp_get_wtime();
  return tock-tick;
}

double elabora_parallelo( int a[], int b[], int c[]) {
  double tick = omp_get_wtime();
  #pragma omp parallel for
	  for (int i=0; i<N; i++) {
		c[i] = a[i] + b[i];
	  }
  double tock = omp_get_wtime();
  return tock-tick;
}

int main( int argc, char* argv[] ) {

  int *a = new int[N];
  int *b = new int[N];
  int *c = new int[N];

  int nt = omp_get_num_procs();
  if ( argc>1 && atoi(argv[1])>0 && atoi(argv[1])<nt ) nt = atoi(argv[1]);
  cout << "Uso " << nt << " thread su " << omp_get_num_procs() << " a disposizione" << endl;
  omp_set_num_threads(nt);

  // inizializzo i primi due vettori
  #pragma omp parallel for
  for (int i=0; i<N; i++) { a[i] = 1; b[i] = 2; }

  // ciclo in seriale
  printf( "Somma di due vettori da %d elementi eseguita in %f secondi\n", N, elabora(a, b, c) );

  // ciclo in parallelo
  printf("Somma di due vettori da %d elementi eseguita in %f secondi\n", N, elabora_parallelo(a, b, c));

}