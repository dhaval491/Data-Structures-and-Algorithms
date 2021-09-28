#include <iostream>

using namespace std;

class DoublyNode{
public:
    DoublyNode* next;
    DoublyNode* prev;
    int data;
} *Doubly_Head = nullptr, *Doubly_Tail = nullptr;

void create_doubly(DoublyNode* &H, DoublyNode* &T, int A[], int n)
{
    DoublyNode *t,*First;
    t = new DoublyNode;
    t->next = nullptr;
    t->prev = nullptr;
    t->data = A[0];
    H = t;
    First = H;
    for(int i = 1;i<n;i++)
    {
        t = new DoublyNode;
        t->data = A[i];
        First->next = t;
        t->next = nullptr;
        t->prev = First;
        First = t;

    }
    T = t;
}
void insert_doubly(DoublyNode* &H,DoublyNode* &T,int key,int pos =0,int Size = -1)
{
    DoublyNode *p = H,*t;
    t = new DoublyNode;
    t->next = nullptr;
    t->prev = nullptr;
    t->data = key;

    if(pos == 0)
    {
       t->next = H;
       H->prev = t;
       H = t;
    }
    else if(pos == Size)
    {
        t->prev = T;
       T->next = t;
       T = t;
    }
    else
    {
        for(int i = 1;i<pos-1;i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;

    }


}
void delete_doubly(DoublyNode* &H,DoublyNode* &T,int pos)
{
    DoublyNode *p = H;
    if(pos == 0)
    {
        p = p->next;
        p->prev = nullptr;
        delete H;
        H = p;
    }
    else
    {
        for(int i = 1 ;i<pos-1;i++)
        {
            p = p->next;
        }
        p->next->next->prev = p;
        p->next = p->next->next;
    }
}
void Display_DLL (DoublyNode* &H,DoublyNode* &T)
{

    cout<<"In forward Order "<<endl;
    DoublyNode *p = H;
    while(p)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
    p = T;
    cout<<"In reverse Order "<<endl;
    while(p)
    {
        cout<<p->data<<endl;
        p = p->prev;
    }
}

int main()
{
    int A[5] = {1,2,3,4,5};
    create_doubly(Doubly_Head, Doubly_Tail, A,5);
    //insert_doubly(Doubly_Head,Doubly_Tail,10,6,6);
    delete_doubly(Doubly_Head,Doubly_Tail,3);
    Display_DLL(Doubly_Head, Doubly_Tail);

}
