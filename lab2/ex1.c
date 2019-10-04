#include <stdio.h>
#include <string.h>

int main()
{
  int i;

  printf("Enter a number from 1 to 20:\n");
  scanf("%d", &i);

  if (i > 20)
  {
    printf("Number is not in the range from 1 to 20\n");
  }
  else if (i < 1)
  {
    printf("Number is not in the range from 1 to 20\n");
  }
  else
  {
    printf("Here are the first ");
    char message[90];
    sprintf(message, "%d", i);
    strcat(message, " ordinal numbers:");
    printf("%s\n", message);
    int j;
    for(j=1; j<=i; j++) {
      if(j == 1)
      {
        printf("1st\n");
      }
      else if(j == 2)
      {
        printf("2nd\n");
      }
      else if(j == 3)
      {
        printf("3rd\n");
      }
      else
      {
        char str[5];
        sprintf(str, "%d", j);
        strcat(str, "th");
        printf("%s\n", str);
      }
    }
  }
}


