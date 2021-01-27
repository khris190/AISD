#pragma once
#include <iostream>
#include <stack>

using namespace std;

struct elem
{
	int data;
	elem* next;
};

void insert(int x, int i, elem*& a)
{
    elem* temp;
    if (i == 0)
    {   

        temp = new elem{ a->data,a->next };
        a->data = x;
        a->next = temp;
    }
    else
    {
        elem* newElem = a;
        for (int j = 0; j < i - 1; ++j)
            newElem = newElem->next;

        temp = new elem{ x, newElem->next };
        newElem->next = temp;
    }
}

void remove(elem*& head, int i)
{
    if (i == 1)
    {
        elem* element = head;
        head = head->next;
        delete element;
    }
    else
    {
        elem* tmp = head;
        int j = 0;
        while (j != (i - 2))
        {
            tmp = tmp->next;
            j++;
        }

        elem* element = tmp->next;
        tmp->next = element->next;
        delete element;
    }

}

void read(int i, elem* head)
{
    int a = 0;
    while (head)
    {
        if (a == i)
            cout << head->data;

        a++;
        head = head->next;
    }
}


void print(elem* head)
{

    for (; head; head = head->next)
        cout << head->data << " ";

    cout << endl;
}

void zad1(elem* &head)
{
    insert(5, 0, head);
    insert(3, 1, head);
    insert(1, 2, head);
    insert(4, 1, head);
    insert(5, 4, head);
    print(head);
    remove(head, 1);
    print(head);
    read(0, head);
    cout << endl;
}

int size(elem* head)
{
    int numOfElements = 0;
    while (head != NULL)
    {
        numOfElements++;
        head = head->next;
    }
    return numOfElements;
}


void zad2(elem* head)
{
    cout << size(head) << endl;
}

void zad3(elem* lista)
{
    print(lista);
}

void odwrotnie(elem* a)
{
    stack <int> stos;
    elem* pElement = a;

    while (pElement != NULL)
    {
        stos.push(pElement->data);
        pElement = pElement->next;
    }

    while (stos.empty() == false)
    {
        cout << stos.top() << " ";
        stos.pop();
    }
    cout << endl;
}

void zad4(elem* head)
{
    odwrotnie(head);
}

void odwrotnie2(elem* head)
{
    if (head->next)
    {
        odwrotnie2(head->next);
    }
    else
    {
        cout << endl;
    }
    cout << head->data << " ";

}

void zad5(elem* lista)
{
    odwrotnie2(lista);
}

void destroy(elem*& head)
{
    if (head != NULL)
    {
        while (head != NULL)
        {
            elem* stary = head;
            head = head->next;
            delete stary;
        }
    }
}

void zad6(elem* head)
{
    destroy(head);
    print(head);
}

elem* search(int x, elem* head)
{
    while (head != NULL)
    {

        if (head->data == x)
            return head;

        head = head->next;
    }

    return NULL;
}