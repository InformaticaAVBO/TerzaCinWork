
#include <iostream>
#include <omp.h>
using namespace std;

int main( int argc, char* argv[] ) {

  int count=0, N=200000000;
  double *a = new double[N];
  double *b = new double[N];
  double tick, tock;

  int nt = omp_get_num_procs();
  if ( argc>1 && atoi(argv[1])>0 && atoi(argv[1])<nt ) nt = atoi(argv[1]);
  cout << "Uso " << nt << " thread su " << omp_get_num_procs() << " a disposizione" << endl;
  omp_set_num_threads(nt);

  // ciclo in seriale
  tick = omp_get_wtime();
  for (int i=0; i<N; i++) {
    a[i] = 1.0 / (i*i);
  }
  tock = omp_get_wtime();
  printf("Vettore di %d elementi inizializzato in %f secondi\n", N, tock-tick);

  // ciclo in parallelo
  tick = omp_get_wtime();
  #pragma omp parallel for
  for (int i=0; i<N; i++) {
    b[i] = 1.0 / (i*i);
  }
  tock = omp_get_wtime();
  printf("Vettore di %d elementi inizializzato in %f secondi\n", N, tock-tick);

  #pragma omp parallel
  {
    count++;
  }
  cout << count << endl;

}
