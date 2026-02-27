#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{ 
	
	char nome[100];
	int idade;
	float nota1;
	float nota2;
	
}Aluno;

int interface(){
	
	int opt;
	
	printf("\n");
	printf("[CADASTRO DE ALUNOS]\n");
	printf("1 - Cadastrar aluno\n");
	printf("2 - Listar alunos\n");
	printf("3 - Mostrar médias\n");
	printf("4 - Ordenar por idade\n");
	printf("5 - Sair\n");
	scanf("%d" , &opt);
	return opt;
}

void cadastroAluno(Aluno a[] , int *cont){
		
	do{
		
	printf("Digite seu nome: ");
	scanf(" %[^\n]s" ,a[*cont].nome);
	printf("Digite sua idade: ");
	scanf("%d" ,&a[*cont].idade);
	
	if (a[*cont].idade > 120 || a[*cont].idade < 0){
		
		printf("Idade inválida , tente novamente ");
		break;
	}
	
	printf("Digite sua primeira nota: ");
	scanf("%f" ,&a[*cont].nota1);
	
	if (a[*cont].nota1 > 10 || a[*cont].nota1 < 0){
		
		printf("Nota inválida , tente novamente");
		break;
		
	}
	printf("Digite sua segunda nota: ");
	scanf("%f" ,&a[*cont].nota2);
	
	if (a[*cont].nota2 > 10 || a[*cont].nota2 < 0){
		
		printf("Nota inválida , tente novamente");
		break;
		
	}
	
	printf("\n");
	(*cont)++;
	
	} while (*cont < 1 );
	
	system("clear");
	
}

void listarAluno(Aluno a[] , int *cont){

		for (int i = 0; i < *cont; i++)
		{
			printf("Nome: %s \n" , a[i].nome);
			printf("Idade: %d \n" , a[i].idade);
			printf("Nota 1 %.2f \n" , a[i].nota1);
			printf("Nota 2: %.2f \n" , a[i].nota2);
			
		}
		printf("\n\n");
	
	
}

void ordenarIdade(Aluno a[] , int *cont){
	
	Aluno temp;
	
	for (int i = 0; i < *cont; i++){
		
		for (int j  = 0; j < *cont - i - 1; j++){
			
			if (a[j].idade > a[j+1].idade){
				
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				
				
			}
			
		}
		
	}
	
	printf("Alunos ordenados por idade:\n");
	
	for (int i = 0; i < *cont; i++){
		
		printf("Nome: %s \n" , a[i].nome);
		printf("Idade: %d \n" , a[i].idade);
		printf("Nota 1 %.2f \n" , a[i].nota1);
		printf("Nota 2: %.2f \n" , a[i].nota2);
		
	}
	printf("\n\n");
	
}

void mostrarMedias(Aluno a[] , int *cont){
	
	float media;
	
	for (int i = 0; i < *cont; i++)
	{
		media = (a[i].nota1 + a[i].nota2) / 2;
		printf("A média do aluno %s foi: %.2f \n" , a[i].nome , media); 
	}
	printf("\n\n");
		
}

int main() {
	
	int opt = 0;
	int cont = 0;
	Aluno a[50];
	
	do{
		
		opt = interface();
		
		if (opt == 1){
			
			cadastroAluno(a , &cont);
		}
		
		if (opt == 2){
			
			listarAluno(a , &cont);
		}
		
		if (opt == 3){
			
			mostrarMedias(a , &cont);
		}
		
		if (opt == 4){
			
			ordenarIdade(a , &cont);
		}
		
		if (opt == 5){
			
			break;
		}
		if (opt > 5 || opt < 1){
			
			printf("opção inválida\n");
			interface();
		}
		
	} while (cont != 50);
	
	
}
	
