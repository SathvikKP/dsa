// Polynomial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Polynomial
{
public:
    int n;
    Term* terms;

    void create();
    void display();
};

void Polynomial::create()
{
    cout << "Enter number of terms : "; cin >> this->n;
    this->terms = new Term[n];
    cout << "Enter coef and exp in decreasing order :\n";
    for (int i = 0; i < this->n; i++)
    {
        cin >> this->terms[i].coeff >> this->terms[i].exp;
    }
    cout << "\nPolynomial created successfully \n";
    this->display();
    cout << endl;
}

void Polynomial::display()
{
    for (int i = 0; i < this->n; i++)
    {
        if (this->terms[i].exp != 0)
        {
            cout << this->terms[i].coeff << "x^" << this->terms[i].exp << " + ";
        }
        else
        {
            cout << this->terms[i].coeff << endl;
        }
    }
}

Polynomial* Polynomial_Add(Polynomial* p1, Polynomial* p2)
{
    Polynomial* p3;
    p3 = new Polynomial;
    p3->terms = new Term[p1->n + p2->n];
    int i = 0, j = 0, k = 0;
    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
            p3->terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            p3->terms[k++] = p2->terms[j++];
        else
        {
            p3->terms[k].exp = p1->terms[i].exp;
            p3->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    while (i < p1->n)
    {
        p3->terms[k++] = p1->terms[i++];
    }
    while (j < p2->n)
    {
        p3->terms[k++] = p2->terms[j++];
    }
    p3->n = k;
    return p3;
}

int main()
{
    std::cout << "\nPolynomial !!  !\n";

    Polynomial p1,p2;
    p1.create();
    p2.create();
    Polynomial* p3;
    p3 = Polynomial_Add(&p1, &p2);
    cout << endl;
    p3->display();
    //p.display();
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
