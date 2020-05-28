#include <stdio.h>
#include <string.h>

int main() {
  int kata;
  char karakter[17];
  printf("Enter any string : ");
  gets(karakter);
  while (karakter == 0x0A)
  {
    printf("Enter any string again : ");
    gets(karakter);

  }

  kata = atoi(karakter);
  printf("Output : %d", kata);
  return(0);
}
