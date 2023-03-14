#include <iostream>
using namespace std;
// Swap two elements - Utility function
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// partition the array using last element as pivot
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        //if current element is smaller than pivot, increment the low element
        //swap elements at i and j
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //partition the array
        int pivot = partition(arr, low, high);

        //sort the sub arrays independently
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void displayArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<arr[i]<<"\t";

}

int main()
{
    int arr[] = {(int)'J',(int)'o',(int)'v',(int)'a',(int)'n',(int)'N',(int)'a',(int)'s',(int)'t',(int)'e',(int)'v',(int)'s',(int)'k',(int)'i',(int)'I',(int)'N',(int)'K',(int)'I',(int)'9',(int)'3',(int)'4'};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Input array"<<endl;
    displayArray(arr,n);
    cout<<endl;
    quickSort(arr, 0, n-1);
    cout<<"Array sorted with quick sort"<<endl;
    displayArray(arr,n);
    return 0;
}
/*Quick Sort алгоритмот работи така што се избира еден елемент од низата (pivot), во случајов последниот елемент.
Доколку тековниот елемент е помал од pivot елементот се преместува на лево од него, а доколку е поголем се заменува десно од него*/
