#include<stdio.h>
#include<stdlib.h>

#define ZERO 0
#define ONE 1

int length;

int binaryMaker(int len, int arr[], int i);

int main() {

  scanf("%d", &length);
  int pattern[length];
  binaryMaker(length, pattern, 0);

  return 0;

}

int binaryMaker(int len, int arr[], int i) {

  if(i == len) {
    for(int i = 0; i < len; i++) {
      printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
  }

  arr[i] = 0;
  binaryMaker(len, arr, i + 1);

  arr[i] = 1;
  binaryMaker(len, arr, i + 1);

}

