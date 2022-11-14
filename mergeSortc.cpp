#include "iostream"
using namespace std;

void merge(int *array, int left, int mid, int right)
{
    int s1=left;
    int s2=mid+1;
    int *temp=new int[right-left+1];
    int i=0;
    while (s1<=mid && s2<=right)
    {
        /* code */
        if (array[s1]<=array[s2])
        {
            /* code */
            temp[i++]=array[s1++];
        }else{
            temp[i++]=array[s2++];
        }
        
    }
    while (s1<=mid)
    {
        /* code */
        temp[i++]=array[s1++];
    }
    while (s2<=right)
    {
        /* code */
        temp[i++] = array[s2++];
    }
    for (int j = 0; j < right-left+1; j++)
    {
        /* code */
        array[j+left]=temp[j];
    }
    
    
    
    
}
void mergeSort(int *array, int left, int right)
{
    if (left >= right)
        return;
    int mid=(right+left)/2;
    mergeSort(array,left,mid);
    mergeSort(array,mid+1,right);
    merge(array,left,mid,right);
}
int main(){
    int a[10]={1,34,3,4,7,123,56,1,0,7};
    mergeSort(a,0,9);
    for (int i = 0; i < 10; i++)
    {
        /* code */
        cout<<a[i]<<"\t";
    }
    
}