/* Using strcpy() and strcmp() to sort strings */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

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
  char tempstring[LEN];
  for(k = 0; k < NUM; k++) {
    for(l = 0; l < NUM; l++) {
      int compare = strcmp(Strings[k], Strings[l]);
      if(compare > 0) {
        continue;
      } else if (compare == 0) {
          continue;
      } else if (compare < 0) {
          strcpy(tempstring, Strings[l]);
          strcpy(Strings[l], Strings[k]);
          strcpy(Strings[k], tempstring);
      }
    }
  }
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
  int m;
  for(m = 0; m < NUM; m++) {
    printf("%s", Strings[m]);
  }

}
