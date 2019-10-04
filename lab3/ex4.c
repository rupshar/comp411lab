/* Example: matrices represented by 2-dimensional arrays */

#include <stdio.h>

int main()
{
  int A[3][3];    // matrix A
  int B[3][3];    // matrix B
  int C[3][3];    // matrix to store their sum

  printf("Please enter 9 values for matrix A:\n");
  scanf("%d%d%d", &A[0][0], &A[0][1], &A[0][2]);
  scanf("%d%d%d", &A[1][0], &A[1][1], &A[1][2]);
  scanf("%d%d%d", &A[2][0], &A[2][1], &A[2][2]);

  printf("Please enter 9 values for matrix B:\n");
  scanf("%d%d%d", &B[0][0], &B[0][1], &B[0][2]);
  scanf("%d%d%d", &B[1][0], &B[1][1], &B[1][2]);
  scanf("%d%d%d", &B[2][0], &B[2][1], &B[2][2]);

  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }

  printf("C = B + A =\n");
  int k, l;
  for(k = 0; k < 3; k++) {
    for(l = 0; l < 3; l++) {
      printf("%*d", 10, C[k][l]);
    }
    printf("\n");
  }
}
