#include "stdio.h"
#include "malloc.h"
#include "Windows.h"
#include "NDGstrings.h"

//вывод меню на экран и возврат выбранного пользователем пункта
char menu();
//выводсправки на экран
void reference();
////проверка, является ли символ разделителем
//short isseparator(char c);
////ввод строки и возврат указателя на первый символ строки
//char *getstr();
////вывод строки и возврат ее длины
//char putstring(char *str);
////освобождение памяти динамической структуры
////возврат символа, введенного пользователем, в режиме реального времени
//char _getchar();
//void *dsfree(void *ds);
////сортировка индексов слов по возрастанию их длин
//void wordsort(short *wordstart, short *wordlen, short wordct);
////формирование структур начала и длин слов строки
//void findwords(char *str, short **wordstart, short **wordlen, short *wordct);
////формирование результирующей строки по индексам начал и длин слов из исходной строки
//char *wordtostr(char *str1, short *wordstart, short *wordlen, short wordct);

int main()
{
	char *str1 = NULL, *str2 = NULL;
	short *wordstart = NULL, *wordlen = NULL, wordct, isprogend = 0, isstr1 = 0, isstr2 = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("title = 1.6 Сортировка слов в строке");

	do
	{
		system("cls");
		switch (menu())
		{
		case '1': //ввод строки
			if (str1 != NULL)
				str1 = (char*)dsfree(str1);
			isstr1 = 1;
			isstr2 = 0;
			system("cls");
			printf_s("Введите строку:\n");
			rewind(stdin);
			str1 = getstr();
			if (strlength(str1) == STR_MAX_LEN)
				printf_s("\nДлина строки достигла лимита. ");
			printf_s("\nВвод завершен.\n");
			waitforenter();
			break;
		case '2': //вывод исходной строки
			system("cls");
			if (isstr1)
			{
				if (strlength(str1))
				{
					printf_s("Исходная строка:\n");
					putstring(str1);
				}
				else
					printf_s("В исходной строке нет символов");
			}
			else
				printf_s("Ошибка! Сначала введите строку");
			printf_s("\n");
			waitforenter();
			break;
		case '3': //обработка исходной строки
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
					printf_s("Строка обработана");
				}
				else
					printf_s("Строка уже обработана!");
			}
			else
				printf_s("Ошибка! Сначала введите исходную строку");
			printf_s("\n");
			waitforenter();
			break;
		case '4': //вывод слов
			system("cls");
			if (isstr2)
			{
				if (wordct)
				{
					printf_s("Результирующая строка:\n");
					putstring(str2);
				}
				else
					printf_s("В строке нет ни одного слова");
			}
			else
				printf_s("Ошибка! Сначала обработайте строку");
			printf_s("\n");
			waitforenter();
			break;
		case '5': //справка
			system("cls");
			reference();
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

//Описание: вывод меню на экран
//Возврат: символ, введенный пользователем

char menu()
{
	printf_s("==Меню==\n");
	printf_s("1 - Ввод строки\n");
	printf_s("2 - Вывод исходной строки\n");
	printf_s("3 - Обработка исходной строки\n");
	printf_s("4 - Вывод слов\n");
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
	printf_s("-Слова строки сортируются по увеличению их длин\n");
	printf_s("-Длина строки не превышает %d\n", STR_MAX_LEN);
	printf_s("-Разделителями являются следующие символы:  \"\\n.,;:\'\"\\t!?(){}[]/|\\<>-_\"\n");
}