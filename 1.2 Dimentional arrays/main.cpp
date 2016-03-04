#include "stdafx.h"
#include "iostream"
#include "Windows.h"

#define ARRAYMAXSIZE 100

int main()
{
	short isnewarray, isnewsort, sorttype, length, i, j;
	int oldarray[ARRAYMAXSIZE], newarray[ARRAYMAXSIZE], k;
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	do
	{
		system("cls");
		//���� �������
		printf_s("������� ������ �������: ");
		do
		{
			scanf_s("%hi", &length);
			if ((length > ARRAYMAXSIZE) || (length < 1))
				printf_s("������! ������ ������� �� ����� ���� ������ ������� � ������ %d.\n������� ������ ������� ��� ���: ", ARRAYMAXSIZE);
		} while ((length > ARRAYMAXSIZE) || (length < 1));
		printf_s("\n���� ��������� �������\n");
		for (i = 0; i < length; i++)
		{
			printf_s("������� %hi-� ������� �������: ", i+1);
			scanf_s("%i", oldarray+i);
		}
		printf_s("\n���� ��������\n");
		//
		do
		{
			printf("�������� ��� ��������� ��������� �������(�� �������� - 1/�� ����������� - 2): ");
			do
			{
				scanf_s("%hi", &sorttype);
				if ((sorttype != 1 ) && (sorttype != 2))
					printf_s("������! ������� ������������ ��� ���������: ");
			} while ((sorttype != 1) && (sorttype != 2));
			//����������� ��������
			for (i = 0; i < length; i++)
				newarray[i] = oldarray[i];
			//
			if (sorttype == 1)
			{
				//��������� ������� �� ��������
				j = 0;
				for (i = 0; i < length; i++)
					if (!(newarray[i] & 1))
					{
						k = newarray[i];
						newarray[i] = newarray[j];
						newarray[j] = k;
						j++;
					}
			}
			else
			{
				//��������� ������� �� �����������
				for (i = length - 1; i > 0; i--)
					for (j = 0; j < i; j++)
						if (newarray[j] > newarray[j + 1])
						{
							k = newarray[j];
							newarray[j] = newarray[j + 1];
							newarray[j + 1] = k;
						}
			}
			//����� ��������� �������
			printf_s("\n�������� ������:\n");
			for (i = 0; i < length; i++)
				printf_s("%5i ", oldarray[i]);
			printf_s("\n");
			//����� ������������� �������
			printf_s("\n������������ ������:\n");
			for (i = 0; i < length; i++)
				printf_s("%5i ", newarray[i]);
			printf_s("\n");
			//
			printf_s("\n��������� ������ ��� ����������?(��-1/���-0): ");
			scanf_s("%hi", &isnewsort);
		} while (isnewsort);
		printf_s("������ ����� ������?(��-1/���-0): ");
		scanf_s("%hi", &isnewarray);
	} while (isnewarray);
    return 0;
}

