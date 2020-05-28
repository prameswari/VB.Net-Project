#include <stdio.h>  /*library untuk kegiatan in-out*/
#include <stdlib.h> /*library untuk melakukan berbagai operasi*/
#include <conio.h>  /*header*/
#include <string.h> /*library untuk memanipulasi beberapa jenis string*/

#define MAX_LIMIT (100) /*menampung nilai index variabel string*/
#define MIN_CONVERSION (1) /*menampung nilai minimum limit konversi*/

int main ()
{
	/*munculkan nomor biner dari inputan bilang desimal dengan fungsi scanf, Saat tidak ada inputan, muncul error dan memungkinkan dapat diinput sekali lagi*/
	int desimal, n;
	printf("Masukkan bilangan desimal : \n");
	n = scan("%[^\n]d", &desimal);
	while(n == 0)
	{
		printf("ERROR. Masukkan bilangan desimal ! \n");
		fflush(stdin);
	}

	//scanf("%d", &desimal);
	printf("Bilangan biner nya adalah ");
	biner(desimal);
	return 0;
}

int biner(int desimal)
{
	if(desimal>=1)
	{
		biner(desimal/2);
	}
	printf("%d", desimal%2);
}
