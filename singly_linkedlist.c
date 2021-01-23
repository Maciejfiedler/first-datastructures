#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} node;

node *head = NULL;

void append(int val){
	if(!head){
		head = (node *) malloc(sizeof(node));

		head->data = val;
		head->next = NULL;
	}
	else{
		node *new = head;
		while(new->next != NULL){
			new = new->next;
		}

		new->next = (node *) malloc(sizeof(node));

		new->next->data = val;
		new->next->next = NULL;
	}
}

void insertfirst(int val){
	node *newhead = NULL;

	newhead = (node *) malloc(sizeof(node));

	newhead->data = val;
	newhead->next = head;

	head = newhead;
}

void insertat(int pos,int val){
	int count = 1;
	node *trav = head;
	node *tmp = NULL;
	node *new = NULL;
	
	while((pos - 1)>count){
		trav = trav->next;
		count++;
	}
	
	tmp = trav->next;
	printf("d: %d \n", tmp->data);

	new = (node *) malloc(sizeof(node));
	new->data = val;
	new->next = tmp;

	trav->next = new;
}

void removefirst(){
	node * todelete = NULL;

	todelete = head;
	head = head->next;

	free(todelete);
}

void removelast(){
	node *tailprev = head;
	node *tail = head;
	while(tailprev->next->next != NULL){
		tailprev = tailprev->next;
	}
	tail = tailprev->next;

	tailprev->next = NULL;
	free(tail);
}

void removeat(int pos){
	int count = 1;
	node *trav = head;

	node *next = NULL;
	while((pos-1)>count){
		trav = trav->next;
		count++;
	}
	next = trav->next->next;

	trav->next = NULL;
	free(trav->next);

	trav->next = next;
}

void printlist(){
	node *trav = head;
	while(trav){
		printf("%d \n", trav->data);
		trav = trav->next;
	}
}
int size(){
	int size = 0;
	node *trav = head;
	while(trav){
		trav = trav->next;
		size++;
	}
	return size;
}

int main(){

	append(0);
	append(1);
	append(2);
	append(3);
	append(4);
	append(5);
	append(6);
	append(7);

	insertat(3,18);
	removeat(3);

	printlist();
	printf("size = %d \n", size());

	return 0;
}
