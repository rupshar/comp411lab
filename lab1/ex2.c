/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float r, a, diameter, circumference;

  printf("Enter radius (in cm):\n");
  scanf("%f", &r);

  float newRadius = r / 2.54;
  diameter = newRadius * 2;
  circumference = PI * diameter;
  a = PI * newRadius * newRadius;

  printf("Circle's area is %3.2f (sq in).\n", a);
  printf("Its circumference is %3.2f (in).\n", circumference);
}
