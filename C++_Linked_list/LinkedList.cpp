// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
}*first=NULL,*second=NULL,*third=NULL,*fourth=NULL,*fifth = NULL,*sixth=NULL,*seventh = NULL; //global pointer;

void create(int A[], int n)
{
    int i;
    Node* temp;
    Node* last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void create2(int A[], int n)
{
    int i;
    Node* temp;
    Node* last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void create3(int A[], int n)
{
    int i;
    Node* temp;
    Node* last;
    fifth = new Node;
    fifth->data = A[0];
    fifth->next = NULL;
    last = fifth;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}



void display(Node* p)
{
    while (p != NULL)
    {
        if (p->next != NULL)
        {
            cout << p->data << "->";
            p = p->next;
        }
        else
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
}

void recursive_display(Node* p)
{
    if (p != NULL)
    {
        if (p->next != NULL)
        {
            cout << p->data << "->";
            recursive_display(p->next);
        }
        else
        {
            cout << p->data << endl;
            recursive_display(p->next);
        }
    }
}

int count(Node* p)
{
    int l = 0;
    while (p)
    {
        p = p->next;
        l++;
    }
    return l;
}

int rcount(Node* p)
{
    if (p != NULL)
        return rcount(p->next) + 1;
    else
        return 0;
}

int sum(Node* p)
{
    int s = 0;
    while (p)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int rsum(Node* p)
{
    if (p)
        return sum(p->next) + p->data;
    else
        return 0;
}

int max(Node* p)
{
    int m = INT32_MIN;
    while (p)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int rmax(Node* p)
{
    int x;
    if (p == 0)
        return INT32_MIN;
    x = rmax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

Node* search(Node* p, int key)
{
    while (p)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return 0;
}

Node* rsearch(Node* p, int key)
{
    if (!p)
        return NULL;
    if (p->data == key)
        return p;
    return rsearch(p->next, key);
}

void Insert(Node* p, int index, int x)
{
    if (index<0 || index>count(p))
    {
        cout << "Invalid index\n";
        return;
    }
    Node* t;
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void InsertLast(Node* p, int x)
{
    //need last node
}

void SortedInsert(Node* p, int x)
{
    Node* t;
    Node* q;
    q = p;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next; //p
            q->next = t;
        }
    }
}

int isSorted(Node* p)
{
    int x = -999999;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

int Delete(struct Node* p, int index)
{
    Node* q;
    q = p;
    int x = -1;
    if (index<1 || index>count(p))
    {
        return -1;
    }
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }

}

void removeDuplicates(Node* p)
{
    Node* q = p;
    q = q->next;
    while (q)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
}

void Reverse(Node* p)
{
    Node* q = NULL;
    Node* r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;

}

void recursiveReverse(Node* q, Node* p)
{
    if (p)
    {
        recursiveReverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void concat(Node* p, Node* q)
{
    fourth = p;
    while (p->next!=NULL) p = p->next;
    p->next = q;
}

void Merge(Node* p, Node* q)
{
    Node* last;
    if (p->data < q->data)
    {
        third = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = last->next;//last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = last->next; //last =q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

int checkloop(Node* f)
{
    Node* p; Node* q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}


int main()
{
    std::cout << "\nLinked List !\n";
    //int A[] = { 3,5,20,10,15,8,12,7 };
    int A[] = { 10,20,30 };
    create(A, 3);
    display(first);
    cout << "\nrecursive\n";
    recursive_display(first);
    cout << "\nCount of elements :" << count(first) << endl;
    cout << "\nRecursive Count of elements :" << rcount(first) << endl;
    cout << "\nRecursive Sum of elements :" << rsum(first) << endl;
    cout << "\nSum of elements :" << sum(first) << endl;
    cout << "\nMax is : " << max(first) << endl;
    cout << "\nRecursive Max is : " << rmax(first) << endl;

    Node* temp;
    cout << "\nSearching for 20\n";
    temp = search(first, 20);
    if (temp)
        cout << "Key found : " << temp->data << endl;
    else
        cout << "Not found\n";

    cout << "\nRecursive Searching for 15\n";
    temp = rsearch(first, 15);
    if (temp)
        cout << "Key found : " << temp->data << endl;
    else
        cout << "Not found\n";

    cout << "Inserting some elements \n";
    Insert(first, 3, 40);
    Insert(first, 100, 100);
    Insert(first, 4, 50);
    display(first);

    cout << "\nSorted Inserting\n";
    SortedInsert(first, 35);
    SortedInsert(first, 25);
    SortedInsert(first, 55);
    display(first);

    cout << "\nIs sorted : " << isSorted(first) << endl;

    cout << "\nDeleting 40, 6th node : " << Delete(first,6) << endl;
    display(first);

    cout << "\nFor removing duplicates, add 20 and 30, 30\n" << endl;
    SortedInsert(first, 20);
    SortedInsert(first, 30);
    SortedInsert(first, 30);
    display(first);
    removeDuplicates(first);
    display(first);

    cout << "\nReversing : " << endl;
    Reverse(first);
    display(first);
    cout << "\nRecursive reverse" << endl;
    recursiveReverse(NULL,first);
    display(first);

    cout << "\nCreating 2nd linked list" << endl;
    int B[] = { 15,26,45,60 };
    create2(B, 4);
    display(second);
    
    /*

    cout << "\nConcat : " << endl;
    concat(first, second);
    display(fourth);
    //delete third; //delete to make pointer NULL
    //third = NULL;

    */

    cout << "Mergiing : " << endl;
    Merge(first, second);
    display(third);

    /*Wrong code below BEWARE
    cout << "\nCreating a newlist\n";
    Node* newlist;
    newlist = new Node;
    Insert(newlist, 0, 10); Insert(newlist, 1, 20); Insert(newlist, 2, 30);
    display(newlist);
    */

    cout << "\nCreating  5th new list 10 20 30 40 50\n" << endl;
    int C[] = { 10,20,30,40,50 };
    create3(C, 5);
    display(fifth);
    Node* t1;
    Node* t2;
    t1 = fifth->next->next;
    t2 = fifth->next->next->next->next;
    t2->next = t1;
    cout << "\nChecking loop : " << checkloop(fifth)<< endl;

    return 0;
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
