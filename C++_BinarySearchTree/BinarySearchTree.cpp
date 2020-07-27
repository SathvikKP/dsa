// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

Node* Insert(Node* root,int key)
{
    Node* p=root;
    Node* r=NULL;
    Node* t;

    if (root == NULL)
    {
        t = new Node;
        t->lchild = t->rchild = NULL; //essentially, what happens 
        t->data = key;
        root = t;
        return root;
    }
    while (p)
    {
        r = p;
        if (key < p->data)
            p = p->lchild;
        else if (key > p->data)
            p = p->rchild;
        else
        {
            cout << "Already exists!!\n"; return root;
        }
    }
    t = new Node;
    t->lchild = t->rchild = NULL;
    t->data = key;
    if (key < r->data)
        r->lchild = t;
    else
        r->rchild = t;

    return root;
}

void Inorder(Node* root)
{
    Node* p = root;
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node* Search(Node* root, int key)
{
    Node* p = root;
    while (p)
    {
        if (p->data == key)
            return p;
        else if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}

Node* RInsert(Node* root, int key)
{
    Node* p = root;

    if (p == NULL)
    {
        Node* t;
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    return p;
}

int Height(Node* p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        int x = Height(p->lchild);
        int y = Height(p->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
}

Node* InorderPredecessor(Node* root)
{
    Node* p = root;
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

Node* InorderSuccessor(Node* root)
{
    Node* p = root;
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

Node* Delete(Node* root, int key)
{
    Node* p = root;
    Node* q = NULL;
    //NULL condition, i.e, nothing to delete, not found??
    if (p == NULL)
        return NULL;

    //deleting leaf nodes
    if (p->lchild == NULL && p -> rchild == NULL && p->data==key) //important condition or else deletes nearest element at leaf
    {
        if (p == root)
            root = NULL;
        delete p;
        return NULL;
    }

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }        
    }
    return p; // Why is this line necessary? Debug to find out, we get p returned, in final call, it'll be root.
}

int main()
{
    std::cout << "Binary Search TREE!\n";
    Node* root=NULL;
    cout << "\nInserting elements\n";
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 30);

    Inorder(root);

    cout << "\nSearching for 20 : " << (Search(root, 20)->data) << endl;


    cout << "\nInserting elements for recursive insert\n";
    Node* root2=NULL;
    root2 = RInsert(root2, 100);
    RInsert(root2, 50);
    RInsert(root2, 200);
    RInsert(root2, 80);
    RInsert(root2, 300);

    Inorder(root2);

    cout << "\nSearching for 80 : " << (Search(root2, 80)->data) << endl;

    cout << "\nDeleting 10 from first tree\n";
    Inorder(root);
    Delete(root, 10); cout << endl;
    Inorder(root);

    

    cout << "\n\nGenerating tree : 50 10 40 20 30\n";
    Node* root1 = NULL;
    root1 = RInsert(root1, 50);
    RInsert(root1, 10);
    RInsert(root1, 40);
    RInsert(root1, 20);
    RInsert(root1, 30);
    Inorder(root1);

    cout << "\nDeleting 50\n";
    Delete(root1, 50);
    Inorder(root1);

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
