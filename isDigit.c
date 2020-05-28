#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    c='59';
    printf("Result when numeric character is passed: %d", isdigit(c));

    c='\0';
    printf("\nResult when non-numeric character is passed: %d", isdigit(c));

    return 0;
}
