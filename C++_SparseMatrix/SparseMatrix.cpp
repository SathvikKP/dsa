// SparseMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element* ele;
};

void create(struct Sparse* s)
{
    printf("Enter dimensions: "); cin >> s->m >> s->n;//scanf("%d%d", &s->m, &s->n);
    printf("\nEnter number of non zero elements: "); cin >> s->num;//scanf("%d", &s->num);
    s->ele = (struct Element*)malloc(s->num * (sizeof(struct Element)));
    printf("\nEnter non zero elements : i,j,x\n");
    for (int i = 0; i < s->num; i++)
    {
        cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;//scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
        cout << endl;
    }
}

void display(struct Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse* add(struct Sparse* s1, struct Sparse* s2)
{
    struct Sparse* s3;

    s3 = (struct Sparse*)malloc(sizeof(struct Sparse));
    s3->ele = (struct Element*)malloc((s1->num + s2->num) * sizeof(struct Element));
    int i = 0, j = 0, k = 0;
    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            s3->ele[k++] = s1->ele[i++];
        else if (s2->ele[j].i < s1->ele[i].i)
            s3->ele[k++] = s2->ele[j++];
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
                s3->ele[k++] = s1->ele[i++];
            else if (s2->ele[j].j < s1->ele[i].j)
                s3->ele[k++] = s2->ele[j++];
            else
            {
                s3->ele[k] = s1->ele[i]; //copy 1st element but add x part
                s3->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    while (i < s1->num)
    {
        s3->ele[k++] = s1->ele[i++];
    }
    while (j < s2->num)
    {
        s3->ele[k++] = s2->ele[j++];
    }
    s3->m = s1->m; s3->n = s1->n;
    s3->num = k;
    return s3;

};

int main()
{
    std::cout << "Sparse Matrix!!\n";
    struct Sparse s1,s2;
    struct Sparse* s3;
    create(&s1); display(s1);
    create(&s2); display(s2);
    s3 = add(&s1,&s2);
    cout << "\nsum is " << endl;
    display(*s3);
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
