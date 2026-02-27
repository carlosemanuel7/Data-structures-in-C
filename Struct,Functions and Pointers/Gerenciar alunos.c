
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 100

typedef struct {

	int id;
	char nome[MAX];
	int idade;
	char curso[MAX];
	
}Aluno;

int interface(){
	
	int opt;
	printf("== MENU ==\n");
	printf("1 - Cadastrar aluno\n");
	printf("2 - Listar aluno\n");
	printf("3 - Excluir aluno\n");
	printf("4 - Chamada\n");
	printf("5 - Encerrar programa\n");
	scanf("%d" , &opt);
	system("clear");
	return opt;
}

void cadastrarAluno(Aluno a[] , int *cont , int *proxid){
	
	printf("Digite o nome: ");
	scanf(" %[^\n]" , a[*cont].nome);
	printf("Digite a idade: ");
	scanf("%d" , &a[*cont].idade);
	printf("Digite o curso: ");
	scanf(" %[^\n]" , a[*cont].curso);
	a[*cont].id = *proxid + 1;
	(*cont)++;
	(*proxid)++;

}

void listarAluno(Aluno a[] , int *cont){
	
	printf(" ID\t NOME\t CURSO\t IDADE\n");
	
	for (int i = 0; i < *cont; i++){
		
		printf(" %d\t %s\t %s\t %d" , a[i].id,a[i].nome,a[i].curso,a[i].idade);
		printf("\n");
		
	}
	
}

void excluirAluno(Aluno a[] , int *cont){
	
	int alvo;
	int flag = 0;
	printf("Qual id vc deseja excluir");
	scanf("%d" , &alvo);
	
	for (int i = 0; i < *cont; i++)
	{

		if (a[i].id == alvo)
		{
			flag = 1;
			
			for (int j = i; j < *cont - 1; j++){
				
				a[j] = a[j+1];
				
			}
			
		}
		
	}
	
	if (flag == 0)
	{
		printf("Aluno não encontrado\n");
		return;
	}
	else{
		
		(*cont)--;
		printf("Aluno excluido");
	}
}
void chamada(Aluno a[] , int *cont){
	
	Aluno aux;
	
	printf("Chamada");
	for (int i = 0; i < *cont; i++)
	{
		for (int j = 0; j < *cont - i - 1; j++)
		{
			if (strcmp(a[j].nome,a[j+1].nome)>0)
			{
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				
			}
		}
	}
	
	for (int i = 0; i < *cont; i++){
		
		printf("Nome: %s\n PRESENTE!!" , a[i].nome);
		printf("\n\n");
	}
	
}

int main(){
	
	Aluno a[MAX];
	int cont = 0;
	int proxid = 0;

	do{
		
		switch (interface())
		{
			case 1: cadastrarAluno(a,&cont,&proxid);
				break;
			
			case 2: listarAluno(a,&cont);
				break;
				
			case 3: excluirAluno(a,&cont);
				break;
				
			case 4: chamada(a,&cont);
				break;
				
			case 5: return 0;
		}
		
	} while (1);
}
