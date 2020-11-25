#include <stdlib.h>
#include <string.h>

char** unite(char** matrix1, char** matrix2, int size) {

	char** matrix = (char**)calloc(size, sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size; i++) {
		matrix[i] = (char*)calloc(size, sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = (matrix1[i][j] | matrix2[i][j]);
		}
	}
	return matrix;
}

char** intersect(char** matrix1, char** matrix2, int size) {

	char** matrix = (char**)calloc(size, sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size; i++) {
		matrix[i] = (char*)calloc(size, sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = (matrix1[i][j] & matrix2[i][j]);
		}
	}
	return matrix;
}

char** ring_sum(char** matrix1, char** matrix2, int size) {

	char** matrix = (char**)calloc(size, sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size; i++) {
		matrix[i] = (char*)calloc(size, sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = (matrix1[i][j] ^ matrix2[i][j]);
		}
	}
	return matrix;
}