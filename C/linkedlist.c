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

int main() {
	node * test_list = (node *) malloc(sizeof(node));
	test_list->val = 1;
	test_list->next = (node *) malloc(sizeof(node));
	test_list->next->val = 2;
	test_list->next->next = (node *) malloc(sizeof(node));
	test_list->next->next->val = 3;
	print_list(test_list);
	return 0;
}
