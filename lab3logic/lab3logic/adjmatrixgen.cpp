#include <time.h>
#include <stdlib.h>

char** gen_adj_matrix(int size) {

	srand(time(0));
	char** matrix = (char**)calloc(size, sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size; i++) {
		matrix[i] = (char*)calloc(size, sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = rand() % 2;
				matrix[j][i] = matrix[i][j];
			}
		}
	}
	return matrix;
}