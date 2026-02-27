#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
	
	int id;
	char nome[MAX];
	char descricao[MAX];
	char responsavel[MAX];
	int status;
	int flag;
	
}Tarefa;

FILE* abrirArquivo(char nome_arq[]){
	
	FILE *arquivo = fopen(nome_arq, "rb+");
	
	if (!arquivo)
	{
		arquivo = fopen(nome_arq, "wb+");
	}
	return arquivo;
}
int interface(){
	
	int opt;
	printf("== TO - DO - LIST ==\n");
	printf("1 - Nova Tarefa\n");
	printf("2 - Listar Tarefas\n");
	printf("3 - Editar Tarefa\n");
	printf("4 - Excluir Tarefa\n");
	printf("5 - Ordenar\n");
	scanf("%d" , &opt);
	system("clear");
	return opt;
}

void novaTarefa(FILE *arquivo){
	
	Tarefa t;
	//int proxid = 1;
	int fazer;
	printf("Digite o nome da tarefa: ");
	scanf(" %[^\n]" , t.nome);
	printf("Digite a descrição da tarefa: ");
	scanf(" %[^\n]" , t.descricao);
	printf("Digite o nome do responsavel pela tarefa: ");
	scanf(" %[^\n]" , t.responsavel);
	printf("Essa tarefa está pendente ou já foi concluida?\n");
	printf("1 - Concluida\n");
	printf("2 - Pendente\n");
	scanf("%d" , &fazer);
	if (fazer == 1)
	{
		t.status = 1;
	}
	else{
		t.status = 0;
	}
	t.flag = 1;
	
	fseek(arquivo,0,SEEK_END);
	fwrite(&t,sizeof(Tarefa),1,arquivo);
	system("clear");
}	

void ordenarTudo(FILE *arquivo){
	
	fseek(arquivo,0,SEEK_END);
	int p = ftell(arquivo) / sizeof(Tarefa);
	fseek(arquivo,0,SEEK_SET);
	Tarefa aux;
	Tarefa lista[p];
	
	fread(lista,p * sizeof(Tarefa),1,arquivo);
	
	for (int i= 0; i < p; i++){
		
		for (int j = 0; j < p - i - 1; j++){
			
			if (lista[j].status > lista[j+1].status)
			{
				aux = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = aux;
			}
		}
	}
	
	fseek(arquivo,0,SEEK_SET);
	fwrite(lista,p * sizeof(Tarefa),1,arquivo);
	fflush(arquivo);
	
}

void listarTarefa(FILE *arquivo){
	
	Tarefa t;
	ordenarTudo(arquivo);
	fseek(arquivo,0,SEEK_SET);
	while(fread(&t , sizeof(Tarefa),1,arquivo)==1){
		
		if (t.flag == 1){
			
			printf("== TAREFAS ==\n");
			//printf("ID: %d\n");
			printf("Tarefa: %s \n" , t.nome);
			printf("Descrição: %s\n" , t.descricao);
			printf("Responsavel: %s\n" , t.responsavel);
			
			if (t.status == 1)
			{
				printf("Status: Concluida\n\n");
				
			}
			else
				printf("Status: Pendente\n\n");
		}	
	}
	
}


void editarTarefa(FILE *arquivo){

	char edit[MAX];
	Tarefa t;
	int editar;
	fseek(arquivo,0,SEEK_SET);
	
	printf("Digite o nome da tarefa que vc quer editar:"); 
	scanf(" %[^\n]" , edit);
	
	while (fread(&t , sizeof(Tarefa),1,arquivo))
	{
		if (strcmp(edit,t.nome)==0)
		{
			printf("Qual dado vc deseja editar:\n");
			printf("1 - Nome\n");
			printf("2 - Descrição\n");
			printf("3 - Responsavel\n");
			printf("4 - Status \n");
			scanf("%d" , &editar);
			
		}
		
		if (editar == 1){
			
		
			printf("Digite o novo nome:");
			scanf(" %[^\n]" , t.nome );
			printf("Nome editado\n");
			fseek(arquivo,-sizeof(Tarefa),SEEK_CUR);
			fwrite(&t , sizeof(Tarefa),1,arquivo);
			fflush(arquivo);
			break;
			
		}
		if (editar == 2){
			
		
			printf("Digite a nova descrição:");
			scanf(" %[^\n]" , t.descricao );
			printf("Descrição editada editado\n");
			fseek(arquivo,-sizeof(Tarefa),SEEK_CUR);
			fwrite(&t , sizeof(Tarefa),1,arquivo);
			fflush(arquivo);
			break;
			
		}
		if (editar == 3){
			
		
			printf("Digite o novo responsável:");
			scanf(" %[^\n]" , t.responsavel );
			printf("Responsável editado\n");
			fseek(arquivo,-sizeof(Tarefa),SEEK_CUR);
			fwrite(&t , sizeof(Tarefa),1,arquivo);
			fflush(arquivo);
			break;
			
		}
		if (editar == 4){
			
			if (t.status == 1)
			{
				t.status = 0;
			}
			else
				t.status = 1;
			
			
			printf("Status da tarefa alterada\n");
			
			fseek(arquivo,-sizeof(Tarefa),SEEK_CUR);
			fwrite(&t , sizeof(Tarefa),1,arquivo);
			fflush(arquivo);
			break;
			
		}
	}
}
void excluirTarefa(FILE *arquivo){
	
	fseek(arquivo,0,SEEK_SET);
	Tarefa t;
	char alvo[MAX];
	printf("Digite o nome da tarefa a ser excluida: ");
	scanf(" %[^\n]" , alvo);
	while(fread(&t,sizeof(Tarefa),1,arquivo)==1){
	
		if (t.flag == 1 && strcmp(t.nome,alvo)==0)
		{
			t.flag = 0;
			printf("Tarefa excluida\n");
			fseek(arquivo , -sizeof(Tarefa),SEEK_CUR);
			fwrite(&t,sizeof(Tarefa),1,arquivo);

		}
		
	}
}



int main(){
	
	FILE *arquivo = abrirArquivo("afazeres.txt");
	
	do{
		switch (interface()){
			
			case 1: novaTarefa(arquivo);
				break;
			case 2: listarTarefa(arquivo);
				break;
			case 3: editarTarefa(arquivo);
				break;
			case 4:excluirTarefa(arquivo);
				break;
			case 5: return 0;
			
		}
	} while (1);
	fclose(arquivo);
	
}
