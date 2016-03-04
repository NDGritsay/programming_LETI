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
		//Ввод массива
		printf_s("Введите размер массива: ");
		do
		{
			scanf_s("%hi", &length);
			if ((length > ARRAYMAXSIZE) || (length < 1))
				printf_s("Ошибка! Размер массива не может быть меньше единицы и больше %d.\nВведите размер массива еще раз: ", ARRAYMAXSIZE);
		} while ((length > ARRAYMAXSIZE) || (length < 1));
		printf_s("\nВвод элементов массива\n");
		for (i = 0; i < length; i++)
		{
			printf_s("Введите %hi-й элемент массива: ", i+1);
			scanf_s("%i", oldarray+i);
		}
		printf_s("\nВвод завершен\n");
		//
		do
		{
			printf("Выберите тип обработки исходного массива(По четности - 1/По возрастанию - 2): ");
			do
			{
				scanf_s("%hi", &sorttype);
				if ((sorttype != 1 ) && (sorttype != 2))
					printf_s("Ошибка! Введите существующий тип обработки: ");
			} while ((sorttype != 1) && (sorttype != 2));
			//копирование массивов
			for (i = 0; i < length; i++)
				newarray[i] = oldarray[i];
			//
			if (sorttype == 1)
			{
				//обработка массива по четности
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
				//обработка массива по возрастанию
				for (i = length - 1; i > 0; i--)
					for (j = 0; j < i; j++)
						if (newarray[j] > newarray[j + 1])
						{
							k = newarray[j];
							newarray[j] = newarray[j + 1];
							newarray[j + 1] = k;
						}
			}
			//Вывод исходного массива
			printf_s("\nИсходный массив:\n");
			for (i = 0; i < length; i++)
				printf_s("%5i ", oldarray[i]);
			printf_s("\n");
			//Вывод обработанного массива
			printf_s("\nОбработанный массив:\n");
			for (i = 0; i < length; i++)
				printf_s("%5i ", newarray[i]);
			printf_s("\n");
			//
			printf_s("\nПрименить другой тип сортировки?(Да-1/Нет-0): ");
			scanf_s("%hi", &isnewsort);
		} while (isnewsort);
		printf_s("Ввести новый массив?(Да-1/Нет-0): ");
		scanf_s("%hi", &isnewarray);
	} while (isnewarray);
    return 0;
}

