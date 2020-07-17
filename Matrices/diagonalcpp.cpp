#include <iostream>
using namespace std;

class Diagonal
{
    private:
        int n;int* A;
    public:
        Diagonal(int n);
        void set(int i,int j,int n);
        int get(int i,int j);
        void Display();
        ~Diagonal();
};

Diagonal::Diagonal(int n)
{
    this->n=n;
    this->A = new int[n];
}

void Diagonal::set(int i,int j,int x)
{
    if (i==j)
    {
        this->A[i-1]=x;
    }
    else
    {
        cout<<"Invalid index";
    }
}

int Diagonal::get(int i,int j)
{
    if (i==j)
    {
        return this->A[i-1];
    }
    else
    {
        return 0;
    }
}

void Diagonal::Display()
{
    for (int i=0;i<this->n;i++)
    {
        for (int j=0;j<this->n;j++)
        {
            if (i==j)
            {
                cout<<A[i]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
            
        }
        cout<<endl;
    }
    cout<<endl;
}

Diagonal::~Diagonal()
{
    delete []A;
}

int main()
{
    Diagonal d(4);
    d.set(1,1,5);d.set(2,2,8);d.set(3,3,9);d.set(4,4,12);
    d.Display();
    d.get(4,3);cout<<endl;
    d.get(2,2);cout<<endl;
    return 0;
}