/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */


int my_compare_strings(char string1[], char string2[]) {

  /* Write code here to compare string1 and string2, character by character.
     WITHOUT USING ANY C STRING LIBRARY FUNCTIONS.

     The max length of the strings is LEN, though they may be shorter so look
     for the string terminators.

     This function should return:
      -1 if string1 comes before string2 in alphabetical order
       0 if string1 is the same as string2
      +1 if string1 comes after string2 in alphabetical order

      Here, alphabetical order is defined simply by the numerical value
      of the characters in the string, from left to right.  See the writeup
      for more details.
  */

  int i;
  for(i = 0; i < LEN; i++) {
    if(string1[i] > string2[i]) {
      return -1;
    }
    else if(string1[i] < string2[i]) {
      return 1;
    }
  }
  return 0;
}


void my_swap_strings(char string1[], char string2[]) {
  char temp;    // char variable used in swapping one character at a time

  /* string1 assumed to be the string that is ahead in alphabetical order, so we swap
     string2's contents with string1. */

  int i;
  for(i = 0; i < LEN; i++) {
    temp = string2[i];
    string2[i] = string1[i];
    string1[i] = temp;
  }

  /* Write code here to swap the contents of string1 and string2, one
     character at a time, WITHOUT USING ANY C STRING LIBRARY FUNCTIONS. 

     The max length of the strings is LEN, though they may be shorter, so look
     for the string terminators.
  */
}


int main()
{
  char Strings[NUM][LEN];

  printf("Please enter %d strings, one per line:\n", NUM);

  int i;
  for(i = 0; i < NUM; i++) {
    fgets(Strings[i], LEN, stdin);
  }

  puts("\nHere are the strings in the order you entered:");

  int j;
  for(j = 0; j < NUM; j++) {
    printf("%s", Strings[j]);
  }
  
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Use the function my_compare_strings() to compare two strings.  If they are out of order,
     use the function my_swap_strings() to swap their contents.

  */

  int k, l;
  for(k = 0; k < NUM; k++) {
    for(l = 0; l < NUM; l++) {
      int comp = my_compare_strings(Strings[k], Strings[l]);
      if(comp == 1) {
        continue;
      } else if(comp == 0) {
          continue;
      } else if(comp == -1) {
          my_swap_strings(Strings[k], Strings[l]);
      }
    }
  }
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
  int m;
  for(m = NUM - 1; m >= 0; m--) {
    printf("%s", Strings[m]);
  }

}
