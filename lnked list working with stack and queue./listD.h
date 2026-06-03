
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TypeStudent{
	
	char *name;
	int age;
	
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
}TypeList;

typedef TypeList* List;

List new_list(){
	
	List new = malloc(sizeof(TypeList));
	
	new->head = NULL;
	new->tail = NULL;
	new->current = NULL;
	new->size = 0;
	return new;
}

Student new_student(char nome[] , int age){
	
	Student new = malloc(sizeof(TypeStudent));
	new->age = age;
	new->name = malloc(strlen(nome)+1);
	strcpy(new->name , nome);
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
		return;
	}
	
	new->next = NULL;
	new->prev = list->tail;
	list->tail->next = new;
	list->tail = new;
	list->current = new;
	list->size++;
	
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
		printf("Idade : %d\n\n" , temp->data->age);
		temp = temp->next;
		
	}

}

