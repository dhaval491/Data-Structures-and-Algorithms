#include <iostream>
#include "Sort.cpp"
using namespace std;
/*int partition(int *A,int l,int h)
{
   int *pivot = A;
   int i = l,j = h,x = A[l];int k;
   do{
      do{i++;} while(A[i]<=x);
      do{j--;} while(A[j]>x);
      if(i<j) {k = A[i];A[i] = A[j];A[j] = k;}
   }while(i<j);
   k = A[l];A[l] = A[j];A[j] = k;
   return j;
}
void QuickSort(int *p, int l, int h){
   int j;
   if(l<h)
   {
      j = partition(p,l,h);
      QuickSort(p,l,j);
      QuickSort(p,j+1,h);

   }
}*/

int main()
{
   int A[] = {0,0,0,0,0};
   int *ptr = A;
   //QuickSort(A,0,9);
   //cout<<Partition(ptr,0,8)<<" Partitioned"<<endl;
   vector<int> Arr;
   Arr = ArrtoVector(A,4);
   std::vector<int> bubbleSort;
   std::vector<int> InsertionSort;
   std::vector<int> SelectionSort;
   std::vector<int> QuickSort;
   std::vector<int> SortedArray;
   std::vector<int> CountSort;
   std::vector<int> binSort;
   //std::vector<int> Merge_Sort;
   //bubbleSort = Bubble_sort(A,5);
   //InsertionSort = Insertion_sort_L(A,5);
   //InsertionSort = Insertion_sort(A,5);
   //SelectionSort = Selection_sort(A,5);
   //QuickSort = Quick_sort(ptr,2);
   //SortedArray = Sort_single(Arr,5,5,6);
   /*rMergeSort(ptr,0,8);
   for(int i = 0;i<9;i++)
   cout<<A[i]<<endl;*/
  //std::vector<int> Arr = ArrtoVector(ptr,11);

  CountSort = countSort(Arr);



   //display(bubbleSort);
   //display(InsertionSort);
  // display(QuickSort);
   //display(Arr);
   //display(SortedArray);
   //display(Arr);
   display(CountSort);

}
