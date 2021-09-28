#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
std::vector<int> &insertInMaxHeap(std::vector<int> &A,int key)
{
    int temp = key;
    int i = A.size() - 1;
    while(i>0 && temp>A[((i+1)/2) - 1]){
        A[i] = A[((i+1)/2)-1];
        i = ((i+1)/2) - 1;
    }
    A[i] = temp;
    //cout<<"inserted"<<A[i]<<endl;
    return A;
}
std::vector<int>CreateMaxHeap(int A[],int Size)
{
    std::vector<int> Heap;
    Heap.push_back(A[0]);
    if(Size>1)
    {
        for(int i = 1;i<Size;i++)
        {
            Heap.push_back(A[i]);
            Heap = insertInMaxHeap(Heap, Heap.back());
      //      cout<<Heap[i]<<" "<<i<<endl;
        }
    }
    //cout<<"Created"<<endl;
    return Heap;
}

std::vector<int> &insertInMinHeap(std::vector<int> &A,int key)
{
    int temp = key;
    int i = A.size() - 1;
    while(i>0 && temp < A[((i+1)/2) - 1]){
        A[i] = A[((i+1)/2)-1];
        i = ((i+1)/2) - 1;
    }
    A[i] = temp;
    //cout<<"inserted"<<A[i]<<endl;
    return A;
}
std::vector<int>CreateMinHeap(int A[],int Size)
{
    std::vector<int> Heap;
    Heap.push_back(A[0]);
    if(Size>1)
    {
        for(int i = 1;i<Size;i++)
        {
            Heap.push_back(A[i]);
            Heap = insertInMinHeap(Heap, Heap.back());
      //      cout<<Heap[i]<<" "<<i<<endl;
        }
    }
    //cout<<"Created"<<endl;
    return Heap;
}
std::vector<int> DeleteFromHeap(std::vector<int> Heap)
{


  int x,X,j,i;
  X = Heap.front();
  Heap[0] = Heap.back();
  i = 0;j  = 2*i+1;
  while(j<Heap.size()-1)
  {
      if(Heap[j+1]>Heap[j])
      {
          j = j+1;
      }
      if(Heap[i]<Heap[j])
      {
          x =Heap[i];
          Heap[i] = Heap[j];
          Heap[j] = x;
          i = j;
          j = 2*j + 1;
      }
      else break;
  }
  Heap[Heap.size()-1] = X;
  //cout<<"Back = "<<Heap.back()<<endl;
  return Heap;
}
std::vector<int> HeapSort(int A[],int Size)
{
    std::vector<int> Heap = CreateMaxHeap(A,Size);
    std::vector<int> HeapSorted;
    for(int i = 0;i<Size;i++)
    {
        Heap = DeleteFromHeap(Heap);
        HeapSorted.push_back(Heap.back());
        Heap.pop_back();
    }
    return HeapSorted;
}

int main()
{
    int A[] = {40,4,30,11,10,25,5};
    std::vector<int> MaxHeap ;
    MaxHeap = CreateMaxHeap(A,7);
    cout<<"Max Heap"<<endl;
    for(int i =  0;i<MaxHeap.size();i++)
    {
        cout<<MaxHeap[i]<<endl;
    }
    /*cout<<" Min Heap"<<endl;
    std::vector<int> MinHeap ;
    MinHeap = CreateMinHeap(A,7);
    for(int i =  0;i<MinHeap.size();i++)
    {
        cout<<MinHeap[i]<<endl;
    }
    */
    MaxHeap = DeleteFromHeap(MaxHeap);
    cout<<"Max Heap after delete"<<endl;
    for(int i =  0;i<MaxHeap.size();i++)
    {
        cout<<MaxHeap[i]<<endl;
    }

    std::vector<int> SortedArray = HeapSort(A,7);
    cout<<"After Sorted"<<endl;
    for(int i =  0;i<SortedArray.size();i++)
    {
        cout<<SortedArray[i]<<endl;
    }



}
