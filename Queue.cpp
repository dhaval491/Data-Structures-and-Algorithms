#include <iostream>
#include<list>
#include<queue>
#include<vector>

using namespace std;

struct Queue
{
    int Size;
    int Front;
    int Rear;
    int *Q; // to declare the queue array dynamically
};
void enqueue(Queue *&q,int x)
{
//     check if queue is full
    if(q->Rear == q->Size-1){
        cout<<"Queue Overflow"<<endl;
    return;
    }
    q->Rear++;
    q->Q[q->Rear] = x;
    return;
}
int dequeue(Queue * &q)
{
    int x = -1;
    if(q->Front == q->Rear){
        cout<< "Queue is empty"<<endl;
    }
    else{
    q->Front++;
    x = q->Q[q->Front];
    }
    return x;
}
void enqueue_circular(Queue *q,int x)
{
    if((q->Rear+1)%q->Size == q->Front)
    {
    cout<<"Queue is Full"<<endl;
    }
    else
    {
        q->Rear = (q->Rear+1)%q->Size;
        q->Q[q->Rear] = x;
    }
    return;
}
int dequeue_circular(Queue *q)
{
    int x = -1;
    if((q->Front) == q->Rear)
    {
        q->Front = q->Rear = -1;
    cout<<"Queue is Empty"<<endl;
    return 0;
    }
    else
    {
        q->Front = (q->Front+1)%q->Size;
        x = q->Q[q->Front];
    }
    return x;
}
void display_queue(Queue *&q)
{
    for(int i = q->Front+1;i<=q->Rear;i++)
    {
        cout<<q->Q[i]<<endl;
    }
    return;
}

int main()
{
    std::queue<Queue*> myQ;


    Queue *q;
    q->Size = 5;
    q->Q = new int[q->Size];
    q->Front = -1;
    q->Rear = -1;
    int A[5] = {1,2,3,4,5};
    for (int i  =0;i<5;i++)
    {
        enqueue(q,A[i]);
    }
    display_queue(q);
    myQ.push(q);
    cout<<myQ.front()<<endl;
//    dequeue(q);
//    display_queue(q);

}

