
#include <stdio.h>
#include <stdlib.h>

void preencheVetor(int vet[], int x){
	
	if (x == 0)
		return;
		
	preencheVetor(vet + 1 , x  - 1);
	vet[0] = 1 + rand()%10;
	
}

void printVet(int vet[], int x){
	
	if (x == 0)
		return;
		
	printVet(vet + 1 , x  - 1);
	printf("%d\n" , vet[0]); 
	
}

int soma(int vet[] , int x){
	
	if (x == 1)
		return vet[0];
		
	return vet[0] += soma(vet + 1, x - 1);
		
}

int main(){
	
	int vet[10];
	preencheVetor(vet , 10);
	printVet(vet,10);
	printf("%d" , soma(vet,10));

}
