#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *randomList(int *arr, int size) {
	
	
	int i;
	
	srand(time(0));

	for (i = 0; i < size; i++) {
		arr[i] = (rand() % 1000);
	}
	return arr;

}

int main() {

	int n = 100;
	int i;
	int j;
	int k;
	int key;
	int arr[n];

	int *numbers = randomList(arr, n);

	clock_t t;

	printf("\nInsertion-Sort algorithm implementation\n");
	printf("Array of %d numbers generated randomly.", n);

	printf("Original array\n");
	for (i = 0; i < n; i++) {
		printf("%d ", numbers[i]);
	}
	
	t = clock();

	for (j = 1; j < n; j++) {
		key = numbers[j];
		k = j - 1;
		while ( k >= 0 && numbers[k] > key) {
			numbers[k + 1] = numbers[k];
			k = k - 1;
		}
		numbers[k + 1] = key;
	}
	
	// time elapsed in miliseconds
	t = clock() - t;
	double time_elapsed = (double)t/(CLOCKS_PER_SEC/1000);

	printf("\n\nSorted numbers\n");
	for (i = 0; i < n; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n\n");
	printf("Time elapsed: %.9f miliseconds.\n", time_elapsed);
	return 0;
}

