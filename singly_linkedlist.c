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

void printlist(){
	node *trav = head;
	while(trav){
		printf("%d \n", trav->data);
		trav = trav->next;
	}

}

int main(){
	append(5);
	append(10);
	append(15);
	append(20);

	removelast();
	printlist();

	return 0;
}
