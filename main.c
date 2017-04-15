#include <stdlib.h>
#include <stdio.h>
#include "libresistance.h"


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

	printf("Den resulterande resistansen blir: %.0f\n", calc_resistance(count, conn, array));
}




