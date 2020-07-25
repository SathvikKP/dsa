// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

Node* create()
{
    queue<Node*> q;
    int x;
    Node* p;
    Node* t;
    Node* root;
    cout << "Enter root node value : "; cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (q.size() != 0)
    {
        p = q.front();
        q.pop();
        cout << "\nEnter left child of " << p->data << " : "; cin >> x;
        if (x == -1)
        {
            cout << "   No left child!" << endl;
        }
        else
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "\nEnter Right child of " << p->data << " : "; cin >> x;
        if (x == -1)
        {
            cout << "   No right child!" << endl;
        }
        else
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
    return root;
}

void preorder(Node* root)
{
    Node* p = root;
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(Node* root)
{
    Node* p = root;
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void postorder(Node* root)
{
    Node* p = root;
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void iterativepreorder(Node* root)
{
    Node* p = root;
    stack<Node*> st;
    while (p || st.size() != 0)
    {
        if (p)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void iterativeinorder(Node* root)
{
    Node* p = root;
    stack<Node*> st;
    while (p || st.size() != 0)
    {
        if (p)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
    cout << endl;
}

void levelordertraversal(Node* root)
{
    Node* p = root;
    queue<Node* > q;
    
    cout << p->data << " ";
    q.push(p);

    while (q.size() != 0)
    {
        p = q.front();
        q.pop();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.push(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.push(p->rchild);
        }
    }
    cout << endl;
}

int count(Node* root)
{
    Node* p;
    p = root;
    if (p)
    {
        return count(p->lchild) + count(p->rchild) + 1;
    }
    else
    {
        return 0;
    }
}

int height(Node* root)
{
    Node* p = root;
    if (p)
    {
        int x = height(p->lchild);
        int y = height(p->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    else
    {
        return 0;
    }
}

int countleaf(Node* root)
{
    Node* p = root;
    if (p)
    {
        int x = countleaf(p->lchild);
        int y = countleaf(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::cout << "Binary Treee!\n";
    Node* root;
    root = create();
    cout << "\nPreorder traversal : ";
    preorder(root);
    cout << "\nInorder traversal : ";
    inorder(root);
    cout << "\nPostorder traversal : ";
    postorder(root);
    cout << "\nIterative Preorder traversal : ";
    iterativepreorder(root);
    cout << "\nIterative Inorder traversal : ";
    iterativeinorder(root);
    cout << "\nLevel Order traversal : ";
    levelordertraversal(root);

    cout << "\nCount of nodes : " << count(root);
    cout << "\nHeight of tree (actually level, so subtract 1) : " << height(root);
    cout << "\nNumber of leaf nodes : " << countleaf(root);
    
    
    delete root;
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
