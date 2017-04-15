#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"

float calc_resistance(int count, char conn, float *array)
{
	float resultat = 0;
	int i, j, nr;

	array = malloc (count+1);
 	if (array==NULL) 
		exit (1);
		
	if (conn == 'S') 
	{                 
   		for (i=0; i<count; i++)
		{
			nr = (i+1);					 
			printf( "Komponent %d i ohm: ",nr);  
 			scanf( "%f", &array[i]);   
			resultat = (resultat+array[i]);
		}		
		resultat = resultat;				
	}		
   	
	else if (conn == 'P')
	{                 
      		for (i=0; i<count; i++)
		{
			nr = (i+1);					 
			printf( "Komponent %d i ohm: ",nr);  
    			scanf( "%f", &array[i]);   
			resultat = (resultat + (1.0 / array[i]));	
		}
		resultat = (1 / resultat);	

		for (j=0; j<count; j++)
		{		
			if (array[j] == 0)
			{				
			resultat = 0;				
			}
		}
	}
	
	else
	{				
			resultat = -1;				
	}	
	free (array);
	return resultat;
}

