#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
   float fahr, celsius;

 fahr = LOWER;
  while(fahr <= UPPER) {
    celsius = fahr - 32;
    celsius = celsius / 1.8;
    printf("%.2f // %.2f \n", celsius, fahr);
    fahr = fahr + STEP;
  }
  
  return 0;
}
