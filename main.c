#include <stdlib.h>
#include <stdio.h>
#include "calc.h"


int main ()
{
	int count; 
	char conn;
	float resultat;

	printf("Ange koppling [S | P]: ");		
 	scanf( " %c", &conn);
									
	printf("Antal komponenter: ");
	scanf( "%d", &count);

	float array[count];

	resultat = calc_resistance(count, conn, array);

	printf("Den resulterande resistansen blir: %.0f\n", resultat);

	return 0;
}




