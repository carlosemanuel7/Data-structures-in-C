#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	
	char nome[100];
	int idade;
	
}Alunos;

int main(){
	
	Alunos a[5];
	Alunos temp;
	//Alunos temp2;
	
	for (int i = 0; i < 5; i++){
		
		printf("Digite seu nome : ");
		scanf(" %[^\n]" , a[i].nome);
	}
	printf("\n\n");
	
	for (int i = 0; i < 5; i++){
		
		printf("Digite sua idade : ");
		scanf("%d" , &a[i].idade );
	}

	//ordenando por nome
	for (int i = 0; i < 5; i++){
		
		for (int j = 0; j < 5 - i - 1; j++){
			
			if (strcmp(a[j].nome , a[j+1].nome) > 0){
				
				temp = a[j];
				a[j] = a[j+1];
				a[j+1]= temp;
				
			}
		}
		
	}
	//SÓ TEM COMO ORDENAR UMA COISA DA STRUCT POR VEZ
	
	/*ordenando por idade
	for (int i = 0; i < 5; i++){
		
		for (int j = 0; j < 5 - i - 1; j++){
			
			if (a[j].idade > a[j+1].idade){
				
				temp2 = a[j];
				a[j] = a[j+1];
				a[j+1] = temp2; 
			}
			
		}
	}
	*/
	
	/*for (int i = 0; i < 5; i++)
	{
		printf("%d" , a[i].idade);
	}
	*/
	
	for (int i  = 0; i < 5; i++)
	{
		printf("%s \n" , a[i].nome);
	}
}
