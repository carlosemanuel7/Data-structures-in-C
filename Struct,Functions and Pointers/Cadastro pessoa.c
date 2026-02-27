#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	
	char nome[100];
	int idade;
	float altura;
	
}Pessoa;

#define MAX 100

Pessoa cadastroPessoa(){
	
	Pessoa nova;
	printf("Digite seu nome");
	scanf("%s" , nova.nome);
	printf("Digite sua idade");
	scanf("%d" , &nova.idade);
	printf("Digite sua altura");
	scanf("%f" , &nova.altura);
	return nova;
	
}

void printPessoa(Pessoa p2[] , int cont2){
	
	for (int i = 0; i < cont2; i++){
		
		printf("Nome: %s\n", p2[i].nome);
		printf("Idade: %d\n", p2[i].idade);
		printf("Altura: %.2f\n", p2[i].altura);
	}
	
}

int interface(){
	
	int opt;
	printf("1 - Cadastrar Pessoa\n");
	printf("2 - Ordenar Pessoas\n");
	printf("3 - Listar Pessoas\n");
	scanf("%d",&opt);
	
	return opt;
}
	

Pessoa ordenarPessoas(int cont2 , Pessoa p2[]){
	
	Pessoa temp;
	
	for (int i = 0; i < cont2; i++){
	
		for (int j = 0; j < cont2 - i -1 ; j++){
			
			if(p2[j].idade > p2[j+1].idade){
				
				temp = p2[j];
				p2[j] = p2[j+1];
				p2[j+1] = temp;
			}
				
		}
		
	}
	for (int i = 0; i < cont2; i++){
		
		printf("Nome: %s\n", p2[i].nome);
		printf("Idade: %d\n", p2[i].idade);
		printf("Altura: %.2f\n", p2[i].altura);
	}
	printf("\n");
	return temp;
	
}


int main(){
	
	Pessoa p[MAX];
	int cont = 0; 

	
	do{
		switch(interface()){
			case 1: p[cont++] = cadastroPessoa(); //cadastra
					break;
			case 2: ordenarPessoas(cont , p); //ordena
					break;
			case 3: printPessoa(p , cont); //lista
					break;
		}
	}while(cont < 100);
	
}
	
