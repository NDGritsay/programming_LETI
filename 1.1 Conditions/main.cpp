#include "stdafx.h"
#include "iostream"
#include "Windows.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float x, y, k, R;
	short newcoefficient, newcoordinates, result;

	//������� ����
	do
	{
		printf_s("������� k: ");
		scanf_s("%f", &k);
		printf_s("������� R: ");
		do
		{
			scanf_s("%f", &R);
			if (R < 0)
				printf("R �� ����� ���� �������������.\n��������� ���� R: ");
		} while (R < 0);
		do
		{
			printf_s("������� x: ");
			scanf_s("%f", &x);
			printf_s("������� y: ");
			scanf_s("%f", &y);
			system("cls");
			result = 0;
			//����� �����������
			printf_s("����������� k = %.2f , R = %.2f\n���������� ����� = ( %.2f ; %.2f )\n", k, R, x, y);
			//�������
			if ((x*x + y*y < R*R) && (((y > k*x) && (x > 0)) || ((y < k*x) && (x < 0))))
				result = 1;
			else
				if (((x*x + y*y <= R*R)) && ((y == k*x) || (y == 0)) || ((x*x + y*y) == R*R) && (((x >= 0) && (y >= k*x)) || ((x < 0) && (y <= k*x))))
					result = 2;
			//�����
			if (result == 1)
				printf_s("\n����� ����� � �������.\n");
			else
				if (result == 2)
					printf_s("\n����� ����� �� �������.\n");
				else
					printf_s("\n����� ����� ��� �������.\n");
			//
			printf_s("\n�������� ���������� �����?(��-1/���-0): ");
			scanf_s("%hi", &newcoordinates);
		} while (newcoordinates);
		//
		printf_s("\n�������� ������������ ���������?(��-1/���-0): ");
		scanf_s("%hi", &newcoefficient);
	} while (newcoefficient);
	return 0;
}
