// PolynomialLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int coeff;
    int exp;
    struct Node* next;
}*poly=NULL;

void create()
{
    struct Node* t, * last;
    int num;
    cout << "\nEnter number of terms\n";
    cin >> num;
    last = NULL;
    cout << "\nEnter in decreasing order, coef and exponent\n";
    for (int i = 0; i < num; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        cin >> t->coeff >> t->exp;
        t->next = NULL;
        if (poly == NULL)
        {
            poly = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void display(struct Node* p)
{
    while (p)
    {
        if (p->next == NULL)
        {
            cout << p->coeff; cout << endl;
        }
        else
        {
            cout << p->coeff << "x^" << p->exp << " + ";
        }
        p = p->next;
    }
}

long evaluate(struct Node* p, int x)
{
    long val=0;
    while (p)
    {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main()
{
    std::cout << "Polynomials!!!!\n";
    create();
    display(poly);
    cout << "\nEvaluate with val = 1 : " << evaluate(poly, 1);
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
