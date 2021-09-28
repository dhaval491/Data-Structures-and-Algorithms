#include <iostream>
#include<string.h>

using namespace std;
struct Stack
{
    int Size;
    int top;
    char *S;
};
void push(Stack *st,char x)
{
    if(st->top == st->Size-1) // -> operator is used as st is a pointer to Stack variable that has been taken as input by  reference
        cout<<"Stack overflow occured"<<endl;
    else{
        st->top++;st->S[st->top]=x;
    }
}
 char Pop(Stack *st)  // function to pot out the topmost value from the stack.
{
    int x = -1;
    if(st->top == -1) cout<<"stack underflow occured"<<endl;
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}
void displayStack(Stack *st)
{
    for(int i = 0;i<st->Size;i++)cout<<st->S[i]<<endl;
}
char peek(Stack *st,int pos)
{
    return pos<=st->top+1?st->S[st->top-pos+1]:-1;


}
bool StackIsEmpty(Stack *st)
{
    return st->top<0?true:false;
}
char StackTop(Stack *st)
{
    return st->S[st->top];
}
int isOperand(char x)
{

if(x == '+' || x == '-' || x == '*' || x  == '/')
{
    return 0;
}
else return 1;
}
int predecence(char x)
{
    if(x == '+' || x=='-') return 1;
    else if(x == '*' || x=='/') return 2;
    return 0;
}
//char *convert(char *infix,Stack *st)
//{
//    char *postfix = new char[]
//}
int main()
{
    Stack *st;
    string A("abcde");


    st->Size = 5;
    st->top = -1;
    st->S = new char[st->Size];
    //push(st,A_char[0]);push(st,A_char[1]);push(st,A_char[2]);push(st,A_char[3]);push(st,A_char[4]);


    //cout<<*(A.data()+2)<<endl;
    int i = 0;
    while(i < st->Size)
    {
        push(st,A[i]);
        //cout<<i<<endl;
        i++;
    }
    displayStack(st);
}
