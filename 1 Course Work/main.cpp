#include "stdio.h"
#include "malloc.h"
#include "Windows.h"
#include "conio.h"

#define STR_MAX_LEN 100

//Вывод меню на экран и возврат символа, введенного пользователем
char menu();
//Вывод справки на экран
void reference();
//Ожидание действия пользователя
void waitforenter();
//Поиск длины строки, введенной пользователем
short strlength(char *str);
//Ввод символа в режиме реального времени, вывод его на экран и возврат его значения
int _getchar();
//Вывод строки на экран
void putstring(char *str);
//Вывод динамической структуры строк на экран
void putstrings(char **strings, short strct);
//Освобождение памяти динамической структуры размерности 1 и возврат NULL
void *dsfree(void *ds);
//Освобождение памяти динамической структуры размерности 2 и возврат NULL
void **dsfree(void **ds, short index1size);
//Ввод строк и возврат указателя на ее первый элемент
char *getstr();
//Возврат 1 в случае, если символ является разделителем и 0 в противном
short isseparator(char c);
//Поиск слов в строке
void findwords(char *str, short **wordstart, short **wordlen, short *wordct);
//Сортировка слов по возрастанию
void wordsort(short *wordstart, short *wordlen, short wordct);
//Формирование строки по заданым началам и длиннам слов исходной строки и возврат указателя на первый символ строки
char *wordtostr(char *str1, short *wordstart, short *wordlen, short wordct);
//Сортировка слов строк текста по возрастанию их длин и возврат указателя на адрес первого элемента результирующего текста
char **wordproc(char **txt1, short strct);
//Ввод текста и возврат указателя на адрес его первого элемента
char **gettxt(short *strct);
//Возврат 1, если строки совпадают и 0 в противном случае
short isstrmatch(char *str, char *regex);

int main()
{
	char **txt1 = NULL, **txt2 = NULL;
	short isprogend = 0, istxt1 = 0, istxt2 = 0, strct;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("title = Курсовая работа. Обработка текста");

	do
	{
		system("cls");
		switch (menu())
		{
		case '1': //ввод текста
			if (txt1 != NULL)
				txt1 = (char**)dsfree((void**)txt1, strct);
			if (txt2 != NULL)
				txt2 = (char**)(dsfree((void**)txt2, strct));
			istxt1 = 1;
			istxt2 = 0;
			system("cls");
			rewind(stdin);
			txt1 = gettxt(&strct);
			printf_s("\nВвод завершен!\n");
			waitforenter();
			break;
		case '2': //вывод исходного текста
			system("cls");
			if (istxt1)
			{
					printf_s("Исходный текст:\n");
					putstrings(txt1, strct);
			}
			else
				printf_s("Ошибка! Сначала введите исходный текст");
			printf_s("\n");
			waitforenter();
			break;
		case '3': //обработка исходного текста
			system("cls");
			if (istxt1)
			{
				if (txt2 == NULL)
				{
					istxt2 = 1;
					txt2 = wordproc(txt1, strct);
					printf_s("Текст обработан");
				}
				else
					printf_s("Текст уже был обработан");
			}
			else
				printf_s("Ошибка! Сначала введите исходный текст");
			printf_s("\n");
			waitforenter();
			break;
		case '4': //вывод текста
			system("cls");
			if (istxt2)
			{
				printf_s("Результирующий текст:\n");
				putstrings(txt2, strct);
			}
			else
				printf_s("Ошибка! Сначала обработайте исходный текст");
			printf_s("\n");
			waitforenter();
			break;
		case '5': //справка
			system("cls");
			reference();
			printf_s("\n");
			waitforenter();
			break;
		case '6': //выход
			system("cls");
			printf_s("Вы уверены, что хотите выйти?(1-Да/0-Нет): ");
			scanf_s("%hi", &isprogend);
			rewind(stdin);
			break;
		default:
			printf_s("Ошибка! Введите существующий пункт меню\n");
			waitforenter();
		}
	} while (!isprogend);
	if (txt1 != NULL)
		txt1 = (char**)dsfree((void**)txt1, strct);
	if (txt1 != NULL)
		txt1 = (char**)dsfree((void**)txt1, strct);
	return 0;
}

//Описание: вывод меню на экран
//Возврат: символ, введенный пользователем

char menu()
{
	printf_s("==Меню==\n");
	printf_s("1 - Ввод текста\n");
	printf_s("2 - Вывод исходного текста\n");
	printf_s("3 - Обработка исходного текста\n");
	printf_s("4 - Вывод результата\n");
	printf_s("5 - Справка\n");
	printf_s("6 - Выход\n");
	printf_s("\nВведите пункт меню: ");
	rewind(stdin);
	return getchar();
}

//Описание: вывод справки на экран

void reference()
{
	printf_s("==Справка==\n");
	printf_s("-Перед тем, как ввести текст, вводится строка конца текста. Строка конца текста не принадлежит тексту\n");
	printf_s("-Длина строк текста и строки конца текста не превышает %d\n", STR_MAX_LEN);
	printf_s("-Исходный текст должен содержать хотя бы одну строку\n");
	printf_s("-Обработанный текс соделржит слова строк исходного, упорядоченные по возрастанию и разделенные пробелом.\n");
	printf_s("-Если в строке текста есть пустые строки, то выводится сообщение о их наличии и количестве\n");
	printf_s("-Разделителями являются следующие символы:  \" \\n.,;:\'\"\t!?(){}[]/|\\<>-_\"");
}