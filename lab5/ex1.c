#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define true 1
#define false 0

#define MAX 100

int maze[100][100];             // 100x100 is the maximum size needed
int wasHere[100][100];
int correctPath[100][100];
int width, height;
int startX, startY, endX, endY;

int recursiveSolve(int x, int y);

int main() {

  int x, y;
  scanf("%d%d", &width, &height);
  scanf("\n");    // This is needed to "eat" the newline after height,
                  // before the actual maze entries begin on the next line


  /* NOTE:  maze[y][x] will refer to the (x,y) element of the maze,
	   i.e., y-th row and x-th column in the maze.
     The row is typically the first index in a 2D array because
     reading and writing is done row-wise.  This is called
     "row-major" order.

     Also note that although we have declared the maze to be 100x100,
     that is the maximum size we need.  The actual entries in the
     maze will be height * width.
  */

  char tempchar;

  for(y=0; y < height; y++) {
    for(x=0; x < width; x++) {
      scanf("%c", &tempchar);
      maze[y][x]=tempchar;

      if(tempchar == 'S') {
        startX = x;
        startY = y;
      }
      if(tempchar == 'F') {
        endX = x;
        endY = y;
      }

      wasHere[y][x] = false;
      correctPath[y][x] = false;
    }
    scanf("%c", &tempchar);    // This is used to "eat" the newline
  }

  recursiveSolve(startX, startY);

  int a, b;
  for(a = 0; a < height; a++) {
    for(b = 0; b < width; b++) {
      if(a == startY && b == startX) {
        printf("S");
      }
      if(a == endY && b == endX) {
        printf("F");
      }
      if(correctPath[a][b] == true && maze[a][b] != 'S') {
        printf(".");
      }
      if(maze[a][b] == '*') {
        printf("*");
      }
      if(maze[a][b] == ' ' && correctPath[a][b] == false) {
        printf(" ");
      }
    }
    printf("\n");
  }

}


int recursiveSolve(int x, int y) {
  if(x == endX && y == endY) {
    return true;
  }
  if(maze[y][x] == '*' || wasHere[y][x] == true) {
    return false;
  }
  wasHere[y][x] = true;
  if(x != 0) {
    if(recursiveSolve(x - 1, y) == true) {
      correctPath[y][x] = true;
      return true;
    }
  }
  if(x != width - 1) {
    if(recursiveSolve(x + 1, y) == true) {
      correctPath[y][x] = true;
      return true;
    }
  }
  if(y != 0) {
    if(recursiveSolve(x, y - 1) == true) {
      correctPath[y][x] = true;
      return true;
    }
  }
  if(y != height - 1) {
    if(recursiveSolve(x, y + 1) == true) {
      correctPath[y][x] = true;
      return true;
    }
  }
  return false;
}
