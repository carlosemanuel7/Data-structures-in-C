#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXCARACTER 100
#define MAX 100

typedef struct{
	int id;
	char titulo[MAXCARACTER];
	char artista[MAXCARACTER];
	int tempo; // segundos
}Musicas;

int interface(){
	
	int opt;

	printf("== MINHA PLAYLIST ==\n");
	printf("1 - Adicionar música\n");
	printf("2 - Excluir música\n");
	printf("3 - Tocar playlist\n");
	printf("4 - Tocar por artista\n");
	printf("5 - Tocar aleatorio\n");
	printf("6 - Encerrar programa\n");
	scanf("%d" ,&opt);
	
	system("clear");
	return opt;
}

void adicionarMusica(Musicas m[] , int *proxid , int *cont){
	
	printf("Digite o nome da música: ");
	scanf(" %[^\n]" , m[*cont].titulo);

	printf("Digite o artista: ");
	scanf(" %[^\n]" , m[*cont].artista);

	printf("Digite o tempo (em segundos): ");
	scanf("%d" , &m[*cont].tempo);

	m[*cont].id = *proxid + 1;
	(*proxid)++;
	(*cont)++;
}

void excluirMusica(Musicas m[] , int *cont){
	
	char alvo[MAXCARACTER];
	int pos = -1;

	printf("Digite o nome da música a ser excluída: ");
	scanf(" %[^\n]" , alvo);

	for(int i = 0; i < *cont; i++){
		if(strcmp(alvo , m[i].titulo) == 0){
			pos = i;
			break;
		}
	}

	if(pos == -1){
		printf("Música não encontrada.\n");
		return;
	}

	for(int j = pos; j < *cont - 1; j++){
		m[j] = m[j+1];
	}

	(*cont)--;
	printf("Música excluída com sucesso.\n");
}

void imprimirTabela(Musicas m[], int cont){

	printf("ID\tTitulo\t\tArtista\t\tTempo\n");

	int total = 0;

	for(int i = 0; i < cont; i++){

		int minutos = m[i].tempo / 60;
		int segundos = m[i].tempo % 60;

		printf("%d\t%s\t\t%s\t\t%02d:%02d\n",
			   m[i].id,
			   m[i].titulo,
			   m[i].artista,
			   minutos,
			   segundos);

		total += m[i].tempo;
	}

	int totalMin = total / 60;
	int totalSeg = total % 60;

	printf("\nTempo total: %02d:%02d\n\n", totalMin, totalSeg);
}

void tocarPlaylist(Musicas m[] , int cont){

	if(cont == 0){
		printf("Playlist vazia.\n");
		return;
	}

	printf("Tocando playlist por ordem de inserção\n\n");
	imprimirTabela(m, cont);
}

void ordenarArtista(Musicas m[] , int cont){

	if(cont == 0){
		printf("Playlist vazia.\n");
		return;
	}

	Musicas aux;

	for(int i = 0; i < cont - 1; i++){
		for(int j = 0; j < cont - i - 1; j++){
			if(strcmp(m[j].artista , m[j+1].artista) > 0){
				aux = m[j];
				m[j] = m[j+1];
				m[j+1] = aux;
			}
		}
	}

	printf("Tocando playlist ordenada por artista\n\n");
	imprimirTabela(m, cont);
}

void tocarAleatorio(Musicas m[] , int cont){

	if(cont == 0){
		printf("Playlist vazia.\n");
		return;
	}

	Musicas temp;

	// Embaralhamento real
	for(int i = cont - 1; i > 0; i--){
		int j = rand() % (i + 1);
		temp = m[i];
		m[i] = m[j];
		m[j] = temp;
	}

	printf("Tocando playlist aleatoriamente\n\n");
	imprimirTabela(m, cont);
}

int main(){
	
	srand(time(NULL));

	Musicas m[MAX];
	int proxid = 0;
	int cont = 0;

	do{
		switch(interface()){
			
			case 1: adicionarMusica(m , &proxid , &cont);
					break;
					
			case 2: excluirMusica(m , &cont);
					break;
					
			case 3: tocarPlaylist(m , cont);
					break;
					
			case 4: ordenarArtista(m , cont);
					break;
					
			case 5: tocarAleatorio(m , cont);
					break;
					
			case 6: return 0;
		}
		
	} while(1);
}
