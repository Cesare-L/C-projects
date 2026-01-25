#include <stdio.h>
#define lower 0
#define upper 300
#define step 20

int main(void) {
   float fahr, celcius;

 fahr = lower;
  while(fahr <= upper) {
    celcius = fahr - 32;
    celcius = celcius / 1.8;
    printf("%.2f // %.2f \n", celcius, fahr);
    fahr = fahr + step;
  }
  
  return 0;
}
