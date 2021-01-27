#pragma once
#include <iostream>

using namespace std;

struct elem
{
	int data;
	elem* next;
};

void push(elem*& stack, int x)
{
	if (stack == NULL)
	{
		stack = new elem;
		stack->data = x;
		stack->next = NULL;
	}
	else
	{
		elem* tmp = new elem;
		tmp->data = x;
		tmp->next = stack;
		stack = tmp;
	}
}

int pop(elem*& stack)
{
	int x = stack->data;
	stack = stack->next;
	return x;
}

int topEl(elem* stack)
{
	int x = stack->data;
	return x;
}

bool isEmpty(elem* stack)
{
	return !stack;
}

void print(elem* stack)
{
	while (stack)
	{
		cout << stack->data << " ";
		stack = stack->next;
	}
	cout << endl;
}

void add(elem*& que_beg, elem*& que_end, int x)
{
	if (que_beg)
	{
		que_end->next = new elem{ x, NULL };
		que_end = que_end->next;
	}
	else
		que_beg = que_end = new elem{ x, NULL };
}

int next(elem*& que_beg, elem*& que_end)
{
	int wartDane = que_beg->data;
	elem* wart = que_beg;
	que_beg = que_beg->next;
	delete wart;
	return wartDane;
}

int firstEl(elem* que_beg)
{
	int wartDane = que_beg->data;
	return wartDane;
}

bool isEmptyKol(elem* que_beg)
{
	return !que_beg;
}

void printKol(elem* que_beg, elem* que_end)
{
	elem* tempElem = que_beg;
	if (que_beg)
	{
		do
		{
			cout << tempElem->data << " ";
			tempElem = tempElem->next;
		} while (tempElem != que_end);
		{
			cout << tempElem->data << " ";
			cout << endl;
		}
	}
	else
		cout << "pusty" << endl;
}

void zad3()
{
	cout << "E A S * Y * Q U E * * * S T * * * I O * N * * *" << endl;
	cout << "stos: S Y E U Q T S A O N I E" << endl;
	cout << "w kolejce: E A S Y Q U E S T I O N" << endl;

}

void zad4()
{
	cout << "na stosie ma byc:A S Y E" << endl;
	cout << "powinien byc ciag: E A * S * Y * * " << endl;

}

void addStos(elem*& stack, int x)
{
	push(stack, x);
}
int nastStos(elem*& stack, elem*& stack2)
{
	if (isEmpty(stack2))
		while (!isEmpty(stack))
			push(stack2, pop(stack));

	return pop(stack2);
}

void addKol(int* arr, int max, int& tail, int x)
{
	tail %= max;
	arr[tail] = x;
	tail++;
}
int nastKol(int* arr, int max, int& head)
{
	int wart = arr[head++];
	head %= max;
	return wart;
}

void reverse_stos(elem*& stack, elem*& stack2)
{
	int x = 0;
	elem* p = NULL;
	while (p != stack)
	{
		x = pop(stack);
		while (stack != p)
			push(stack2, pop(stack));

		push(stack, x);
		p = stack;
		while (stack2 != NULL)
			push(stack, pop(stack2));

	}
}

void reverseKol(elem*& stack)
{
	elem* que_beg1 = NULL;
	elem* que_beg2 = NULL;
	while (!isEmpty(stack))
		add(que_beg1, que_beg2, pop(stack));

	while (!isEmptyKol(que_beg1))
		push(stack, next(que_beg1, que_beg2));
}

void sort(elem*& stack)
{
	elem* temp = NULL;
	int x = 0;
	while (!isEmpty(stack))
	{
		x = pop(stack);
		while (!isEmpty(temp))
		{
			if (topEl(temp) < x) break;
			push(stack, pop(temp));
		}
		push(temp, x);
	}
	stack = temp;
}

void moveStos(elem* stack, elem*& stack2)
{
	elem* temp = NULL;
	while (!isEmpty(stack))
		push(temp, pop(stack));

	while (!isEmpty(temp))
		push(stack2, pop(temp));
}
