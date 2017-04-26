#include <stdio.h>
#include "libpower.h"
#include "libresistance.h"
#include "libcomponent.h"

int main()
{
	float i, r, v, resistans; 
	int count; 
	char conn;
	float e_res_array[3];

	printf("Ange spänningskälla i V: ");
	scanf(" %f", &v);

	printf("Ange koppling [S | P]: ");		
 	scanf( " %c", &conn);
									
	printf("Antal komponenter: ");
	scanf( "%d", &count);

	float res_array[count];

	resistans = calc_resistance(count, conn, res_array);
	
	printf("Ersättningsresistans: %.0f\n", resistans);
	
	printf("Effekt: %.2f\n", calc_power_r(v,resistans));	

	int nr_in_res_array = e_resistance(resistans, res_array);

	printf("Ersättningsresistanser i E12-serien kopplade i serie: \n");
  	for (int i = 0 ; i < nr_in_res_array; i++)
	{
   	printf("%.0f ", res_array[i]);
   	printf("\n");
  	}
}
