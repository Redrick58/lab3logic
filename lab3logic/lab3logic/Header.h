#pragma once

char** gen_adj_matrix(int size);
int pr_adj_matrix(char** matrix, int size);
char** vertex_cleaving(char** oldmatrix, int size, int to_cleaving);
char** delete_vertex(char** oldmatrix, int size, int to_del);
char** edge_contraction(char** oldmatrix, int size, char vertex1, char vertex2);
char** vertex_identification(char** oldmatrix, int size, char vertex1, char vertex2);
char** unite(char** matrix1, char** matrix2, int size);
char** intersect(char** matrix1, char** matrix2, int size);
char** ring_sum(char** matrix1, char** matrix2, int size);
