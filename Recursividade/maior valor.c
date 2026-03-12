
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheVetor(int vet[], int x){
	
	if (x == 0)
		return;
		
	preencheVetor(vet + 1 , x  - 1);
	vet[0] = 1 + rand()%100;
	
}

void printVet(int vet[], int x){
	
	if (x == 0)
		return;
		
	printVet(vet + 1 , x  - 1);
	printf("%d\n" , vet[0]); 
	
}

int valorMaior(int vet[] , int x){
	
	if (x == 1)
		return vet[0];
		
	if (vet[x-1] > valorMaior(vet, x -1)) {
		return vet[x-1];
	}
	
	return valorMaior(vet, x-1);
}

int main(){
	srand(time(NULL));
	int vet[10];
	preencheVetor(vet , 10);
	printVet(vet,10);
	printf(" Maior valor : %d" , valorMaior(vet,10));

}
