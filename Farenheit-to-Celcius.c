#include <stdio.h>

int main(void) {
   float fahr, celcius;
   int upper, lower, step;

  lower = 0;
  upper = 300;

  step = 20;

 fahr = lower;
  while(fahr <= upper) {
    celcius = fahr - 32;
    celcius = celcius / 1.8;
    printf("%f // %f \n", celcius, fahr);
    fahr = fahr + step;
  }
  
  return 0;
}
