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


int pop(node ** head) {
	int val;
	node * next_node = NULL;

	if (*head == NULL) {
		return -1;
	}

	next_node = (*head)->next;
	val = (*head)->val;
	free(*head);
	*head = next_node;

	return val;
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

int remove_last(node ** head) {
	int val;

	if (*head == NULL) {
		return -1;

	} else if ((*head)->next == NULL) {
		val = (*head)->val;
		free(head);
		return val;
	}

	node * current = *head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	val = current->next->val;
	free(current->next);
	current->next = NULL;
	return val;
}

int main() {
	node * test_list = (node *) malloc(sizeof(node));
	test_list->val = 1;
	push(&test_list, 2);
	push(&test_list, 3);

	print_list(test_list);
	
	printf("Pop value %d\n", pop(&test_list));
	printf("New list\n");
	print_list(test_list);

	printf("Remove Last\n");
	remove_last(&test_list);
	print_list(test_list);

	return 0;
}
