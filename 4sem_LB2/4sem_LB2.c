#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct stack
{
	float elem[100];
	int top;	//индекс верхнего элемента
};

void add(struct stack* stk, float f)	//помещение элемента в стек
{
	if (stk->top < 100)
	{
		stk->elem[stk->top] = f;
		stk->top++;
	}
	else
	{
		printf("Стек полон, количество элементов: %d!\n", stk->top);
	}
}

float del(struct stack* stk)	//удаление элемента из стека
{
	float elem;
	if ((stk->top) > 0)
	{
		stk->top--;
		elem = stk->elem[stk->top];
		return elem;
	}
	else
	{
		printf("Стек пуст!\n");
		return 0;
	}
}

int Stget(struct stack* stk)		//получение количества элементов стека
{
	return stk->top;
}

int findnull(struct stack* stk)	//определение, пуст ли стек
{
	if (stk->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

float Sttop(struct stack* stk)	//верхний элемент стека
{
	if ((stk->top) > 0)
	{
		return stk->elem[stk->top - 1];
	}
	else
	{
		printf("Стек пуст!\n");
		return 0;
	}
}

void Stprint(struct stack* stk)	//вывод элементов стека
{
	int i;
	i = stk->top; // i - количество элементов в стеке
	if (findnull(stk) == 1)
	{
		return; // стек пуст
	}
	do {i--; printf("%.2f\n", stk->elem[i]);} while (i > 0);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	struct stack* stk;
	stk = (struct stack*)malloc(sizeof(struct stack));
	stk->top = 0;
	int j, choice;
	while (1)
	{
		printf("\n1 - Добавить элемент в стек.\n2 - Удаление элемента из стека.\n3 - Заполненость стека.\n4 - Верхний элемент стека.\n0 - Выход\nВаш выбор: ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			printf("\n\nВведите элемент: ");
			scanf_s("%d", &j);
			add(stk, j);
		}
		if (choice == 2)
		{
			printf("\n\nУдаление элемента %.2f, ", del(stk));
			printf("В стеке %d элементов\n\n", Stget(stk));
		}
		if (choice == 3)
		{
			printf("\n\nВ стеке %d элементов\n", Stget(stk));
			printf("\nВывод элементов стека:\n");
			Stprint(stk);
			printf("\n");
		}
		if (choice == 4)
		{
			printf("\n\nВерхний элемент стека - %.2f", Sttop(stk));
			printf("\n");
		}
		if (choice == 0)
		{
			break;
		}
	}
}
