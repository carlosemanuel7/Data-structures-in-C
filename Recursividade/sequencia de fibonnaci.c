#include <stdio.h>
#include <stdlib.h>

int iniciarVet(int tam , long long int vet[]){
	
	if (!tam)
		return 0;
	else
		return vet[0] = iniciarVet(tam - 1 ,vet + 1);
}

long long fib_din(int tam ,  long long int vet[]){

	if (tam<=2) 
		return 1;
	if (vet[tam] !=0)
		return vet[tam];
	else{
		vet[tam] =  fib_din(tam - 1, vet) + fib_din (tam-2,vet);
		return vet[tam];
	}
}

long long int fib_rec(long long int tam){
	
	if (tam <= 2)
		return 1;
	
	else
		return fib_rec(tam - 1) + fib_rec(tam - 2 );
	
}

int main(){
	
	int tam = 0;
	printf("Digite qual número vc quer saber da série FIBONNACI: ");
	scanf("%d" , &tam);
	long long int vet[tam];
	iniciarVet(tam,vet);
	printf("Fibonnaci recursivo e dinâmico : %lld\n" , fib_din(tam - 1 , vet));
	printf("Fibonnaci recursivo : %lld\n" , fib_rec(tam - 1));
	
}
