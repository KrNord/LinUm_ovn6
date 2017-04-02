#include <stdio.h>
#include "calc.h"

float calc_resistance(int count, char conn, float *array)
{
	float varde;
	float resultat = 0;
	int i, j, nr;
		
	if (conn == 'P') 
	{                 
   		for (i=0; i<count; i++)
		{
			nr = (i+1);					 
			printf( "Komponent %d i ohm: ",nr);  
 			scanf( "%f", &varde );   
			array[i] = varde;
			resultat = (resultat+array[i]);
		}		
		resultat = resultat;
		return resultat;		
	}		
   	
	else if (conn == 'S')
	{                 
      		for (i=0; i<count; i++)
		{
			nr = (i+1);					 
			printf( "Komponent %d i ohm: ",nr);  
    			scanf( "%f", &varde );   
			array[i] = varde;
			resultat = (resultat + (1.0 / array[i]));
		}

		for (j=0; j<count; j++)
		{
			if (array[j] == 0)
			{
				resultat = 0;
				j = count;
			}
			else
			{
				resultat = (1.0 / resultat);
			}
		}		
		return resultat;	
	}
}



