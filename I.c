#include <stdio.h>
#include <string.h>

int main ()
{
  char *input=NULL;
  printf ("Enter a sentence: ");
  scanf("%ms", &input);
  //Is this legit?
  printf ("The sentence entered is %u characters long.\n",(unsigned)strlen(input));
  return 0;
}
