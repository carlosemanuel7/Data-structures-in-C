#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Um apostador joga um dado para o ar N vezes (N definido pelo usuário). Sabendo que um
dado possui 6 faces, faça um programa que simula o experimento. Como resultado,
imprima quantas vezes que cada face (não quais faces) caiu para cima e o % de cada face.*/


int main(){
	
	srand(time(NULL));
    
    int vezes = 0 , num = 0;
    int lado[7];

    
    printf("Quantas vezes deseja jogar o dado?"); 
    scanf("%d" , &vezes); 
    
    for (int i = 0; i < vezes; i++){
			
	    num = 1 + rand()%6;
         
			if(num == 1) 
				lado[0]++;
            
            if(num == 2) 
				lado[1]++;
            
            if(num == 3) 
				lado[2]++;
            
            if(num == 4) 
				lado[3]++;
            
            if(num == 5) 
				lado[4]++;
            
            if(num == 6) 
				lado[5]++;
            

	}
	
	for (int i  = 0; i < 6 ; i++){
		
		printf("o lado %d caiu : %d vezes , %.2f\n" , i+1 , lado[i] ,(float) ((lado[i] * 100) / vezes ));
		
	}
	
	
}
