
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listD.h"


int interface(){
	
	int opt;
	printf("1 - Cadastrar aluno no final\n");
	printf("2 - Cadastrar aluno no inicio\n");
	printf("3 - Printar aluno\n");
	scanf("%d" , &opt);
	return opt;
}

void insert_last(List list){
	
	int age;
	char nome[100];
	printf("Nome: ");
	scanf("%s", nome);
	printf("Idade: ");
	scanf("%d", &age);
	Student aluno = new_student(nome, age);

	insert_queue(list, aluno);
	
}
void insert_first(List list){
	
	int age;
	char nome[100];
	printf("Nome: ");
	scanf("%s", nome);
	printf("Idade: ");
	scanf("%d", &age);
	Student aluno = new_student(nome, age);
	insert_stack(list, aluno);
	
}
int main()
{
	List list = new_list();
	do
	{
		switch (interface())
		{
			case 1 : insert_last(list);
				break;
				
			case 2 : insert_first(list) ;
				break;
			
			case 3: print_aluno(list);
				break;
			
		
		}
	} while (1);

}

