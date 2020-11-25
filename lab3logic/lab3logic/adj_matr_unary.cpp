#include <stdlib.h>
#include <string.h>


char** delete_vertex(char** oldmatrix, int size, int to_del) {

	char** matrix = (char**)calloc(size - long long int(1), sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size-1; i++) {
		matrix[i] = (char*)calloc(size - long long int(1), sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if ((i != to_del) && (j != to_del)) {
				matrix[(i < to_del) ? i : i - 1][(j < to_del) ? j : j - 1] = oldmatrix[i][j];
				matrix[(j < to_del) ? j : j - 1][(i < to_del) ? i : i - 1] = matrix[(i < to_del) ? i : i - 1][(j < to_del) ? j : j - 1];
			}
		}
	}
	return matrix;
}


char** vertex_cleaving(char** oldmatrix, int size, int to_cleaving) {

	char** matrix = (char**)calloc(size + long long int(1), sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size + 1; i++) {
		matrix[i] = (char*)calloc(size + long long int(1), sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if ((i != to_cleaving) && (j != to_cleaving)) {
				matrix[i][j] = oldmatrix[i][j];
				matrix[j][i] = oldmatrix[i][j];
			}
		}
	}
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			matrix[to_cleaving][i] = oldmatrix[to_cleaving][i];
			matrix[i][to_cleaving] = oldmatrix[to_cleaving][i];
		}
		else {
			matrix[size][i] = oldmatrix[to_cleaving][i];
			matrix[i][size] = oldmatrix[to_cleaving][i];
		}
	}
	matrix[size][to_cleaving] = 1;
	matrix[to_cleaving][size] = 1;
	

	return matrix;
}


char** edge_contraction(char** oldmatrix, int size, char vertex1, char vertex2) {

	if (oldmatrix[vertex1][vertex2] != 1) {
		return NULL;
	}

	if (vertex1 > vertex2) {
		char buffer;
		buffer = vertex2;
		vertex2 = vertex1;
		vertex1 = buffer;
	}

	char** matrix = (char**)calloc(size - long long int(1), sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size - 1; i++) {
		matrix[i] = (char*)calloc(size - long long int(1), sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}

	char* result_vertex = (char*)calloc(size - long long int(1), sizeof(char));
	for (int i = 0; i < size; i++) {
		if (vertex1 || vertex2) {
			result_vertex[(i < vertex2) ? i : i-1] = 1;
		}
		else
		{
			result_vertex[(i < vertex2) ? i : i - 1] = 0;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if ((i != vertex1) && (j != vertex1) && (i != vertex2) && (j != vertex2)) {
				matrix[(i < vertex2) ? i : i - 1][(j < vertex2) ? j : j - 1] = oldmatrix[i][j];
				matrix[(j < vertex2) ? j : j - 1][(i < vertex2) ? i : i - 1] = matrix[(i < vertex2) ? i : i - 1][(j < vertex2) ? j : j - 1];
				}
			}
		}	
	for (int i = 0; i < size-1; i++) {
		if (vertex1 == i) {
			matrix[i][vertex1] = 0;
		}
		else {
			matrix[vertex1][i] = result_vertex[i];
			matrix[i][vertex1] = result_vertex[i];
		}

	}
	return(matrix);
}


char** vertex_identification(char** oldmatrix, int size, char vertex1, char vertex2) {

	if (vertex1 > vertex2) {
		char buffer;
		buffer = vertex2;
		vertex2 = vertex1;
		vertex1 = buffer;
	}

	char** matrix = (char**)calloc(size - long long int(1), sizeof(char*));
	if (matrix == NULL)
		return NULL;

	for (int i = 0; i < size - 1; i++) {
		matrix[i] = (char*)calloc(size - long long int(1), sizeof(char));
		if (matrix[i] == NULL)
			return NULL;
	}

	char* result_vertex = (char*)calloc(size - long long int(1), sizeof(char));
	for (int i = 0; i < size; i++) {
		if (vertex1 || vertex2) {
			result_vertex[(i < vertex2) ? i : i - 1] = 1;
		}
		else
		{
			result_vertex[(i < vertex2) ? i : i - 1] = 0;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if ((i != vertex1) && (j != vertex1) && (i != vertex2) && (j != vertex2)) {
				matrix[(i < vertex2) ? i : i - 1][(j < vertex2) ? j : j - 1] = oldmatrix[i][j];
				matrix[(j < vertex2) ? j : j - 1][(i < vertex2) ? i : i - 1] = matrix[(i < vertex2) ? i : i - 1][(j < vertex2) ? j : j - 1];
			}
		}
	}
	for (int i = 0; i < size - 1; i++) {
		matrix[vertex1][i] = result_vertex[i];
		matrix[i][vertex1] = result_vertex[i];
	}
	return(matrix);
}


