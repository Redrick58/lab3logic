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
		printf("1) �������� �������\n");
		printf("2) ����������� �������\n");
		printf("3) ���������� �����\n");
		printf("4) �������������� ������\n");
		printf("5) ����������� ������\n");
		printf("6) ����������� ������\n");
		printf("7) ��������� ����� ������\n");
		printf("0) �����\n\n");

		switch (_getch()) {
			case ('0'): {
				return (0);
			}
			case ('1'): {

				printf("�������� �������\n");
				printf("������� ������ �������: ");
				scanf("%d", &size);
				char** adj = gen_adj_matrix(size);
				pr_adj_matrix(adj, size);
				printf("\n������� ����� ������� ��� ��������: ");
				scanf("%d", &vertex1);
				adj = delete_vertex(adj, size, vertex1);
				pr_adj_matrix(adj, size-1);
				printf("\n������� ����� ������� ��� �����������");
				_getch();
				system("cls");
				break;
			}
			case ('2'): {
				printf("����������� �������\n");
				printf("������� ������ �������: ");
				scanf("%d", &size);
				char** adj = gen_adj_matrix(size);
				pr_adj_matrix(adj, size);
				printf("\n������� ����� ������� ��� �����������: ");
				scanf("%d", &vertex1);
				adj = vertex_cleaving(adj, size, vertex1);
				pr_adj_matrix(adj, size + 1);
				printf("\n������� ����� ������� ��� �����������");
				_getch();
				system("cls");
				break;
			}
			case ('3'): {
				printf("���������� �����\n");
				printf("������� ������ �������: ");
				scanf("%d", &size);
				char** adj = gen_adj_matrix(size);
				pr_adj_matrix(adj, size);
				printf("\n������� ������ ������ ��� ���������� ����� ������: ");
				scanf("%d %d", &vertex1, &vertex2);
				if (adj = edge_contraction(adj, size, vertex1, vertex2)) {
					pr_adj_matrix(adj, size - 1);
				}
				else
					printf("\n����� ��������� ��� �����");
				printf("\n������� ����� ������� ��� �����������");
				_getch();
				system("cls");
				break;
			}
			case ('4'): {
				printf("�������������� ������\n");
				printf("������� ������ �������: ");
				scanf("%d", &size);
				char** adj = gen_adj_matrix(size);
				pr_adj_matrix(adj, size);
				printf("\n������� ������ ������ ��� �������������� ����� ������: ");
				scanf("%d %d", &vertex1, &vertex2);
				adj = vertex_identification(adj, size, vertex1, vertex2);
				pr_adj_matrix(adj, size - 1);
				printf("\n������� ����� ������� ��� �����������");
				_getch();
				system("cls");
				break;
			}
			case ('5'): {
				printf("����������� ������\n");
				printf("������� ������ ������: ");
				scanf("%d", &size);
				char** adj1 = gen_adj_matrix(size);
				Sleep(500);
				char** adj2 = gen_adj_matrix(size);
				pr_adj_matrix(adj1, size);
				printf("\n");
				pr_adj_matrix(adj2, size);
				printf("\n���������\n");
				adj1 = unite(adj1, adj2, size);
				pr_adj_matrix(adj1, size);
				printf("\n������� ����� ������� ��� �����������");
				_getch();
				system("cls");
				break;
			}
			case ('6'): {
				printf("����������� ������\n");
				printf("������� ������ ������: ");
				scanf("%d", &size);
				char** adj1 = gen_adj_matrix(size);
				Sleep(500);
				char** adj2 = gen_adj_matrix(size);
				pr_adj_matrix(adj1, size);
				printf("\n");
				pr_adj_matrix(adj2, size);
				printf("\n���������\n");
				adj1 = intersect(adj1, adj2, size);
				pr_adj_matrix(adj1, size);
				printf("\n������� ����� ������� ��� �����������");
				_getch();
				system("cls");
				break;
			}
			case ('7'): {
				printf("��������� ����� ������\n");
				printf("������� ������ ������: ");
				scanf("%d", &size);
				char** adj1 = gen_adj_matrix(size);
				Sleep(500);
				char** adj2 = gen_adj_matrix(size);
				pr_adj_matrix(adj1, size);
				printf("\n");
				pr_adj_matrix(adj2, size);
				printf("\n���������\n");
				adj1 = ring_sum(adj1, adj2, size);
				pr_adj_matrix(adj1, size);
				printf("\n������� ����� ������� ��� �����������");
				_getch();
				system("cls");
				break;
			}
			default: printf("����������� �������\n\n");
		}
	}
}