#include <iostream>



using namespace std;
struct Node{
int data;
struct Node* next;

}*Head;
Node* CreatCricular(int A[],int n,Node* &H){
    H = new Node;
    Node* p = H, *t;
    p->data =A[0];
    p->next = p;
    for(int i = 1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = p->next;
        p->next = t;
        p = p->next;
    }
    return H;
}
void displayCircular(Node* &Head)
{
    Node*p = Head;
    do{
        cout<<p->data<<endl;
        p = p->next;
    }while(p != Head);
}
void displayCircularRecursive(Node* H)
{
    static bool flag = false;
    static Node* p = H;
    if(!flag || p!=H)
    {
        flag = !flag;
        cout<<H->data<<endl;
        displayCircularRecursive(H->next);
    }
    flag = false;
}
void insertNodePos(Node* &H, int Data, int p) // Inserting node after the pth pos
{
    Node* q = H,*t;
    t = new Node;
    if(p != 1)
    {
        for(int i = 1;i<p;i++)q = q->next;
        t->data = Data;
        t->next = q->next;
        q->next = t;
    }
    else{
        t->data = Data;
        while(q->next!= H)
        {
            q = q->next;
        }
        q->next = t;
        t->next = H;
        H = t;
    }
}
void deleteNode(Node* &H, int pos)
{
    Node *p,*q = H;p = q->next;
    if(pos!=1){
        for(int i = 1;i<pos-1;i++)
        {
            q = q->next; p = p->next;
        }
        q->next = p->next;
        delete p;
    }
    else{
        while(p->next!= H)
        {
            p = p->next;
        }
        p->next = H->next;
        delete H;
        H = p->next;
    }
}


int main()
{
    int A[] = {1,2,3,4,5};
    Head = CreatCricular(A,5,Head);
    //displayCircularRecursive(Head);
    //insertNodePos(Head,6,5);
    //insertNodePos(Head,0,1);
    deleteNode(Head,1);


    displayCircular(Head);
    return 0;
}
