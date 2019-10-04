#include <stdio.h>
#include <string.h>

int main() {

  int a, b, c, d, e, f;
  printf("Enter six integers:\n");
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

  printf("1234567890bb1234567890\n");
  printf("%*d", 10, a);
  printf("  %*d\n", 10, b);
  printf("%*d", 10, c);
  printf("  %*d\n", 10, d);
  printf("%*d", 10, e);
  printf("  %*d\n", 10, f);
}
