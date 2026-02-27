#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int contarVogal(char vet[] , int cont){
	
	for (int i = 0 ; vet[i] != '\0'; i++){
		
		if (vet[i] == 'a' || vet[i] == 'e' || vet[i] == 'i' ||  vet[i] == 'o' || vet[i] == 'u' ){
			
			cont++;
				
		}
		
	}
	
	printf("Esse é o total de vogais presentes na frase: %d" , cont);
	return cont;
}

int main(){
	
	int cont = 0;
	char vet[100];
	
	scanf(" %[^\n]s" , vet); 
	
	contarVogal(vet , cont);

	
}
