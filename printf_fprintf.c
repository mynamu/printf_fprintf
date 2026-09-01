#include <stdio.h>
#include <time.h>

#define NUM_ITERS 1000000

int main() {

	clock_t start, end;
	int i;
	FILE *fp;

	// printf() time test
	start = clock();
	for (i = 0; i < NUM_ITERS; i++) {
		printf("Hello World\n");
	}
	end = clock();
	double printf_time = ((double)(end - start)) / CLOCKS_PER_SEC;


	// fprintf() time test
	fp = fopen("output.txt", "w");
	if (fp == NULL) {
		perror("Erro ao abrir arquivo");
		return 1;
	}


	start = clock();
	for (i = 0; i < NUM_ITERS; i++) {
		fprintf(fp, "Bye World\n");
	}
	end = clock();
	double fprintf_time = ((double)(end - start)) / CLOCKS_PER_SEC;

	fclose(fp);


	printf("printf time: %f seconds\n", printf_time);
	printf("fprintf time: %f seconds\n", fprintf_time);

	return 0;
}
