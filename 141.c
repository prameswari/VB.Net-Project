#include <stdio.h>

void f_error(char a[7])
{
    int vbl = 1;

    awal :
    printf("Masukkan bilangan yang ingin diubah :\n");

    while(vbl)
    {
        scanf ("%[^\n]", a) < 1;

        if(!isdigit(a)
        {
            printf("ERROR!\n\n");
            fflush(stdin);
            goto awal;
        }
        else
        {
            vbl = 0;
        }
    }
    return;
}

int main()
{
    char chara[1];
    int bin;

    printf("PROGRAM KONVERSI BINER \n\n");

    f_error(chara);
    bin = atoi(chara);

    printf("\nHasil konversinya adalah\n");
    fg_biner(bin);

    getch();
    return 0;
}

void fg_biner(int bin)
{
    if(bin > 1)
    {
        fg_biner(bin/2);
    }
    printf("%d", bin%2);
}
