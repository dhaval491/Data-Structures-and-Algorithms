#include <iostream>

using namespace std;
struct node
{
    int data;
    node* next;

} *first = nullptr, *F = nullptr, *E  = nullptr;
using namespace std;

// function to create a linked list
void create(node * &first, int A[], int n)
{
    int i;
    node *t,*last;

    t = new node;
    t->data = A[0];
    t->next = nullptr;
    last = t;
    first = last;
    for(i = 1;i<n;i++)
    {
        t = new node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = last->next;
    }

}

// Function to insert a key at a given position in a linked list
void insert_key(node* &p, int key, int pos)
{
    node *t, *q = p;
//    int cnt = 0;
    t = new node;
    t->data = key;
    t->next = nullptr;
    if(pos == 0)
    {
       t->next = p;
       p = t; // if p has not been taken as reference than p taken here will be a copy of original p taken from input and the original p
       // wont have value of t;
    }
    else{
        for(int i = 0; i < pos-1;i++)
        {
            q = q->next;

        }
        t->next = q->next;
        //t->data = key;
        q->next = t;
    }

}


// Using Insert function defined above
void create_using_insert(int A[], int n, node*&p)
{
    for(int i = 0;i<n;i++)
    {
        insert_key(p,A[i],i);
    }
}
// Create by adding node at last
void insert_last(node* &p, int key)
{
    node *q = p, *t,*last;
    t = new node;
    t->next = nullptr;
    t->data = key;
    if(p  == nullptr) p = last = t;
    else{
        while(q->next) q = q->next;
    }
    q->next = t;
}

// Insert a node in a sorted list at a sorted position

void insert_sorted(node* &p, int key)
{
    node *r,*q,*t;
    t = new node;
    t->data = key;
    t->next = nullptr;
    q = p;
//    bool flag = true;
    r = nullptr;
    if(key <= p->data)
    {
        t->next = p;
        p = t;
    }
    else{
            r = q;
            q = q->next;
        while(q != nullptr)
        {

            if((key>= r->data) && (key< q->data))
            {
                r->next = t;
                t->next = q;
                //flag = false;
                break;
            }
            r = q;
            q = q->next;

        }
        //if(flag){
        r->next = t;
        t->next = q;
        //}
    }
}

void insert_sorted2(node* &p, int key)
{
    node *t,*q,*r;
    t = new node;
    t->data = key;
    q = p;
    r = nullptr;
    if(p->data>key)
    {
        t->next = p;
        p = t;
    }
    else{

    while(q && q->data < key)
    {

        r = q;
        q = q->next;
    }
    //cout<<"Reached"<<endl;
    r->next = t;
    t->next = q;

    //cout<<p<<" and q = "<<q<<endl;
    }
}

// deleting a node with a matching key
void delete_key(node *&p, int key)
{
    node *q = p;
    if(p->data == key)
    {
        p = p->next;
        q = nullptr;
    }
    while(q && !(key == q->next->data))
    {
        q = q->next;
    }
    q->next = q->next->next;
//    while(q)  // this is optional logic
//    {
//        if(q->data == key)
//        {
//            r->next = q->next;
//            break;
//        }
//        r = q;
//        q = q->next;
//    }

}

void delete_node(node* &p,int num)
{
    int cnt = 1;node *q = p;
    if(num == 1)
    {
        p = p->next;
    }
    else{
        while(num-1>cnt++) q = q->next;
        q->next = q->next->next;

    }
}

bool isSorted(node* p)
{
    while(p->next)
    {
        if(p->data > p->next->data) return false;
        p = p->next;
    }
    return true;
}
void remove_duplicates(node* r)
{
    node *q = r,*p = r->next;
    while(p)
    {
        if((q->data == p->data))
        {
             q->next = p->next;
             delete p;
             p = q->next;
        }
        else{
            //q->next = p;
            q = p;
            p = p->next;
        }
    }
}
void reverse_1(node* &q)
{
    node*p = q,*r = nullptr,*s;
    //first node

    //
    while(p)
    {
        s = p->next;
        p->next = r;
        r = p;
        p = s;
    }
    q = r;
}
void reverse_recursion(node* p)
{
    if(p->next == nullptr)
    {
        F = p;
        return;
    }
    reverse_recursion(p->next);
    node* q = p->next;
    q->next = p;
    p->next = nullptr;
}
void concatanate(node *&P,node *&q)
{
    node *p = P;
    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
}
node* merge_two_lists(node* &F, node* &S){
    node* M;
    node* f = F,*s = S;
    node* last;
    if(f->data<s->data){
            M = f;
            last = f;
            f = f->next;
            last->next = nullptr;
        }
        else{
            M = s;
            last = s;
            s = s->next;
            last->next = nullptr;
        }
    while(f&& s)
    {
        if(f->data<s->data)
        {

            last->next = f;
            last = f;
            f = f->next;
            last->next = nullptr;
        }
        else{
        last->next = s;
        last = s;
        s = s->next;
        last->next = nullptr;
        }

    }
    if(f)
    {
        last->next = f;
    }
    else{
        last->next = s;
    }
    cout<< "done"<<endl;
    return M;
}

// Merge list 2
node* merge_two_lists2(node* &F, node* &S){
    node* M;
    node* f = F,*s = S;
    node* last;
    if(f->data<s->data){
            M = f;
            last = f;
            f = f->next;
            last->next = nullptr;
        }
        else{
            M = s;
            last = s;
            s = s->next;
            last->next = nullptr;
        }
    while(f&& s)
    {
        if(f->data<s->data)
        {

            last->next = f;
            last = f;
            f = f->next;
            last->next = nullptr;
        }
        else{
        last->next = s;
        last = s;
        s = s->next;
        last->next = nullptr;
        }

    }
    if(f)
    {
        last->next = f;
    }
    else{
        last->next = s;
    }
    cout<< "done"<<endl;
    return M;
}
bool is_list_loop(node* &P)
{
    node* p  = P;node*q = P;
    do
    {
        p  = p->next;
        q = q->next;
        q = q!=nullptr?q->next:nullptr;

    }
    while((p&&q)&&p!=q);
        if(p==q)return true;
        else return false;
}



// To display the list
void disp_list(node *&q)
{
    node*p = q;
    while(p){
        cout<<p->data<<endl;
        p = p->next;
    }
}
int main()
{
    int A[] = {1,2,2,4,5,6};
    int B[] = {4,8,9};
    create_using_insert(A,6,F);
    create_using_insert(B,3,E);
    node* t1,*t2;
//    t1 = E;
//    t2 = E->next->next;
//    t2->next = t1;
    //insert_key(F,10,0);
    //insert_last(F,11);
    //insert_sorted2(F,0);
    //delete_node(F,2);
    //delete_key(F,3);
    //cout<<isSorted(F);
    //remove_duplicates(F);
    //reverse_1(F);
    //concatanate(F,E);
    disp_list(F);
//    disp_list(E);
////    cout<<"\n"<<"Merged"<<"\n"<<endl;
//   node* M ;
//   M = merge_two_lists(F,E);
////
   //disp_list(M);
//   cout<<is_list_loop(F)<<endl;
//   cout<<is_list_loop(t1)<<endl;

}
