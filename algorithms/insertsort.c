#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char *randomList(int n) {

	// Create a random array //
	
	int i;
	char *list = malloc(n);
	
	srand(time(0));

	if (!list) {
		return NULL;
	}
	for (i = 0; i < n; i++) {
		list[i] = (rand() % 100);
	}
	return list;
}

int main() {

	int n = 10;
	int i;
	int j;
	int k;
	int key;
	char *numbers = randomList(n);

	printf("\nInsertion-Sort algorithm implementation\n");
	printf("Array of %d numbers generated randomly between 0 and 100\n\n", n);

	printf("Original array\n");
	for (i = 0; i < n; i++) {
		printf("%d ", numbers[i]);
	}
	
	for (j = 1; j < n; j++) {
		key = numbers[j];
		k = j - 1;
		while ( k >= 0 && numbers[k] > key) {
			numbers[k + 1] = numbers[k];
			k = k - 1;
		}
		numbers[k + 1] = key;
	}
	
	printf("\n\nSorted numbers\n");
	for (i = 0; i < n; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
	return 0;
}

