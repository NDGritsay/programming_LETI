#include "stdafx.h"
#include "Windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int **arr1 = NULL, **arr2 = NULL;
	short clmct, str1ct, str2ct, ismatch, menu, isarr1 = 0, isarr2 = 0, isprogend = 0;

	do
	{
		system("title 1.4 ������������ �������");
		system("cls");
		printf_s("==����==\n1.���� �������.\n2.����� �������� �������\n3.��������� �������� �������\n4.����� �������������� �������\n5.�������\n6.�����\n\n������� ����� ����: ");
		switch (menu = getchar())
		{
		case '1': //���� �������
			if (arr1 != NULL)
			{
				for (short i = 0; i < str1ct; i++)
					free(*(arr1 + i));
				free(arr1);
				arr1 = NULL;
			}
			isarr1 = 1;
			isarr2 = 0;
			system("cls");
			printf_s("==���� �������==\n");
			//���� ���-�� �����
			do
			{
				printf("������� ���������� ����� �������� �������: ");
				scanf_s("%hi", &str1ct);
				if (str1ct < 1)
					printf_s("������! ���������� �������� �� ����� ���� ������ 1\n");
			} while (str1ct < 1);
			//���� ���-�� ��������
			do
			{
				printf("������� ���������� �������� �������� �������: ");
				scanf_s("%hi", &clmct);
				if (clmct < 1)
					printf_s("������! ���������� ����� �� ����� ���� ������ 1\n");
			} while (clmct < 1);
			//������������ �������� �������
			arr1 = (int**)malloc(sizeof(int*) * str1ct);
			for (short i = 0; i < str1ct; i++)
			{
				*(arr1 + i) = (int*)malloc(sizeof(int) * clmct);
				for (short j = 0; j < clmct; j++)
				{
					printf_s("������� �������[%hi][%hi]: ", i + 1, j + 1);
					scanf_s("%d", *(arr1 + i) + j );
				}
			}
			printf_s("\n���� ��������!\n��� ����������� ������� ������� Enter");
			rewind(stdin);
			getchar();
			break;
		case '2': //����� �������� �������
			system("cls");
			if (isarr1)
			{
				printf_s("==�������� �������==\n");
				for (short i = 0; i < str1ct; i++)
				{
					for (short j = 0; j < clmct; j++)
						printf_s("%5d", *(*(arr1 + i) + j));
					printf_s("\n");
				}
			}
			else
				printf_s("������! ������� ������� �������");
			printf_s("\n��� ����������� ������� ������� Enter");
			rewind(stdin);
			getchar();
			break;
		case '3': //��������� �������� �������
			if (arr2 != NULL)
			{
				for (short i = 0; i < str2ct; i++)
					free(*(arr2 + i));
				free(arr2);
				arr2 = NULL;
			}
			system("cls");
			if (isarr1)
			{
				isarr2 = 1;
				str2ct = 0;
				for (short i = 0; i < str1ct; i++)
				{
					ismatch = 0;
					for (short j = 0; j < clmct - 1 && !ismatch; j++)
						for (short k = j + 1; k < clmct && !ismatch; k++)
							if (*(*(arr1 + i) + j) == *(*(arr1 + i) + k))
								ismatch = 1;
					if (ismatch)
					{
						arr2 = (int**)realloc(arr2, sizeof(int*) * (str2ct + 1));
						*(arr2 + str2ct) = (int*)malloc(sizeof(int) * clmct);
						for (short j = 0; j < clmct; j++)
							*(*(arr2 + str2ct) + j) = *(*(arr1 + i) + j);
						str2ct++;
					}
				}
				printf_s("�������������� ������� ������������");
			}
			else
				printf_s("������! ������� ������� �������");
			printf_s("\n��� ����������� ������� ������� Enter");
			rewind(stdin);
			getchar();
			break;
		case '4': //����� �������������� �������
			system("cls");
			if (isarr2)
			{
				if (str2ct)
				{
					printf_s("==�������������� �������==\n");
					for (short i = 0; i < str2ct; i++)
					{
						for (short j = 0; j < clmct; j++)
							printf_s("%5d", *(*(arr2 + i) + j));
						printf_s("\n");
					}
				}
				else
					printf_s("� �������������� ������� ��� �� ����� ������.\n");
			}
			else
				printf_s("������! ������� ����������� �������� �������");
			printf_s("\n��� ����������� ������� ������� Enter");
			rewind(stdin);
			getchar();
			break;
		case '5': //�������
			system("cls");
			printf_s("==�������==\n�������������� ������� ����������� �� ����� �����, � ������� ���� ����������� ��������.\n\n��� ����������� ������� ������� Enter");
			rewind(stdin);
			getchar();
			break;
		case '6': //�����
			system("cls");
			printf_s("�� �������, ��� ������ �����?(1-��/0-���): ");
			scanf_s("%hi", &isprogend);
			rewind(stdin);
			break;
		default:
			printf_s("������! ������� ������������ ����� ����\n\n");
			rewind(stdin);
			getchar();
		}
	} while (!isprogend);
	//
	if (arr1 != NULL)
	{
		for (short i = 0; i < str1ct; i++)
			free(*(arr1 + i));
		free(arr1);
		arr1 = NULL;
	}
	if (arr2 != NULL)
	{
		for (short i = 0; i < str2ct; i++)
			free(*(arr2 + i));
		free(arr2);
		arr2 = NULL;
	}
	return 0;
}
