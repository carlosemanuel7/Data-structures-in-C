#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	int n = 0;
	
	printf("Digite a quantidade de artigos:");
	scanf("%d" , &n);
	
	int vet[n];
	
	printf("\n");
	
	for (int i = 0; i < n; i++)
			
		vet[i] = 1 + rand() % n;
	
	for (int i = 0; i < n - 1; i++){
		
		int troca;
		
		for (int j = i + 1 ; j < n; j++){
		
			if(vet[i] > vet[j]){ 
				troca = vet[i];
				vet[i] = vet[j];
				vet[j] = troca;
			}
			
		}
	}
	printf("Artigos Ordenados:\n");
	printf("\n");
	
	for (int i = 0; i < n; i++)
	
		printf("[%02d] ", vet[i]);
				
}
