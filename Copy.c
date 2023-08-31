#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  printf("Enter the original string: ");
  gets(str1);
  char str2[100];
  strcpy(str2, str1);
  printf("The original string is: %s\n", str1);
  printf("The copied string is: %s\n", str2);

  return 0;
}
