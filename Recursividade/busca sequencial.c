
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

int buscaSeq(int vet[] , int x , int alvo){
	
	
	if (vet[0] == alvo)
		return alvo;
	
	else
		return vet[0] = buscaSeq(vet + 1 , x - 1 , alvo);
	
	if (!vet)
		return 1;
		
}


int main(){
	
	srand(time(NULL));
	int vet[10];
	preencheVetor(vet , 10);
	printVet(vet,10);
	int alvo;
	printf("Digite qual valor vc quer procurar: ");
	scanf("%d" , &alvo);
	buscaSeq(vet , 10 , alvo);
	printf("%d" , buscaSeq(vet,10,alvo));
	
}
