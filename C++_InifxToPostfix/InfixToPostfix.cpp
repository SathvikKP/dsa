// InfixToPostfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
using namespace std;

struct Node
{
    char data;
    struct Node* next;
}*top = NULL;

void push(char x)
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        cout << "\nStack overflow!!\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node* t;
    if (top == NULL)
    {
        cout << "\nStack Underflow!!!\n";
        return '@';
    }
    else
    {
        //t = (struct Node*)malloc(sizeof(struct Node));
        t = top;
        top = top->next;
        char x = t->data;
        free(t);
        return x;
    }
}

void display()
{
    struct Node* p;
    p = top;
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

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '/' || x == '*')
        return 2;
    else
        return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

string infixtopostfix(string infix)
{
    string postfix="";
    //int len = strlen(infix);
    //postfix = (char*)malloc(sizeof(char) * (len+2));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        //cout << infix[i] << " "<< i<<endl;
        if (isOperand(infix[i]))
        {
            //cout << "Operand detected\n" << endl;
            postfix += infix[i++];
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);
            else
            {
                postfix += pop();
                j++;
            }
        }
    }
    while (top != NULL)
    {
        postfix += pop();
    }
    //postfix[j] = '\0';
    return postfix;
}


/////Associativity + Paranthesis

int isOperand2(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x=='(' || x ==')' || x == '^')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int outstackprecedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '/' || x == '*')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    else
        return -1;
}

int instackprecedence(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '/' || x == '*')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return -1;
}


//bugged infixtopostfix dunno why


string infixtopostfixbug(string infix)
{
    string postfix = "";
    //int len = strlen(infix);
    //postfix = (char*)malloc(sizeof(char) * (len+2));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        cout << infix[i] << " " << i <<"   ";
        if (isOperand2(infix[i]))
        {
            //cout << "Operand detected\n" << endl;
            postfix += infix[i++];
            j++;
        }
        else if (infix[i] == ')')
        {
            char y = pop(); //j++;
            cout << y << "   Popped  " << endl;
            i++;
        }
        else
        {
            if (outstackprecedence(infix[i]) > instackprecedence(top->data))
            {
                cout << infix[i++] << "   Pushed  " << endl;;
                push(infix[i++]);
            }// DANNGGEERRRRRR!
            //else if (outstackprecedence(infix[i]) == instackprecedence(top->data))
            //{
            //    char y = pop(); //j++;
            //    cout << y << "   Popped  " << endl;
            //}    
            else
            {
                char y = pop(); //j++;
                cout << y << "   Popped  " << endl;
                postfix += y;
                j++;
            }
        }
        cout << endl;
    }
    while (top != NULL)
    {
        postfix += pop();
    }
    //postfix[j] = '\0';
    return postfix;
}




string infixtopostfix2(string infix)
{
    string postfix = "";
    int i = 0;
    while (infix[i] != '\0')
    {
        if (isOperand2(infix[i]))
        {
            postfix += infix[i++];
        }
        else
        {
            if (outstackprecedence(infix[i]) > instackprecedence(top->data))
            {
                push(infix[i++]);
            }
            else if (outstackprecedence(infix[i]) == instackprecedence(top->data))
            {
                pop();
                //cout<<"\nMatched paranthesis\n";
                i++;
            }
            else
            {
                postfix += pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix += pop();
    }
    return postfix;
}





int eval(string postfix)
{
    stack<int> st;
    int val = 0;
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isOperand2(postfix[i]))
        {
            st.push(postfix[i]-'0');
        }
        else
        {
            int x2 = st.top(); st.pop();
            int x1 = st.top(); st.pop();
            int r;
            switch (postfix[i])
            {
            case '+':r = x1 + x2; st.push(r); break;
            case '-':r = x1 - x2; st.push(r); break;
            case '*':r = x1 * x2; st.push(r); break;
            case '/':r = x1 / x2; st.push(r); break;
            }
        }
        i++;
    }
    return st.top();
    
}

int main()
{
    std::cout << "Infix to Postfix!\n";

    string infix = "a+b*c-d/e";
    //char postfix[6];
    cout << infix << endl;

    /*
    push('a');
    push('b');
    push('#');
    pop();
    display();
    */

    push('#');
    string postfix = infixtopostfix(infix);

    cout << postfix << endl<<endl;
    
    push('#');

    string infix2 = "((a+b)*c)-d^e^f";
    cout << infix2 << endl;
    string postfix2 = infixtopostfix2(infix2);
    cout << postfix2 << endl;
    

    string infix3 = "234*+82/-";
    cout << "\n" << infix3 << endl;
    cout << eval(infix3);
    //push(10);


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
