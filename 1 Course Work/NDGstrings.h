#include "stdio.h"
#include "malloc.h"
#include "conio.h"
#include "Windows.h"

#define STR_MAX_LEN 100

void NDGlogo();
void waitforenter();
short strlength(char *str);
char _getchar();
void putstring(char *str);
void putstrings(char **strings, short strct);
void *dsfree(void *ds);
void **dsfree(void **ds, short index1size);
char *getstr();
short isseparator(char c);
void findwords(char *str, short **wordstart, short **wordlen, short *wordct);
void wordsort(short *wordstart, short *wordlen, short wordct);
char **wordproc(char **txt1, short strct);
char **gettxt(short *strct);
short isstrmatch(char *str, char *regex);

//Описание: вывод логотипа на экран

void NDGlogo()
{
	char str[] = { "КУРСОВАЯ РАБОТА       ГРИЦАЙ НИКИТА       ЛЭТИ 2015       "};
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

//Описание: ввод символа в режиме реального времени
//Возврат: символ, введенный пользователем

void waitforenter()
{
	printf_s("Для продолжения нажмите клавишу Enter");
	rewind(stdin);
	for (; _getch() != '\r';); //'\r' == '\t'
}

//Описание: поиск длинны строки, введенной пользователем
//Возврат: длинна строки, веденной пользователем

short strlength(char *str)
{
	short i;
	for (i = 0; *(str + i) != '\0'; i++);
	return (i);
}

//Описание: ввод символа в режиме раельного времени
//Возврат: символ, введенный пользователем

char _getchar()
{ 
	char c;
	
	c = _getch();
	if (c == '\r')//'\r' == '\n' в функции _getch()
		c = '\n';
	printf_s("%c", c);
	return c;
}

//Описание: вывод строки на экран

void putstring(char *str)
{
	for (short i = 0; *(str + i) != '\0'; i++)
		putchar(*(str + i));
}

//Описание: вывод текста на экран

void putstrings(char **strings, short strct)
{
	short voidstrct = 0;

	for (short i = 0; i < strct; i++)
	{
		putstring(*(strings + i));
		printf_s("\n");
		if (!strlength(*(strings + i)))
			voidstrct++;
	}
	if (voidstrct)
		printf_s("\nПустых строк в тексте: %hi\n", voidstrct);
}

//Описание: освобождение памяти динамической структуры
//Возврат: NULL

void *dsfree(void *ds)
{
	free(ds);
	return NULL;
}
void **dsfree(void **ds, short index1ct)
{
	for (short i = 0; i < index1ct; i++)
		free(*(ds + i));
	free(ds);
	return NULL;
}

//Описание: ввод строки
//Возврат: указатель на первый элемент строки


char *getstr()
{
	char *str = (char*)malloc(sizeof(char));
	short count = 0;
	while (((*(str + count) = _getchar()) != '\n') && (count < STR_MAX_LEN))
	{
		if (*(str + count) == '\b')
		{
			if (count)
			{
				printf_s(" \b");
				count--;
			}
		}
		else
		{
			count++;
		}
		str = (char*)realloc(str, sizeof(char) * (count + 1));
	}
	*(str + count) = '\0';
	return str;
}

//Описание: проверка, является ли символ разделителем
//Возврат: (1/0)

short isseparator(char c)
{
	char separators[] = { " \n.,;:\'\"\t!?(){}[]/|\\<>-_" };
	bool isres = 0;

	for (short i = 0; (separators[i] != '\0') && !isres; i++)
		if (c == separators[i])
			isres = 1;
	return isres;
}

//Описание: поиск слов в строке

void findwords(char *str, short **wordstart, short **wordlen, short *wordct)
{
	*wordct = 0;

	for (short i = 0; *(str + i) != '\0'; i++)
		if (!isseparator(*(str + i)))
		{
			*wordlen = (short*)realloc(*wordlen, sizeof(short) * ((*wordct) + 1));
			*wordstart = (short*)realloc(*wordstart, sizeof(short) * ((*wordct) + 1));
			*((*wordstart) + *wordct) = i;
			for (; !isseparator(*(str + i)) && (*(str + i) != '\0'); i++);
			*((*wordlen) + *wordct) = (i - *((*wordstart) + *wordct));
			(*wordct)++;
			i--;
		}
}

//Описание: сортировка слов по возрастанию

void wordsort(short *wordstart, short *wordlen, short wordct)
{
	for (short i = 0; i < wordct - 1; i++)
		for (short j = (wordct - 1); j > i; j--)
			if (*(wordlen + j - 1) > *(wordlen + j))
			{
				short t = *(wordlen + j - 1);
				*(wordlen + j - 1) = *(wordlen + j);
				*(wordlen + j) = t;
				t = *(wordstart + j - 1);
				*(wordstart + j - 1) = *(wordstart + j);
				*(wordstart + j) = t;
			}
}


//Описание: формирует строку по заданым началам и длиннам слов исходной строки
//Возврат: указатель на первый символ строки

char *wordtostr(char *str1, short *wordstart, short *wordlen, short wordct)
{
	char *str2 = (char*)malloc(sizeof(char));
	short strlen = 0, i = -1;

	for (short j = 0; j < wordct; j++)
	{
		i++;
		strlen += (*(wordlen + j)) + 1;
		str2 = (char*)realloc(str2, sizeof(char) * strlen);
		for (short k = 0; k < *(wordlen + j); i++, k++)
			*(str2 + i) = *(str1 + (*(wordstart + j)) + k);
		*(str2 + i) = ' ';
	}
	if (wordct)
		*(str2 + i) = '\0';
	else
		*str2 = '\0';
	return str2;
}

//Описание: сортировка слов в строках текста
//Возврат: указатель на адрес первого элемента результирующего текста

char **wordproc(char **txt1, short strct)
{
	char **txt2;
	short *wordstart = NULL, *wordlen = NULL, wordct;

	txt2 = (char**)malloc(sizeof(char*) * strct);
	for (short i = 0; i < strct; i++)
	{
		findwords(*(txt1 + i), &wordstart, &wordlen, &wordct);
		wordsort(wordstart, wordlen, wordct);
		*(txt2 + i) = wordtostr(*(txt1 + i), wordstart, wordlen, wordct);
	}
	return txt2;
}

//Описание: ввод текста
//Возврат: указатель на адрес первого элемента текста

char **gettxt(short *strct)
{
	char **txt, *regex = NULL;
	short isbreak;
	
	//ввод строки конца текста
	system("cls");
	do
	{
		if (regex != NULL)
			dsfree(regex);
		printf_s("Введите строку конца текста: ");
		rewind(stdin);
		regex = getstr();
		if (!strlength(regex))
			printf_s("Ошибка! Строка конца текста должна состоять хотя бы из одного символа\n");
		else
			if (strlength(regex) == STR_MAX_LEN)
			{
				printf_s("\nДлина строки достигла лимита.Ввод прекращен.\n");
				waitforenter();
			}
	} while (!strlength(regex));
	//ввод текста
	do
	{
		isbreak = 0;
		txt = NULL;
		system("cls");
		printf_s("Строка конца текста:\n");
		putstring(regex);
		printf_s("\nВведите текст:\n");
		for (*strct = 0; !isbreak; (*strct)++)
		{
			txt = (char**)realloc(txt, sizeof(char*) * ((*strct) + 1));
			rewind(stdin);
			*(txt + *strct) = getstr();
			isbreak = isstrmatch(*(txt + *strct), regex);
			if ((strlength(*(txt + *strct)) == STR_MAX_LEN) && !isbreak)
				printf_s("\nДлина строки достигла лимита. Ввод прекращен. Введите следующую строку:\n");
		}
		if (!(--(*strct)))
		{
			printf_s("\nОшибка! В тексте должна быть хотя бы одна строка\n");
			waitforenter();
		}
	} while (!(*strct));
	return txt;
}

//Описание: проверка на совпадение двух строк
//Возврат: (1/0)

short isstrmatch(char *str, char *regex)
{
	short isres = 1;
	
	if (strlength(str) == strlength(regex))
	{
		for (short i = 0; (*(str + i) != '\0') && isres; i++)
			if (*(str + i) != *(regex + i))
				isres = 0;
	}
	else
	{
		isres = 0;
	}
	return isres;
}