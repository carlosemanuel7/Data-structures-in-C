#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROTAS 100
#define MAX_CDD 100

typedef struct{
	
	char cdd_origem[MAX_CDD];
	char cdd_destino[MAX_CDD];
	int km;
	int horas;
	
}Rotas;

int interface(){
	
	int opt ;
	do
	{
		printf("---SEDEX ENTREGAS---\n");
		printf("Escolha a opção desejada:\n");
		printf("1 - Cadastrar rotas\n");
		printf("2 - Consultar distância\n");
		printf("3 - Encerrar programa\n");
		scanf("%d" , &opt);
		
	} while (0);
	system("clear");
	return opt;
	
}

void cadastrarRota(Rotas r[] , int *cont){
	
		
		printf("Digite a cidade de origem: ");
		scanf(" %[^\n]" , r[*cont].cdd_origem);
		
		for (int i = 0; i < *cont; i++){
			
			if (strcmp (r[i].cdd_origem , r[i+1].cdd_origem) == 0){
				
				printf("Cidade de origem já cadastrada,TENTE NOVAMENTE\n\n");
				return;
				
			}
		}
		printf("digite a cidade de destino ");
		scanf(" %[^\n]" , r[*cont].cdd_destino);
		printf("DIgite a distancia da rota em KM: ");
		scanf("%d" , &r[*cont].km);
		printf("Digite o tempo gasta para fazer a rota, em horas: ");
		scanf("%d" , &r[*cont].horas);
		(*cont)++;
		
	
	system("clear");
	
}

void consultarRota(Rotas r[] , int cont){
	
	char origem[MAX_ROTAS];
	char destino[MAX_ROTAS];
	int flag;
	int verificar = 0;
	int acumular_km = 0;
	int acumular_h = 0;
	int contar_rotas = 0;
	
	printf("Digite a cidade de origem ");
	scanf(" %[^\n]" , origem);
	printf("Digite a cidade de destino ");
	scanf(" %[^\n]" , destino);
	
	do
	{
	
	
	for (int i = 0; i < cont; i++){
		
		if (strcmp(origem , r[i].cdd_origem) ==0 ){
			
			flag = i;
			verificar = 1;
			
		}
		
	}
	
		if (!verificar){
			
			printf("Rota inexistente");
				break;
		}
	
		else{
			
			acumular_h+= r[flag].horas;
			acumular_km+= r[flag].km;
			contar_rotas++;
		}
		
		if (strcmp(destino , r[flag].cdd_destino) == 0){
			
			printf("distancia : %d \n" , acumular_km);
			printf("horas : %d \n" , acumular_h);
			printf("total rotas : %d \n" , contar_rotas);
				break;
		}
		
		else {
			
			strcpy(origem , r[flag].cdd_destino); 
		}
	} while (1);
}
	
int main(){
	
	Rotas r[MAX_ROTAS];
	int cont = 0;
	int opt;
	do{
		
		opt = interface();
		
		if(opt == 1)
		
			cadastrarRota(r , &cont);
		
		
		if (opt == 2)
		
			consultarRota(r , cont);
		
		if (opt == 3)
		
			return 0;
			
	} while (1);
}
