#include "stdio.h"
#include "malloc.h"
#include "Windows.h"
#include "NDGstrings.h"

//����� ���� �� ����� � ������� ���������� ������������� ������
char menu();
//������������ �� �����
void reference();
////��������, �������� �� ������ ������������
//short isseparator(char c);
////���� ������ � ������� ��������� �� ������ ������ ������
//char *getstr();
////����� ������ � ������� �� �����
//char putstring(char *str);
////������������ ������ ������������ ���������
////������� �������, ���������� �������������, � ������ ��������� �������
//char _getchar();
//void *dsfree(void *ds);
////���������� �������� ���� �� ����������� �� ����
//void wordsort(short *wordstart, short *wordlen, short wordct);
////������������ �������� ������ � ���� ���� ������
//void findwords(char *str, short **wordstart, short **wordlen, short *wordct);
////������������ �������������� ������ �� �������� ����� � ���� ���� �� �������� ������
//char *wordtostr(char *str1, short *wordstart, short *wordlen, short wordct);

int main()
{
	char *str1 = NULL, *str2 = NULL;
	short *wordstart = NULL, *wordlen = NULL, wordct, isprogend = 0, isstr1 = 0, isstr2 = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("title = 1.6 ���������� ���� � ������");

	do
	{
		system("cls");
		switch (menu())
		{
		case '1': //���� ������
			if (str1 != NULL)
				str1 = (char*)dsfree(str1);
			isstr1 = 1;
			isstr2 = 0;
			system("cls");
			printf_s("������� ������:\n");
			rewind(stdin);
			str1 = getstr();
			if (strlength(str1) == STR_MAX_LEN)
				printf_s("\n����� ������ �������� ������. ");
			printf_s("\n���� ��������.\n");
			waitforenter();
			break;
		case '2': //����� �������� ������
			system("cls");
			if (isstr1)
			{
				if (strlength(str1))
				{
					printf_s("�������� ������:\n");
					putstring(str1);
				}
				else
					printf_s("� �������� ������ ��� ��������");
			}
			else
				printf_s("������! ������� ������� ������");
			printf_s("\n");
			waitforenter();
			break;
		case '3': //��������� �������� ������
			system("cls");
			if (isstr1)
			{
				if (!isstr2)
				{
					if (str2 != NULL)
						str2 = (char*)dsfree(str2);
					if (wordstart != NULL)
						wordstart = (short*)dsfree(wordstart);
					if (wordlen != NULL)
						wordlen = (short*)dsfree(wordlen);
					isstr2 = 1;
					findwords(str1, &wordstart, &wordlen, &wordct);
					wordsort(wordstart, wordlen, wordct);
					str2 = wordtostr(str1, wordstart, wordlen, wordct);
					printf_s("������ ����������");
				}
				else
					printf_s("������ ��� ����������!");
			}
			else
				printf_s("������! ������� ������� �������� ������");
			printf_s("\n");
			waitforenter();
			break;
		case '4': //����� ����
			system("cls");
			if (isstr2)
			{
				if (wordct)
				{
					printf_s("�������������� ������:\n");
					putstring(str2);
				}
				else
					printf_s("� ������ ��� �� ������ �����");
			}
			else
				printf_s("������! ������� ����������� ������");
			printf_s("\n");
			waitforenter();
			break;
		case '5': //�������
			system("cls");
			reference();
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
			rewind(stdin);
			waitforenter();
		}
	} while (!isprogend);
	if (str1 != NULL)
		str1 = (char*)dsfree(str1);
	if (str2 != NULL)
		str2 = (char*)dsfree(str2);
	if (wordstart != NULL)
		wordstart = (short*)dsfree(wordstart);
	if (wordlen != NULL)
		wordlen = (short*)dsfree(wordlen);
	return 0;
}

//��������: ����� ���� �� �����
//�������: ������, ��������� �������������

char menu()
{
	printf_s("==����==\n");
	printf_s("1 - ���� ������\n");
	printf_s("2 - ����� �������� ������\n");
	printf_s("3 - ��������� �������� ������\n");
	printf_s("4 - ����� ����\n");
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
	printf_s("-����� ������ ����������� �� ���������� �� ����\n");
	printf_s("-����� ������ �� ��������� %d\n", STR_MAX_LEN);
	printf_s("-������������� �������� ��������� �������:  \"\\n.,;:\'\"\\t!?(){}[]/|\\<>-_\"\n");
}