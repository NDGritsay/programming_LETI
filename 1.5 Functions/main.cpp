#include "stdio.h"
#include "Windows.h"
#include "conio.h"

//вывод на экран меню и возврат выбранного пользователем пункта
char menu();
//ввод матрицы и возврат указателя на адрес ее первого элемента
int **matrixi(short *strct, short *clmct);
//Формирование результирующей матрицы и возврат указателя на адрес ее первого элемента
int **resmatrix(int **arr1, short str1ct, short clmct, short *str2ct);
//вывод на экран матрицы
void matrixo(int **arr, short strct, short clmct);
//вывод на экран справки
void reference();
//освобождение памяти динамической структуры и возврат NULL
int **dsfree(int **arr, short strct);
//проверка наличия совпадающих элементов массива
bool ismatch(int *arr, short strlen);
//добавление новой строки результирующей матрицы
int **addcopystr(int **arr2, int *arr1, short *strct, short clmct);
void NDGlogo(char str[59]);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int **arr1 = NULL, **arr2 = NULL;
	short clmct, str1ct, str2ct, isarr1 = 0, isarr2 = 0, isprogend = 0;

	NDGlogo("ЛАБОРАТОРНАЯ РАБОТА №5    ГРИЦАЙ НИКИТА     ЛЭТИ 2015     ");
	do
	{
		system("title 1.5 Динамическая Матрица");
		system("cls");
		switch (menu())
		{
		case '1': //ввод матрицы
			system("cls");
			printf_s("==Ввод матрицы==\n");
			isarr1 = 1;
			isarr2 = 0;
			if (arr1 != NULL)
				arr1 = dsfree(arr1, str1ct);
			if (arr2 != NULL)
				arr2 = dsfree(arr2, str2ct);
			arr1 = matrixi(&str1ct, &clmct);
			printf_s("\nВвод завершен!\nДля продолжения нажмите клавишу Enter");
			rewind(stdin);
			getchar();
			break;
		case '2': //вывод исходной матрицы
			system("cls");
			if (isarr1)
			{
				printf_s("==Исходная матрица==\n");
				matrixo(arr1, str1ct, clmct);
			}
			else
				printf_s("Ошибка! Сначала введите матрицу");
			printf_s("\nДля продолжения нажмите клавишу Enter");
			rewind(stdin);
			getchar();
			break;
		case '3': //обработка исходной матрицы
			system("cls");
			if (isarr1)
			{
				if (!isarr2)
				{
					isarr2 = 1;
					arr2 = resmatrix(arr1, str1ct, clmct, &str2ct);
				}
				else
					printf_s("Матрица уже обработана!");
			}
			else
				printf_s("Ошибка! Сначала введите матрицу");
			printf_s("\nДля продолжения нажмите клавишу Enter");
			rewind(stdin);
			getchar();
			break;
		case '4': //вывод результирующей матрицы
			system("cls");
			if (isarr2)
			{
				if (str2ct)
				{
					printf_s("==Результирующая матрица==\n");
					matrixo(arr2, str2ct, clmct);
				}
				else
					printf_s("В результирующей матрице нет ни одной строки.\n");
			}
			else
				printf_s("Ошибка! Сначала обработайте исходную матрицу");
			printf_s("\nДля продолжения нажмите клавишу Enter");
			rewind(stdin);
			getchar();
			break;
		case '5': //справка
			system("cls");
			reference();
			rewind(stdin);
			getchar();
			break;
		case '6': //выход
			system("cls");
			printf_s("Вы уверены, что хотите выйти?(1-Да/0-Нет): ");
			scanf_s("%hi", &isprogend);
			rewind(stdin);
			break;
		default:
			printf_s("Ошибка! Введите существующий пункт меню\n\n");
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

//Описание: вывод меню на экран
//Возврат: символ, введенный пользователем

char menu()
{
	printf_s("==Меню==\n");
	printf_s("1.Ввод матрицы.\n");
	printf_s("2.Вывод исходной матрицы\n");
	printf_s("3.Обработка исходной матрицы\n");
	printf_s("4.Вывод результирующей матрицы\n");
	printf_s("5.Справка\n");
	printf_s("6.Выход\n");
	printf_s("\nВведите пункт меню: ");
	rewind(stdin);
	return getchar();
}

//Описание: ввод матрицы
//Возврат: указатель на адрес первого элемента матрицы

int **matrixi(short *strct, short *clmct)
{
	int **arr;

	//ввод кол-ва строк
	do
	{
		printf("Введите количество строк исходной матрицы: ");
		scanf_s("%hi", strct);
		if (*strct < 1)
			printf_s("Ошибка! Количество столбцов не может быть меньше 1\n");
	} while (*strct < 1);
	//ввод кол-ва столбцов
	do
	{
		printf("Введите количество столбцов исходной матрицы: ");
		scanf_s("%hi", clmct);
		if (*clmct < 1)
			printf_s("Ошибка! Количество строк не может быть меньше 1\n");
	} while (*clmct < 1);
	//формирование исходной матрицы
	arr = (int**)malloc(sizeof(int*) * *strct);
	for (short i = 0; i < *strct; i++)
	{
		*(arr + i) = (int*)malloc(sizeof(int) * *clmct);
		for (short j = 0; j < *clmct; j++)
		{
			printf_s("Введите элемент[%hi][%hi]: ", i + 1, j + 1);
			scanf_s("%d", *(arr + i) + j);
		}
	}
	return arr;
}

//Описание: вывод матрицы

void matrixo(int **arr, short strct, short clmct)
{
	for (short i = 0; i < strct; i++)
	{
		for (short j = 0; j < clmct; j++)
			printf_s("%5d", *(*(arr + i) + j));
		printf_s("\n");
	}
}

//Описание: вывод справки на экран

void reference()
{
	printf_s("==Справка==\n");
	printf_s("-Результирующая матрица формируется из строк новой, в которых есть совпадающие элементы.\n");
	printf_s("\nДля продолжения нажмите клавишу Enter");
}

//Описание: освобождение памяти двумерной динамической структуры
//Возврат: указатель на адрес динамичекой структуры

int **dsfree(int **arr, short strct)
{
	for (short i = 0; i < strct; i++)
		free(*(arr + i));
	free(arr);
	return NULL;
}

//Описание: формирование результирующей матрицы
//Возврат: указатель на адрес первого элемента результирующей матрицы

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
	printf_s("Результирующая матрица сформирована");
	return arr2;
}

//Описание: проверка на наличие совпадающих элементов в массиве
//Возврат: 1 если есть совпадающие элементы, 0 в противном случае

bool ismatch(int *arr, short strlen)
{
	bool isres = 0;

	for (short j = 0; (j < strlen - 1) && !isres; j++)
		for (short k = j + 1; (k < strlen) && !isres; k++)
			if (*(arr + j) == *(arr + k))
				isres = 1;
	return isres;
}

//Описание: Добавляет в матрицу новую строку и копирует в нее элементы исходной строки
//Возврат: Указатель на адрес первого элемента матрицы

int **addcopystr(int **arr2, int *arr1, short *strct, short clmct)
{
	arr2 = (int**)realloc(arr2, sizeof(int*) * (*strct + 1));
	*(arr2 + *strct) = (int*)malloc(sizeof(int) * clmct);
	for (short j = 0; j < clmct; j++)
		*(*(arr2 + *strct) + j) = *(arr1 + j);
	*strct = *strct + 1;
	return arr2;
}

//Вывод логотипа на экран

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
		printf_s("\n\n\n    Для продолжения нажмите клавишу");
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