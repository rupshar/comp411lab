/* Example: analysis of text */

#include <stdio.h>
#include <string.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
  char text[MAX], newtext[MAX], reverse[MAX], c;
  int i;
  int lowercase, uppercase, digits, other;
  int length;
  
  puts("Type some text (then ENTER):");
  
  /* Save typed characters in text[]: */

  fgets(text, MAX, stdin);

  length = strlen(text) - 1;

  int j, k, count = 0;
  while (text[count] != '\0')
  {
    count++;
  }

  k = count - 2;
  for (j = 0; j < count; j++) {
    reverse[j] = text[k];
    k--;
  }

  printf("Your input in reverse is:\n");
  printf("%s\n", reverse);

  int equals = 0;
  int m;
  for(m = 0; m < length; m++) {
    if(text[m] == reverse[m]) {
      equals = 1;
    }
    else {
      equals = 0;
      break;
    }
  }

  if(equals == 1)
  {
    printf("Found a palindrome!\n");
  } 
}
