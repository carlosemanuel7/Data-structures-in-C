#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){  
	
	srand(time(NULL)); 
	int vet[31];
	int cont = 0 , cont2 = 0;
	int media = 0;
	
	for (int i = 1; i <= 30; i++)
	{
		vet[i] = 12 + rand()%(80 - 12 + 1) ;
		cont += vet[i];
	    
	    if (vet[i] > 50)
	    {
			printf("dia [%d]: %dº  ALTA UMIDADE\n" ,i , vet[i]);
			
			
		}
		if (vet[i] < 50)
	    { 
			printf("dia [%d]: %dº  BAIXA UMIDADE\n" ,i , vet[i]);
			
		}
		
    }
    
        media = cont/30;
        
        for (int i = 0; i < 30; i++)
		{
			if(vet[i] > media) 
				cont2++;
		}
       
        printf("Essa é a média mensal: %dº\n" , media);
        printf("Essa é a quantidade de dias acima da média: %d" , cont2);
    
   

}
