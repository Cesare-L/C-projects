#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
   float fahr, celcius;

 fahr = LOWER;
  while(fahr <= UPPER) {
    celcius = fahr - 32;
    celcius = celcius / 1.8;
    printf("%.2f // %.2f \n", celcius, fahr);
    fahr = fahr + STEP;
  }
  
  return 0;
}
