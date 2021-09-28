#include<vector>
#include<iostream>
struct node
{
    int data;
    node* next;

} *first = nullptr, *F = nullptr;

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
node* search_key(node *p, int key)
{
   static int cnt = 0;
   cnt++;
   if(p == nullptr){
       return nullptr;
   }

   if(p->data == key){
       return p;
   }
   search_key(p->next,key);
}
int hash(int key)
{
    return key%10;
}
void Insert(struct node *H[], int Key)
{
    int index = hash(Key);
    insert_sorted(H[index], Key);
}
