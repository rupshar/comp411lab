#include <stdio.h>

int A[10][10];
int B[10][10];
int C[10][10];
int matrix;

int main() {
  scanf("%d", &matrix);
  int i, j;

  for(i = 0; i < matrix; i++) {
    for(j = 0; j < matrix; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for(i = 0; i < matrix; i++) {
    for(j = 0; j < matrix; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  int m, n, o;;

  for(m = 0; m < matrix; m++) {
    for(n = 0; n < matrix; n++) {
      for(o = 0; o < matrix; o++) {
        C[m][n] += (A[m][o]*B[o][n]);
      }
    }
  }

  int k, l;
  for(k = 0; k < matrix; k++) {
    for(l = 0; l < matrix; l++) {
      printf("%6d", C[k][l]);
    }
    printf("\n");
  }
}
