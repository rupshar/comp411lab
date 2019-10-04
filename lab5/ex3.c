#include <stdio.h>
#include <string.h>

char animals[20][15];
char lyrics[20][60];
int  number;

void nurseryrhyme(int current) {
                                                // print "current" number of spaces

                                                // print something before the recursive call
  if(current == 0) {
    printf("There was an old lady who swallowed a %s;\n", animals[0]);
  } else {
      printf("%*s", current, "");
      printf("She swallowed the %s to catch the %s;\n", animals[current-1], animals[current]);
  }    
                                                //   if so, print "There was an old lady..."
                                                //   or if it is > 0, print "She swallowed ..."

  if(current < number-1)                        // if we are not at the last animal, make the recursive call
    nurseryrhyme(current+1);

  printf("%*s", current, "");                                             // print something after the recursive call
  printf("I don't know why she swallowed a %s - %s", animals[current], lyrics[current]);

}


int main() {
  int i=0;

  while (1) {

    fgets(animals[i], 15, stdin);

    if (strcmp(animals[i], "END\n") == 0)       // if it is "END\n", we are done reading
      break;

    int length = strlen(animals[i]);

    animals[i][length-1] = '\0';

    fgets(lyrics[i], 60, stdin);
    i++;
  }

  number = i;

  nurseryrhyme(0);
}
