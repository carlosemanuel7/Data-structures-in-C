#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
	
	char placa[MAX];
	char cor[MAX];
	char modelo[MAX];
	char nome[MAX];
	int estacionou;
	

}Veiculo;

FILE* abrirArquivo(char nome_arq[]){
	
	FILE *arquivo = fopen(nome_arq , "rb+");
	
	if (!arquivo)
	{
		arquivo = fopen(nome_arq , "wb+");
	}
	return arquivo;
}

int interface(){
	
	int opt;
	
	do{	
		printf("== ESTACIONAMENTO ==\n");
		printf("1 - Entrada veículo\n");
		printf("2 - Utilização atual\n");
		printf("3 - Saida carro\n");
		printf("4 - Ordenar por placa\n");
		printf("5 - Encerrar programa\n");
		scanf("%d" , &opt);
	} while (0);
	system("clear");
	return opt;
}
void cadastroCarro(FILE *arquivo , char placa[]){
	
	Veiculo v;
	printf("Placa não encontrada\nCADASTRO DE VEÍCULOS\n");
	printf("Placa:%s\n" , placa);	
	strcpy(v.placa,placa);
	printf("Digite a cor do veiculo ");
	scanf(" %[^\n]" , v.cor);
	printf("Digite o modelo ");
	scanf(" %[^\n]" , v.modelo);
	printf("Digite o nome do proprietário do veículo ");
	scanf(" %[^\n]" , v.nome);
	v.estacionou = 1;
	
	
	fseek(arquivo,0,SEEK_END);
	fwrite(&v,sizeof(Veiculo),1,arquivo);
	system("clear");
}
void entradaCarro(FILE *arquivo){
	
	Veiculo v;
	char placa[MAX];
	int flag = 0;
	int escolha = 0;
	printf("Digite sua placa: ");
	scanf(" %s" , placa);
	fseek(arquivo,0,SEEK_SET);
	while (fread(&v , sizeof(Veiculo),1,arquivo))
	{
		if (strcmp(placa , v.placa) == 0)
		{
			flag = 1;
			break;
		}
		
	}
	
	if (flag == 1 && v.estacionou == 1)
	{
		printf("Carro já estacionado \n");
		printf("Placa: %s\n" , v.placa);
		printf("Cor: %s\n" , v.cor);
		printf("Modelo: %s\n" , v.modelo);
		printf("Nome: %s\n" , v.nome);
		
	}
	if (flag == 1 && v.estacionou == 0)
	{
		printf("Carro já cadastrado,mas não está estacionado \n");
		printf("Placa: %s\n" , v.placa);
		printf("Cor: %s\n" , v.cor);
		printf("Modelo: %s\n" , v.modelo);
		printf("Nome: %s\n" , v.nome);
		printf("\n\n");
		printf("Deseja estacionar?\n");
		printf("1 - sim\n");
		printf("2 - não\n");
		scanf("%d" , &escolha);
		if (escolha == 1)
		{
			v.estacionou = 1;
			printf("Carro estacionado\n");
			fseek(arquivo, -sizeof(Veiculo), SEEK_CUR);
            fwrite(&v, sizeof(Veiculo), 1, arquivo);
            fflush(arquivo);
			
		}
		else
			return;
	}
	if (flag == 0)
	{	
		cadastroCarro(arquivo,placa);
	}
}

void utilizacaoAtual(FILE *arquivo){
	
	Veiculo v;
	fseek(arquivo,0,SEEK_SET);
	
	while (fread(&v,sizeof(Veiculo),1,arquivo) == 1)
	{
		if (v.estacionou == 1){
			
			printf("Placa: %s\n" , v.placa);
			printf("Cor: %s\n" , v.cor);
			printf("Modelo: %s\n" , v.modelo);
			printf("Nome: %s\n" , v.nome);
			printf("\n");
		}
		
	}
}

void saidaCarro(FILE *arquivo){
	
	Veiculo v;
	char excluir[MAX];
	fseek(arquivo,0,SEEK_SET);
	
	printf("Digite a placa do veículo que deseja excluir: ");
	scanf(" %[^\n]" , excluir);
	
	while (fread(&v,sizeof(Veiculo),1,arquivo)==1)
	{
		if (v.estacionou == 1 && strcmp(excluir , v.placa)==0)
		{
			v.estacionou = 0;
			
			fseek(arquivo,-sizeof(Veiculo),SEEK_CUR);
			fwrite(&v,sizeof(Veiculo),1,arquivo);
		
			printf("Carro saindo! \n! \n! \n!\n");
			
			return;
			
		}
		
	}
	printf("placa não encontrada /:");
	
}
void ordenarPlaca(FILE *arquivo){
	
	fseek(arquivo,0,SEEK_END);
	int p = ftell(arquivo) / sizeof(Veiculo);
	fseek(arquivo,0,SEEK_SET);
	Veiculo lista[p];
	Veiculo aux;
	fread(lista,p * sizeof(Veiculo),1,arquivo);
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p - 1 - i; j++)
		{
			if (strcmp(lista[j].nome,lista[j+1].nome)>0)
			{
				aux = lista[j];
				lista[j] = lista[j+1];
				lista[j+1] = aux;
				
			}
		}
	}
	fseek(arquivo,0,SEEK_SET);
	fwrite(lista,p*sizeof(Veiculo),1,arquivo);
	fflush(arquivo);
	printf("Os carros foram ordenados por ordem de nome!\n");
}


int main(){
	
	FILE *arquivo = abrirArquivo("estacionamento.txt");
	do{
		
	switch (interface()){
		
		case 1: entradaCarro(arquivo);
			break;
			
		case 2: utilizacaoAtual(arquivo);
			break;
			
		case 3: saidaCarro(arquivo);
			break;
			
		case 4: ordenarPlaca(arquivo);
			break;
			
		case 5: return 0;
	}
	} while (1);
	fclose(arquivo);
}
