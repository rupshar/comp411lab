/* Example: analysis of text */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
  char text[MAX], newtext[MAX], retreverse[MAX], reverse[MAX], comptext[MAX], compreverse[MAX], c;
  int i;
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

  int r = count - 2;
  for (j = 0; j < count; j++) {
    retreverse[j] = text[r];
    r--;
  }

  int l = 0;
  for (l = 0; l < length; l++) {
    newtext[l] = text[l];
  }

  int textcount = 0;
  for(int w = 0; newtext[w] != '\0'; w++) {
    if(isalpha(newtext[w])) {
      comptext[textcount] = tolower(newtext[w]);
      textcount++;
    }
  }

  int revcount = 0;
  for(int x = 0; reverse[x] != '\0'; x++) {
    if(isalpha(reverse[x])) {
      compreverse[revcount] = tolower(reverse[x]);
      revcount++;
    }
  }

  printf("Your input in reverse is:\n");
  printf("%s\n", retreverse);

  int equals = 0;
  int f;
  for(f = 0; f < strlen(comptext)-1; f++) {
   if(comptext[f] == compreverse[f]) {
      equals = 1;
    }
    else {
      equals = 0;
      break;
    }
  }

  if(equals == 1 || strlen(text) == 2 || strlen(text) == 1)
  {
    printf("Found a palindrome!\n");
  }
}
