// CirclularLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;


class Node
{
public:
    int data;
    Node* next;
}*head;

void create(int A[], int n)
{
    int i;
    struct Node* t, * last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }

}

void Display(Node* h)
{
    do {
        if (h->next == head)
        {
            cout << h->data;
        }
        else
        {
            cout << h->data << "->";
        }
        h = h->next;
    } while (h != head);
    cout << endl;
}

void Rdisplay(Node* h)
{
    static int flag = 0;
    if (h != head || flag == 0)
    {
        flag = 1;
        if (h->next == head)
        {
            cout << h->data;
        }
        else
        {
            cout << h->data << "->";
        }
        Rdisplay(h->next);
    }
    flag = 0;
}

int length(Node* p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void Insert(Node* p,int index, int x)
{
    Node* t;

    if (index<0 || index>length(p))
    {
        cout << "\ninvalid index\n";
        return;
    }
    
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = t;
        t->next = head;
        head = t;
    }
    else
    {
        t = new Node;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(Node* p, int index)
{
    Node* q;
    int x;
    if (index<0 || index>length(p))
    {
        cout << "\ninvalid index\n";
        return -1;
    }
    if (index == 1)
    {
        while (p->next != head) p = p->next;
        x = head->data;
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            p=p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
        return x;
    }
}

int main()
{
    std::cout << "Circular Linked List!\n";

    int A[] = { 2,3,4,5,6 };
    create(A, 5);
    Display(head);
    cout << "\nRecursive Display\n";
    Rdisplay(head);
    cout << "\nInserting 10 at pos 2" << endl;
    Insert(head, 2, 10);
    Display(head);
    cout << "\nDeleting 10 at pos 3 " << endl;
    //cout << "YSOOASDJAO";
    Delete(head,3);
    Display(head);



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
