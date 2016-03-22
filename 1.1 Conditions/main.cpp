#include "stdafx.h"
#include "iostream"
#include "Windows.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float x, y, k, R;
	short newcoefficient, newcoordinates, result;

	//главный цикл
	do
	{
		printf_s("Введите k: ");
		scanf_s("%f", &k);
		printf_s("Введите R: ");
		do
		{
			scanf_s("%f", &R);
			if (R < 0)
				printf("R не может быть отрицательным.\nПовторите ввод R: ");
		} while (R < 0);
		do
		{
			printf_s("Введите x: ");
			scanf_s("%f", &x);
			printf_s("Введите y: ");
			scanf_s("%f", &y);
			system("cls");
			result = 0;
			//вывод парраметров
			printf_s("коэффициент k = %.2f , R = %.2f\nкоординаты точки = ( %.2f ; %.2f )\n", k, R, x, y);
			//решение
			if ((x*x + y*y < R*R) && (((y > k*x) && (x > 0)) || ((y < k*x) && (x < 0))))
				result = 1;
			else
				if (((x*x + y*y <= R*R)) && ((y == k*x) || (y == 0)) || ((x*x + y*y) == R*R) && (((x >= 0) && (y >= k*x)) || ((x < 0) && (y <= k*x))))
					result = 2;
			//вывод
			if (result == 1)
				printf_s("\nТочка лежит в области.\n");
			else
				if (result == 2)
					printf_s("\nТочка лежит на границе.\n");
				else
					printf_s("\nТочка лежит вне области.\n");
			//
			printf_s("\nИзменить координаты точки?(Да-1/Нет-0): ");
			scanf_s("%hi", &newcoordinates);
		} while (newcoordinates);
		//
		printf_s("\nИзменить коэффициенты уравнения?(Да-1/Нет-0): ");
		scanf_s("%hi", &newcoefficient);
	} while (newcoefficient);
	return 0;
}
