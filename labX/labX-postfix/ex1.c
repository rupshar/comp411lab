#include <stdlib.h>
#include <stdio.h>

#define MAX 16
#define TOP 0

int stack[MAX];
int top = 0;

void empty() {
  top = 0;
}

void push(int a) {
  stack[top] = a;
  top++;
}

int pop() {
  top--;
  return stack[top];
}

int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return a / b;
}

int main() {
  char i;
  char expression[64];
  int stack[MAX];
  int top = 0;

  int j = 0;

  fgets(expression, 64, stdin);

  while(expression[0] != '0' && expression[1] != '\n') {
    if(expression[0] == '0' && expression[1] == '\n') {
      break;
    }

    for(int k = 0; k < 64; k++) {

      if(expression[k] == '\n') {
        break;
      }

      if(expression[k] == '0') {
        push(0);
      } else if (expression[k] == '1') {
          push(1);
      } else if (expression[k] == '2') {
          push(2);
      } else if (expression[k] == '3') {
          push(3);
      } else if (expression[k] == '4') {
          push(4);
      } else if (expression[k] == '5') {
          push(5);
      } else if (expression[k] == '6') {
          push(6);
      } else if (expression[k] == '7') {
          push(7);
      } else if (expression[k] == '8') {
          push(8);
      } else if (expression[k] == '9') {
          push(9);
      }

      if(expression[k] == '+') {
        push(add(pop(), pop()));
      }

      if(expression[k] == '-') {
        push(subtract(pop(), pop()));
      }

      if(expression[k] == '*') {
        push(multiply(pop(), pop()));
      }

      if(expression[k] == '/') {
        push(divide(pop(), pop()));
      }


    }

    printf("%d\n", pop());

    empty();

    fgets(expression, 64, stdin);

  }

}

