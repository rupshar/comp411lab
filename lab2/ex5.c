#include <stdio.h>
#include <string.h>

int main() {

  int width, height;
  do {
    printf("Please enter width and height:\n");
    scanf("%d", &width);

    if (width == 0) {
      break;
    }

    scanf("%d", &height);

    int i, j;
    for(i = 1; i <= height; i++) {
      for(j = 1; j <= width; j++) {
        if(i == 1 || i == height){
          if(j == 1 || j == width) {
            printf("+");
          }
          else if(j > 1 && j < width) {
            printf("-");
          }
        }
        else if(i > 1 && i < height) {
          if(j == 1 || j == width) {
            printf("|");
          }
          else if(j > 1 && j < width) {
            printf("~");
          }
        }
      }
      printf("\n");
    }

  } while (width != 0);

  printf("End\n");

}
