// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

using namespace std;


class Node
{
public:
    Node* prev;
    int data;
    Node* next;
}*first=NULL;


void create(int A[], int n)
{
    Node* t;
    Node* last;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(Node* p)
{
    while (p)
    {
        if (p->next == NULL)
        {
            cout << p->data;
        }
        else
        {
            cout << p->data << "->";
        }
        p = p->next;
    }
    cout << endl;
}

int length(Node* p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(Node* p, int index, int x)
{
    Node* t;
    if (index<0 || index>length(p))
    {
        cout << "\nInvalid index";
        return;
    }
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int Delete(Node* p, int index)
{
    Node* q;
    int x = -1;
    if (index<1 || index > length(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
        return x;
    }
}

void reverse(Node* p)
{
    Node* temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p!=NULL && p->next == NULL)
            first = p;
    }
}

int main()
{
    std::cout << "Doubly Linked List!\n";
    int A[] = { 10,20,30,40,50 };
    create(A, 5);
    cout << "\nlength is : " << length(first) << endl;
    Display(first);
    cout << "\nInserting 5 at pos 0" << endl; Insert(first, 0, 5); Display(first);
    cout << "\nInserting 25 at pos 3" << endl; Insert(first, 3, 25); Display(first);
    cout << "\nInserting 60 at pos 7" << endl; Insert(first, 7, 60); Display(first);
    cout << "\nDeleting 5 at pos 1" << endl; Delete(first, 1); Display(first);
    cout << "\nDeleting 25 at pos 3" << endl; Delete(first, 3); Display(first);
    cout << "\nDeleting 60 at pos 6" << endl; Delete(first, 6); Display(first);
    cout << "\nReversing" << endl; reverse(first); Display(first);

    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
