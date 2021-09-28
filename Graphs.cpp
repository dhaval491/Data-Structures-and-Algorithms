#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define I INT_MAX
using namespace std;
void BFS(int G[][7], int start,int u)  //starting point and dimension of the matrix
{
    int i = start;
    queue<int> Que;
    vector<int> visited(7,0);
    cout<<i<<" ";
    visited[i] = 1;
    Que.push(i);
    while(!Que.empty())
    {
        i = Que.front();
        Que.pop();
        for(int v = 1;v<u;v++)
        {
            if(G[i][v] == 1 && visited[v] == 0)
            {cout<<v<<" ";
            visited[v] = 1;
            Que.push(v);
            }
        }


    }
}
void DFS(int G[][7], int start, int u)
{
    static int visited[7] = {0};
    if(visited[start]==0)
    {
        visited[start] = 1;
        cout<<start<<" ";
        for(int j = 1;j<u;j++)
        {
            if(visited[j] == 0 && G[start][j] == 1)
            {
                DFS(G,j,u);
            }
        }
    }
}
void DFS_S(int G[][7],int start, int n)
{
    stack<int> stk;
    int visited[7] = {0};
    int i = start,j = 1; cout<<i<<" ";
    visited[start] = 1;
    stk.push(i);
    while(!stk.empty())
    {

       i = stk.top(); //cout<<" i= "<<i<<" " ;
       stk.pop();
       j = 0;
       while(j<=6)
       {
           if(G[i][j] == 1 && visited[j] == 0)
           {
               stk.push(i);
               visited[j] = 1;cout<<j<<" "; 
               i = j; j = 0;
               
           }
           j++;

       }
       
    }
}

void Prim(int cost[][8])
{
    int n = 7;
    int near[8] = {I,I,I,I,I,I,I,I};
    int t[2][6]{0};
    int j,i,u,v,k,min;
    for(i = 1;i<=n;i++)
    {
        for(j = 1;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min = cost[i][j];
                u = i;v = j;
            }
        }
    }
    t[0][0] = u; t[1][0] = v;
    near[u] = near[v] = 0;
    // it will be t[0][i];
    for(j = 1;j<8;j++)
    {
        if(near[j] != 0){
        if(cost[j][u] < cost[j][v])
        near[j] = u;
        else near[j] = v;
        }
    }
    
    for(int i = 1;i<n-1;i++)
    {
        min = I;
       for(j = 1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]]<min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for(j = 1;j<=n;j++)
        {
            if(near[j] != 0){
            if( cost[j][k]<cost[j][near[j]])
            near[j] = k;
            }
        }
    }
    cout<<endl;
    for(int i = 0;i<6;i++)
    {
        cout<<t[0][i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i<6;i++)
    {
        cout<<t[1][i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int G[7][7]= {{0,0,0,0,0,0,0},
                  {0,0,1,1,0,0,0},
                  {0,1,0,0,1,0,0},
                  {0,1,0,0,1,0,0},
                  {0,0,1,1,0,1,1},
                  {0,0,0,0,1,0,0},
                  {0,0,0,0,1,0,0}};
    //BFS(G,5,7);cout<<endl;
    //DFS(G,2,7);cout<<endl;
    //DFS_S(G,2,7);

 int cost[8][8]= {{I,I,I,I,I,I,I,I},
                  {I, I,25,I,I,I,5,I},
                  {I,25,I,12,I,I,I,10},
                  {I, I,12,I,8,I,I,I},
                  {I, I,I,8,I,16,I,14},
                  {I, I,I,I,16,I,20,18},
                  {I, 5,I,I,I,20,I,I},
                  {I, I,10,I,14,18,I,I}};
   
Prim(cost);



    return 0;
}