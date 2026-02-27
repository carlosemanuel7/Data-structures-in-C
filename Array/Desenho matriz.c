
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	int n = 0 , x = 0 ; 
	
	printf("Digite o valor de X:");
	scanf("%d" , &x);
	
	printf("Digite o valor de N:");
	scanf("%d" , &n);
	
	int vet[n];
	
	
	for (int i = 0; i < n; i++){
		
		
		for (int j = 0; j < n; j++){
			
			vet[j] = 1 + rand()%x;
			printf(" %d " , vet[j]);
			
		}
		
		printf(" \n");
	}
	
}
