#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node * next;
} node;

void print_list(node * head) {
	node * current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

void push(node ** head, int val) {
	node * new_head;
	new_head = (node *) malloc(sizeof(node));

	new_head->val = val;
	new_head->next = *head;
	*head = new_head;
}


void add_last(node * head, int val) {
	node * current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = (node *) malloc(sizeof(node));
	current->next->val = val;
	current->next->next = NULL;
}


int main() {
	node * test_list = (node *) malloc(sizeof(node));
	test_list->val = 1;
	push(&test_list, 2);
	push(&test_list, 3);

	print_list(test_list);
	return 0;
}
