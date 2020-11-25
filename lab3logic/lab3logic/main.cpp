#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	int vertex1, vertex2;
	for (;1;) {
		printf("1) Удаление вершины\n");
		printf("2) Расщепление вершины\n");
		printf("3) Стягивание ребра\n");
		printf("4) Отождествление вершин\n");
		printf("5) Объединение графов\n");
		printf("6) Пересечение графов\n");
		printf("7) Кольцевая сумма графов\n");
		printf("0) Выход\n\n");

		switch (_getch()) {
			case ('0'): {
				return (0);
			}
			case ('1'): {

				printf("Удаление вершины\n");
				printf("Введите размер матрицы: ");
				scanf("%d", &size);
				char** adj = gen_adj_matrix(size);
				pr_adj_matrix(adj, size);
				printf("\nВведите номер вершины для удаления: ");
				scanf("%d", &vertex1);
				adj = delete_vertex(adj, size, vertex1);
				pr_adj_matrix(adj, size-1);
				printf("\nНажмите любую клавишу для продолжения");
				_getch();
				system("cls");
				break;
			}
			case ('2'): {
				printf("Расщепление вершины\n");
				printf("Введите размер матрицы: ");
				scanf("%d", &size);
				char** adj = gen_adj_matrix(size);
				pr_adj_matrix(adj, size);
				printf("\nВведите номер вершины для расщепления: ");
				scanf("%d", &vertex1);
				adj = vertex_cleaving(adj, size, vertex1);
				pr_adj_matrix(adj, size + 1);
				printf("\nНажмите любую клавишу для продолжения");
				_getch();
				system("cls");
				break;
			}
			case ('3'): {
				printf("Стягивание ребра\n");
				printf("Введите размер матрицы: ");
				scanf("%d", &size);
				char** adj = gen_adj_matrix(size);
				pr_adj_matrix(adj, size);
				printf("\nВведите номера вершин для стягивания через пробел: ");
				scanf("%d %d", &vertex1, &vertex2);
				if (adj = edge_contraction(adj, size, vertex1, vertex2)) {
					pr_adj_matrix(adj, size - 1);
				}
				else
					printf("\nМежду вершинами нет ребра");
				printf("\nНажмите любую клавишу для продолжения");
				_getch();
				system("cls");
				break;
			}
			case ('4'): {
				printf("Отождествление вершин\n");
				printf("Введите размер матрицы: ");
				scanf("%d", &size);
				char** adj = gen_adj_matrix(size);
				pr_adj_matrix(adj, size);
				printf("\nВведите номера вершин для отождествления через пробел: ");
				scanf("%d %d", &vertex1, &vertex2);
				adj = vertex_identification(adj, size, vertex1, vertex2);
				pr_adj_matrix(adj, size - 1);
				printf("\nНажмите любую клавишу для продолжения");
				_getch();
				system("cls");
				break;
			}
			case ('5'): {
				printf("Объединение графов\n");
				printf("Введите размер матриц: ");
				scanf("%d", &size);
				char** adj1 = gen_adj_matrix(size);
				Sleep(500);
				char** adj2 = gen_adj_matrix(size);
				pr_adj_matrix(adj1, size);
				printf("\n");
				pr_adj_matrix(adj2, size);
				printf("\nРезультат\n");
				adj1 = unite(adj1, adj2, size);
				pr_adj_matrix(adj1, size);
				printf("\nНажмите любую клавишу для продолжения");
				_getch();
				system("cls");
				break;
			}
			case ('6'): {
				printf("Пересечение графов\n");
				printf("Введите размер матриц: ");
				scanf("%d", &size);
				char** adj1 = gen_adj_matrix(size);
				Sleep(500);
				char** adj2 = gen_adj_matrix(size);
				pr_adj_matrix(adj1, size);
				printf("\n");
				pr_adj_matrix(adj2, size);
				printf("\nРезультат\n");
				adj1 = intersect(adj1, adj2, size);
				pr_adj_matrix(adj1, size);
				printf("\nНажмите любую клавишу для продолжения");
				_getch();
				system("cls");
				break;
			}
			case ('7'): {
				printf("Кольцевая сумма графов\n");
				printf("Введите размер матриц: ");
				scanf("%d", &size);
				char** adj1 = gen_adj_matrix(size);
				Sleep(500);
				char** adj2 = gen_adj_matrix(size);
				pr_adj_matrix(adj1, size);
				printf("\n");
				pr_adj_matrix(adj2, size);
				printf("\nРезультат\n");
				adj1 = ring_sum(adj1, adj2, size);
				pr_adj_matrix(adj1, size);
				printf("\nНажмите любую клавишу для продолжения");
				_getch();
				system("cls");
				break;
			}
			default: printf("Неизвестная команда\n\n");
		}
	}
}