#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE (1)
#define FALSE (0)
#define NUM0 (0)
#define NUM1 (1)
#define NUM2 (2)
#define LIMIT_INDEX (19)

/*****int get_input (int count)****
* Garis besar: Ketentuan inputan                *
* Penjelasan: mengecek inputan dari user        *
* Parameter: int count                          *
* Nilai balik: int mymessage                    *
****************/
double get_input(int count)
{
	char *input={'\0'};

	int str_count = 0;

	double mymessage = 0;
	int inputan = FALSE;
	int titik =FALSE;
	int minus = FALSE;
	int angka = FALSE;
	input = malloc (sizeof (int) * LIMIT_INDEX); /*alokasi memori untuk hensu input*/

	while ( inputan == FALSE)/* untuk pengulangan pertanyaan.. jika input benar maka while selesai */
	{
		fflush(stdin);
		memset(input,0, sizeof(input));	/*set memory hensu input ke 0 */
		printf("%d. Input  :",count);/* membaca inputan maks 50 char*/
		scanf("%19[^\n]%*c",input);

		str_count = strlen(input);/* menghitung panjang input */

		mymessage = atof(input);

		if ( str_count > 0)
		{
			titik = fg_cektitik(input,str_count);
			minus = fg_cekminus	(input,str_count);
			angka = fg_cekangka(input,str_count);

			if ( (LIMIT_INDEX-2) < str_count) /*panjang input di atas 11 character 19-2<17 */
			{
				printf("Maksimal 17LF Angka Inputan !\n");
				inputan = FALSE;
			}
			else if ((mymessage < INT_MIN)||(mymessage > INT_MAX))
						{
				printf("Inputan over Min %i Max %i!\n",INT_MIN, INT_MAX);
				inputan = FALSE;
			}
			else if ((titik == TRUE)&&(minus == TRUE)&&(angka==TRUE))
			{
				printf("Inputan Correct ! \n");

				inputan = TRUE;
			}
			else
			{
				printf("Inputan Salah \n");/*menampilkan pesan error */
			}
		}
		else
		{
			printf("Tidak Boleh kosong \n");/*menampilkan pesan error */
		}
	}

	return mymessage ;
}

/*int fg_cekangka (char *chk_input, int panjang_input)*
* Garis besar: Ketentuan inputan                            *
* Penjelasan: mengecek inputan dari user                    *
* Parameter: int count                                      *
* Nilai balik: int result                                   *
********************/

int fg_cekangka (char *chk_input, int panjang_input)
{
	int count =0;
	int i = 0;
	int result = FALSE;

	for (i=0 ; i<panjang_input ; i++)
	{
		if (isdigit(chk_input[i])!= NUM0)
		{
			result=TRUE;
		}
		else
		{
			if( ( chk_input[i]=='-') || (chk_input[i]=='.') )
			{
				result=TRUE;
			}
			else
			{
				result=FALSE;
				i=panjang_input;
			}
		}
	}
	return result;
}

/*int fg_cektitik (char *chk_input, int panjang_input)*
* Garis besar: Ketentuan inputan                            *
* Penjelasan: mengecek inputan dari user                    *
* Parameter: int count                                      *
* Nilai balik: int result                                   *
********************/

int fg_cektitik (char *chk_input, int panjang_input)
{
	int count =0;
	int i = 0;
	int result = FALSE;

	for (i=0 ; i<panjang_input ; i++)
	{
		if (chk_input[i]=='.')
		{
			count++;
		}
	}
	if (count<=1)
	{
		if(panjang_input!=1)
		{
			result=TRUE;
		}

	}

	return result;
}

/*int fg_cekminus (char *chk_input, int panjang_input)*
* Garis besar: Ketentuan inputan                            *
* Penjelasan: mengecek inputan dari user                    *
* Parameter: int count                                      *
* Nilai balik: int result                                   *
********************/

int fg_cekminus (char *chk_input, int panjang_input)
{
	int count =0;
	int i = 0;
	int result = FALSE;

	for (i=0 ; i<panjang_input ; i++)
	{
		if (chk_input[i] == '-')
		{
			count++;
		}
	}
	if (( count ==0 ) || (( chk_input[0]=='-') && (count ==1)))
	{
		result=TRUE;
	}

	return result;
}
/******int main fungtion (void)********
* Garis besar: kansu utama                                  *
* Penjelasan: nilai operasi                                 *
* Parameter:                                                *
* Nilai balik:                                              *
********************/

int main (void)
{
	double  message1 = 0;
	double  message2 = 0;

	printf("[[Program untuk memunculkan nilai operasi aritmatika, OR, AND]]\n");
	printf("Masukkan %d bilangan  (%d ~ %d):\n", NUM2, INT_MIN, INT_MAX);
	printf("Masukkan 17 digit bilangan koma misal (1.345678901234567)\n");
	message1 = get_input(NUM1);
	message2 = get_input(NUM2);

	fg_calcINT(message1,message2);
	fg_calcFLOAT(message1,message2);
	fg_calcDouble(message1,message2);

    getch();
	return 0;
}

fg_calcINT (double message1, double message2)
{
	printf ("\nHasil INT: \n");
	printf ("INT (Penjumlahan):%i + %i = %i \n",(int)message1,(int)message2,(int)message1+(int)message2);
	printf ("INT (Pengurangan):%i - %i = %i \n",(int)message1,(int)message2,(int)message1-(int)message2);
	printf ("INT (Perkalian):%i * %i = %i \n",(int)message1,(int)message2,(int)message1*(int)message2);
	if ((int)message2 == 0)
	{
		printf ("INT (Pembagian):%i / %i = Tidak Terhingga \n",(int)message1,(int)message2);
	}
	else
	{
		printf ("INT (Pembagian):%i / %i = %i \n",(int)message1,(int)message2,(int)message1/(int)message2);
	}

	printf ("INT (Bitor):%i or %i = %i \n",(int)message1,(int)message2,(int)message1|(int)message2);
	printf ("INT (Bitand):%i &and %i = %i \n",(int)message1,(int)message2,(int)message1&(int)message2);

	return 0;
}

fg_calcFLOAT (double message1, double message2)
{
	printf ("\nHasil Float: \n");
	printf ("Float (Penjumlahan):%f + %f = %f \n",(float)message1,(float)message2,(float)message1+(float)message2);
	printf ("Float (Pengurangan):%f - %f = %f \n",(float)message1,(float)message2,(float)message1-(float)message2);
	printf ("Float (Perkalian):%f * %f = %f \n",(float)message1,(float)message2,(float)message1*(float)message2);
	if ((int)message2 == 0)
	{
		printf ("Float (Pembagian):%f / %f = Tidak Terhingga \n",(float)message1,(float)message2);
	}
	else
	{
		printf ("Float (Pembagian):%f / %f = %f \n",(float)message1,(float)message2,(float)message1/(float)message2);
	}

	return 0;
}
fg_calcDouble (double message1, double message2)
{
	printf ("\nHasil Double: \n");
	printf ("Double (Penjumlahan):%0.15lf + %0.15lf = %0.15lf \n",message1,message2,message1+message2);
	printf ("Double (Pengurangan):%0.15lf - %0.15lf = %0.15lf \n",message1,message2,message1-message2);
	printf ("Double (Perkalian):%0.15lf * %0.15lf = %0.15lf \n",message1,message2,message1*message2);
	if ((int)message2 == 0)
	{
		printf ("Double (Pembagian):%0.15lf / %0.15lf = Tidak Terhingga \n",message1,message2);
	}
	else
	{
		printf ("Double (Pembagian):%0.15lf / %0.15lf = %0.15lf \n",message1,message2,message1/message2);
	}

	return 0;
}
