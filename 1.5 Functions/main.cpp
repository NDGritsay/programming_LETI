#include "stdio.h"
#include "Windows.h"
#include "conio.h"

//����� �� ����� ���� � ������� ���������� ������������� ������
char menu();
//���� ������� � ������� ��������� �� ����� �� ������� ��������
int **matrixi(short *strct, short *clmct);
//������������ �������������� ������� � ������� ��������� �� ����� �� ������� ��������
int **resmatrix(int **arr1, short str1ct, short clmct, short *str2ct);
//����� �� ����� �������
void matrixo(int **arr, short strct, short clmct);
//����� �� ����� �������
void reference();
//������������ ������ ������������ ��������� � ������� NULL
int **dsfree(int **arr, short strct);
//�������� ������� ����������� ��������� �������
bool ismatch(int *arr, short strlen);
//���������� ����� ������ �������������� �������
int **addcopystr(int **arr2, int *arr1, short *strct, short clmct);
void NDGlogo(char str[59]);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int **arr1 = NULL, **arr2 = NULL;
	short clmct, str1ct, str2ct, isarr1 = 0, isarr2 = 0, isprogend = 0;

	NDGlogo("������������ ������ �5    ������ ������     ���� 2015     ");
	do
	{
		system("title 1.5 ������������ �������");
		system("cls");
		switch (menu())
		{
		case '1': //���� �������
			system("cls");
			printf_s("==���� �������==\n");
			isarr1 = 1;
			isarr2 = 0;
			if (arr1 != NULL)
				arr1 = dsfree(arr1, str1ct);
			if (arr2 != NULL)
				arr2 = dsfree(arr2, str2ct);
			arr1 = matrixi(&str1ct, &clmct);
			printf_s("\n���� ��������!\n��� ����������� ������� ������� Enter");
			rewind(stdin);
			getchar();
			break;
		case '2': //����� �������� �������
			system("cls");
			if (isarr1)
			{
				printf_s("==�������� �������==\n");
				matrixo(arr1, str1ct, clmct);
			}
			else
				printf_s("������! ������� ������� �������");
			printf_s("\n��� ����������� ������� ������� Enter");
			rewind(stdin);
			getchar();
			break;
		case '3': //��������� �������� �������
			system("cls");
			if (isarr1)
			{
				if (!isarr2)
				{
					isarr2 = 1;
					arr2 = resmatrix(arr1, str1ct, clmct, &str2ct);
				}
				else
					printf_s("������� ��� ����������!");
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
					matrixo(arr2, str2ct, clmct);
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
			reference();
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
	if(arr1 != NULL)
		arr1 = dsfree(arr1, str1ct);
	if(arr2 != NULL)
		arr2 = dsfree(arr2, str2ct);
	return 0;
}

//��������: ����� ���� �� �����
//�������: ������, ��������� �������������

char menu()
{
	printf_s("==����==\n");
	printf_s("1.���� �������.\n");
	printf_s("2.����� �������� �������\n");
	printf_s("3.��������� �������� �������\n");
	printf_s("4.����� �������������� �������\n");
	printf_s("5.�������\n");
	printf_s("6.�����\n");
	printf_s("\n������� ����� ����: ");
	rewind(stdin);
	return getchar();
}

//��������: ���� �������
//�������: ��������� �� ����� ������� �������� �������

int **matrixi(short *strct, short *clmct)
{
	int **arr;

	//���� ���-�� �����
	do
	{
		printf("������� ���������� ����� �������� �������: ");
		scanf_s("%hi", strct);
		if (*strct < 1)
			printf_s("������! ���������� �������� �� ����� ���� ������ 1\n");
	} while (*strct < 1);
	//���� ���-�� ��������
	do
	{
		printf("������� ���������� �������� �������� �������: ");
		scanf_s("%hi", clmct);
		if (*clmct < 1)
			printf_s("������! ���������� ����� �� ����� ���� ������ 1\n");
	} while (*clmct < 1);
	//������������ �������� �������
	arr = (int**)malloc(sizeof(int*) * *strct);
	for (short i = 0; i < *strct; i++)
	{
		*(arr + i) = (int*)malloc(sizeof(int) * *clmct);
		for (short j = 0; j < *clmct; j++)
		{
			printf_s("������� �������[%hi][%hi]: ", i + 1, j + 1);
			scanf_s("%d", *(arr + i) + j);
		}
	}
	return arr;
}

//��������: ����� �������

void matrixo(int **arr, short strct, short clmct)
{
	for (short i = 0; i < strct; i++)
	{
		for (short j = 0; j < clmct; j++)
			printf_s("%5d", *(*(arr + i) + j));
		printf_s("\n");
	}
}

//��������: ����� ������� �� �����

void reference()
{
	printf_s("==�������==\n");
	printf_s("-�������������� ������� ����������� �� ����� �����, � ������� ���� ����������� ��������.\n");
	printf_s("\n��� ����������� ������� ������� Enter");
}

//��������: ������������ ������ ��������� ������������ ���������
//�������: ��������� �� ����� ����������� ���������

int **dsfree(int **arr, short strct)
{
	for (short i = 0; i < strct; i++)
		free(*(arr + i));
	free(arr);
	return NULL;
}

//��������: ������������ �������������� �������
//�������: ��������� �� ����� ������� �������� �������������� �������

int **resmatrix(int **arr1, short str1ct, short clmct, short *str2ct)
{
	int **arr2 = NULL;

	*str2ct = 0;
	for (short i = 0; i < str1ct; i++)
	{
		if (ismatch(*(arr1 + i), clmct))
		{
			arr2 = addcopystr(arr2, *(arr1 + i), str2ct, clmct);
		}
	}
	printf_s("�������������� ������� ������������");
	return arr2;
}

//��������: �������� �� ������� ����������� ��������� � �������
//�������: 1 ���� ���� ����������� ��������, 0 � ��������� ������

bool ismatch(int *arr, short strlen)
{
	bool isres = 0;

	for (short j = 0; (j < strlen - 1) && !isres; j++)
		for (short k = j + 1; (k < strlen) && !isres; k++)
			if (*(arr + j) == *(arr + k))
				isres = 1;
	return isres;
}

//��������: ��������� � ������� ����� ������ � �������� � ��� �������� �������� ������
//�������: ��������� �� ����� ������� �������� �������

int **addcopystr(int **arr2, int *arr1, short *strct, short clmct)
{
	arr2 = (int**)realloc(arr2, sizeof(int*) * (*strct + 1));
	*(arr2 + *strct) = (int*)malloc(sizeof(int) * clmct);
	for (short j = 0; j < clmct; j++)
		*(*(arr2 + *strct) + j) = *(arr1 + j);
	*strct = *strct + 1;
	return arr2;
}

//����� �������� �� �����

void NDGlogo(char strin[59])
{
	char str[59];
	for (short i = 0; i < 59; i++)
		str[i] = strin[i];
	//
	do
	{
		system("cls");
		for (int i = 0; i < 39; i++)
			printf_s("%c", str[i]);
		printf_s("\n");
		printf_s("%c                                     %c\n", str[58], str[39]);
		printf_s("%c   ki     ni     ichd       itsa     %c\n", str[57], str[40]);
		printf_s("%c   nita   ta     ev  mi    gr        %c\n", str[56], str[41]);
		printf_s("%c   ta ni  ki     ri  tr   ay   gri   %c\n", str[55], str[42]);
		printf_s("%c   ki   kini     it  ie    ts   ts   %c\n", str[54], str[43]);
		printf_s("%c   ni     ta     dmvi       igray    %c\n", str[53], str[44]);
		printf_s("%c                                     %c\n", str[52], str[45]);
		printf_s("=======================================");
		printf_s("\n\n\n    ��� ����������� ������� �������");
		//
		for (short j = 1; j < 59; j++)
		{
			char c = str[j];
			str[j] = str[j - 1];
			str[j - 1] = c;
		}
		Sleep(200);
	} while (!_kbhit());
	_getch();
}