
#include <stdio.h>
#include <string.h>

int main() {

  double d;
  double a;
  double sum;
  double product;
  double min;
  double max;

  printf("Enter 10 floating-point numbers:\n");
  scanf("%lf", &a);
  sum += a;
  product = a;
  min = a;
  max = a;

  for(int i=0; i < 9; i++) {
    scanf("%lf", &d);
    sum += d;
    product *= d;
    if(d < min) {
      min = d;
    }
    if(d > max) {
      max = d;
    }
  }

  printf("Sum is %.5lf\n", sum);
  printf("Min is %.5lf\n", min);
  printf("Max is %.5lf\n", max);
  printf("Product is %.5lf\n", product);
}
