#include <stdio.h>
#include <string.h>

int NchooseK(int n, int k);

int main() {

  int n, k;

  do {

    printf("Enter two integers (for n and k) separated by space:\n");
    scanf("%i %i", &n, &k);
    int binomial = NchooseK(n, k);
    printf("%d\n", binomial);

  } while(n != 0 || k != 0);

}

int NchooseK(int n, int k) {

  if(k == 0) {
    return 1;
  } else if(n == k) {
    return 1;
  }

  return NchooseK(n-1, k-1) + NchooseK(n-1, k);

}
