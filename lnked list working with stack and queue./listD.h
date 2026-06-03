
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeStudent{
	
	char *name;
	int age;
	int id;
	
}TypeStudent;

typedef TypeStudent* Student;

typedef struct TypeNode{
	
	Student data;
    struct TypeNode* next;
    struct TypeNode* prev;
	
}TypeNode;

typedef TypeNode* Node;

typedef struct TypeList{
    Node head;
    Node tail;
    Node current;
    int size;
    int nextId;
}TypeList;

typedef TypeList* List;

List new_list(){
	
	List new = malloc(sizeof(TypeList));
	
	new->head = NULL;
	new->tail = NULL;
	new->current = NULL;
	new->size = 0;
	new->nextId = 0;
	return new;
}

Student new_student(char nome[] , int age , int id){
	
	Student new = malloc(sizeof(TypeStudent));
	new->age = age;
	new->name = malloc(strlen(nome)+1);
	strcpy(new->name , nome);
	new->id = id;
	return new;
}

void insert_queue(List list , Student student){
	
	Node new = malloc(sizeof(TypeNode));
	
	new->data = student;
	
	if (!list->head){
		
		new->prev = NULL;
		new->next = NULL;
		
		list->head = new;
		list->tail = new;
		list->current = new;
		
		list->size++;
		new->data->id++;
		return;
	}
	
	new->next = NULL;
	new->prev = list->tail;
	list->tail->next = new;
	list->tail = new;
	list->current = new;
	list->size++;
	new->data->id++;

	
}

void insert_stack(List list , Student student){
	
	Node new = malloc(sizeof(TypeNode));
	
	new->data = student;
	
	if (!list->tail)
	{
		new->next = NULL;
		new->prev = NULL;
		list->head = new;
		list->tail = new;
		list->current = new;
		
		list->size++;
		return;
	}
	new->prev = NULL;
	new->next = list->head;
	list->head->prev = new;
	list->head  = new;
	list->current = new;
	list->size++;
	
}
void print_aluno(List list){
	
	if (!list->head)
	{
		return;
	}
	
	Node temp = list->head;
	while (temp)
	{
		printf("Aluno : %s\n" , temp->data->name);
		printf("Idade : %d\n" , temp->data->age);
		printf("ID: %d\n\n" , temp->data->id);
		temp = temp->next;
		
	}

}

Node busca(List list){
	
	int alvo;
	printf("Digite qual indice excluir ");
	scanf("%d",&alvo);
	
	Node temp = list->head;
	
	while (temp){
		
		if (temp->data->id == alvo)
		{
			return temp;
		}
		temp = temp->next;
		
	}
	return 0;
}
void excluir_aluno(List list){
	
	Node temp = busca(list);
	
	if (!temp)
	{
		return;
	}
	if (temp == NULL)
	{
		printf("Alvo n encontrado");
	}
	if (temp == list->head && temp == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
		list->current = NULL;
		free(temp);
		list->size--;
	}
	if (temp == list->head)
	{
		list->head = temp->next;
		list->head->prev = NULL;
		free(temp);
		list->size--;
	}
	if (temp == list->tail)
	{
		list->tail = temp->prev;
		list->tail->next = NULL;
		free(temp);
		list->size--;
	}
	if (temp != list->head && temp != list->tail)
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
	
		free(temp);
		list->size--;
	}
}




