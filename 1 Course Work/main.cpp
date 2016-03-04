#include "stdio.h"
#include "malloc.h"
#include "Windows.h"
#include "conio.h"

#define STR_MAX_LEN 100

//����� ���� �� ����� � ������� �������, ���������� �������������
char menu();
//����� ������� �� �����
void reference();
//�������� �������� ������������
void waitforenter();
//����� ����� ������, ��������� �������������
short strlength(char *str);
//���� ������� � ������ ��������� �������, ����� ��� �� ����� � ������� ��� ��������
int _getchar();
//����� ������ �� �����
void putstring(char *str);
//����� ������������ ��������� ����� �� �����
void putstrings(char **strings, short strct);
//������������ ������ ������������ ��������� ����������� 1 � ������� NULL
void *dsfree(void *ds);
//������������ ������ ������������ ��������� ����������� 2 � ������� NULL
void **dsfree(void **ds, short index1size);
//���� ����� � ������� ��������� �� �� ������ �������
char *getstr();
//������� 1 � ������, ���� ������ �������� ������������ � 0 � ���������
short isseparator(char c);
//����� ���� � ������
void findwords(char *str, short **wordstart, short **wordlen, short *wordct);
//���������� ���� �� �����������
void wordsort(short *wordstart, short *wordlen, short wordct);
//������������ ������ �� ������� ������� � ������� ���� �������� ������ � ������� ��������� �� ������ ������ ������
char *wordtostr(char *str1, short *wordstart, short *wordlen, short wordct);
//���������� ���� ����� ������ �� ����������� �� ���� � ������� ��������� �� ����� ������� �������� ��������������� ������
char **wordproc(char **txt1, short strct);
//���� ������ � ������� ��������� �� ����� ��� ������� ��������
char **gettxt(short *strct);
//������� 1, ���� ������ ��������� � 0 � ��������� ������
short isstrmatch(char *str, char *regex);

int main()
{
	char **txt1 = NULL, **txt2 = NULL;
	short isprogend = 0, istxt1 = 0, istxt2 = 0, strct;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("title = �������� ������. ��������� ������");

	do
	{
		system("cls");
		switch (menu())
		{
		case '1': //���� ������
			if (txt1 != NULL)
				txt1 = (char**)dsfree((void**)txt1, strct);
			if (txt2 != NULL)
				txt2 = (char**)(dsfree((void**)txt2, strct));
			istxt1 = 1;
			istxt2 = 0;
			system("cls");
			rewind(stdin);
			txt1 = gettxt(&strct);
			printf_s("\n���� ��������!\n");
			waitforenter();
			break;
		case '2': //����� ��������� ������
			system("cls");
			if (istxt1)
			{
					printf_s("�������� �����:\n");
					putstrings(txt1, strct);
			}
			else
				printf_s("������! ������� ������� �������� �����");
			printf_s("\n");
			waitforenter();
			break;
		case '3': //��������� ��������� ������
			system("cls");
			if (istxt1)
			{
				if (txt2 == NULL)
				{
					istxt2 = 1;
					txt2 = wordproc(txt1, strct);
					printf_s("����� ���������");
				}
				else
					printf_s("����� ��� ��� ���������");
			}
			else
				printf_s("������! ������� ������� �������� �����");
			printf_s("\n");
			waitforenter();
			break;
		case '4': //����� ������
			system("cls");
			if (istxt2)
			{
				printf_s("�������������� �����:\n");
				putstrings(txt2, strct);
			}
			else
				printf_s("������! ������� ����������� �������� �����");
			printf_s("\n");
			waitforenter();
			break;
		case '5': //�������
			system("cls");
			reference();
			printf_s("\n");
			waitforenter();
			break;
		case '6': //�����
			system("cls");
			printf_s("�� �������, ��� ������ �����?(1-��/0-���): ");
			scanf_s("%hi", &isprogend);
			rewind(stdin);
			break;
		default:
			printf_s("������! ������� ������������ ����� ����\n");
			waitforenter();
		}
	} while (!isprogend);
	if (txt1 != NULL)
		txt1 = (char**)dsfree((void**)txt1, strct);
	if (txt1 != NULL)
		txt1 = (char**)dsfree((void**)txt1, strct);
	return 0;
}

//��������: ����� ���� �� �����
//�������: ������, ��������� �������������

char menu()
{
	printf_s("==����==\n");
	printf_s("1 - ���� ������\n");
	printf_s("2 - ����� ��������� ������\n");
	printf_s("3 - ��������� ��������� ������\n");
	printf_s("4 - ����� ����������\n");
	printf_s("5 - �������\n");
	printf_s("6 - �����\n");
	printf_s("\n������� ����� ����: ");
	rewind(stdin);
	return getchar();
}

//��������: ����� ������� �� �����

void reference()
{
	printf_s("==�������==\n");
	printf_s("-����� ���, ��� ������ �����, �������� ������ ����� ������. ������ ����� ������ �� ����������� ������\n");
	printf_s("-����� ����� ������ � ������ ����� ������ �� ��������� %d\n", STR_MAX_LEN);
	printf_s("-�������� ����� ������ ��������� ���� �� ���� ������\n");
	printf_s("-������������ ���� ��������� ����� ����� ���������, ������������� �� ����������� � ����������� ��������.\n");
	printf_s("-���� � ������ ������ ���� ������ ������, �� ��������� ��������� � �� ������� � ����������\n");
	printf_s("-������������� �������� ��������� �������:  \" \\n.,;:\'\"\t!?(){}[]/|\\<>-_\"");
}