#include <stdio.h>

int AA[100];  		// linearized version of A[10][10]
int BB[100];  		// linearized version of B[10][10]
int CC[100];  		// linearized version of C[10][10]
int m;       		// actual size of A, B and C is [m][m], where m is at most 10

int main() {
  scanf("%d", &m);
  int i, j, n;

  int matrix = m*m;

  for(i = 0; i < matrix; i++) {
    scanf("%d", &AA[i]);
  }

  for(i = 0; i < matrix; i++) {
    scanf("%d", &BB[i]);
  }

  // perform matrix multiplication
  for(i = 0; i < m; i++) {
    for(j = 0; j < m; j++) {
      for(n = 0; n < m; n++) {
        CC[(m * i) + j] += (AA[(m * i) + n] * BB[(m * n) + j]);
      }
    }
  }

  int k, l;
  for(k = 0; k < m; k++) {
    for(l = 0; l < m; l++) {
      printf("%d ", CC[(m * k) + l]);
    }
    printf("\n");
  }
}
