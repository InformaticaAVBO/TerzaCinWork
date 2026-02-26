
#include <stdio.h>
#include "/opt/homebrew/opt/libomp/include/omp.h"

int main(void)
{
  #pragma omp parallel
    printf("Hello, world.\n");
  return 0;
}
