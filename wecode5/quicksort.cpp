#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void quicksort(int a[], int low, int high)
{
    if (low <= high)
    {
        int pivot = a[(low + high) / 2];
        int left = low, right = high;
        while (left <= right)
        {
            while (a[left] > pivot) left++;
            while (a[right] < pivot) right--;
            if (left <= right)
            {
                swap(a[left], a[right]);
                left++;
                right--;
            }
        }
        if (low < left) quicksort(a, low, left);
        if (high > right) quicksort(a, right, high);
    }
}
int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)cin>>a[i];
    quicksort(a,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
