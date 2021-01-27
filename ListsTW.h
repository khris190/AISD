#pragma once
#include <iostream>

using namespace std;

struct elem
{
	int data;
	elem* prev;
	elem* next;
};

void insert(int x, int i, elem*& head)
{
	elem* newElem = new elem;
	newElem->data = x;
	elem* element = head;
	if (i == 1)
	{
		newElem->next = element;
		head = newElem;
	}
	else
	{
		for (int j = 2; j < i; j++)
		{
			element = element->next;
		}

		newElem->next = element->next;
		element->next = newElem;
	}
}

void remove(elem*& head)
{
	elem* temp = head;
	head = head->next;

	if (head != NULL)
		head->prev = NULL;

	delete temp;
}


void print(elem* head)
{
	int counter = 0;
	for (; head; head = head->next)
	{
		cout << head->data << " ";
		counter++;
		if (counter > 10)
			break;
	}
	cout << endl;
}

void reverse(elem*& head)
{
	elem* wart = head;
	while (wart)
	{
		elem* war2 = wart->next;
		wart->next = wart->prev;
		wart->prev = war2;
		if (wart->prev == NULL)
			head = wart;

		wart = wart->prev;
	}
}

void to_cyclic(elem* head)
{
	elem* wskaznik = head;

	while (wskaznik->next != NULL)
		wskaznik = wskaznik->next;

	wskaznik->next = head;
}

void reverse_cyclic(elem* head)
{
	elem* wart = head;
	head = head->next;
	elem* war2 = head->next;
	while (wart != war2)
	{
		head->next = wart;
		wart = head;
		head = war2;
		war2 = head->next;
	}
}

bool is_valid_pn(elem* head)
{
	if (head == NULL)
		return false;


	int operands = 0;
	while (head != NULL)
	{
		if (head->data == '+' || head->data == '-' || head->data == '*' || head->data == '/')
		{
			operands--;
			if (operands < 1)
			{
				return false;
			}
		}
		else if (head->data >= 97 && head->data <= 122)
			operands++;

		else
			return false;


		head = head->next;
	}

	return operands == 1;
}