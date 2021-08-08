#include <iostream>
using namespace std;

void swap(long long &a, long long &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void quicksort(long long a[], long long low, long long high)
{
    if (low <= high)
    {
        long long pivot = a[(low + high) / 2];
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
void quicksortcount(long long a[], long long low, long long high)
{
    if (low <= high)
    {
        long long pivot = a[(low + high) / 2];
        int left = low, right = high;
        while (left <= right)
        {
            while (a[left] > pivot) left++;
            while (a[right] < pivot) right--;
            if (left <= right)
            {
                swap(a[left], a[right]);
                cout<<left<<" "<<right<<endl;
                left++;
                right--;
            }
        }
        if (low < left) quicksortcount(a, low, left);
        if (high > right) quicksortcount(a, right, high);
    }
}
void print(long long *a, long long n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    long long n;
    cin>>n;
    long long *a = new long long[n];
    long long *temp = new long long[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<"Day truoc khi sap xep: ";
    print(a,n);
    quicksort(a,0,n-1);
    cout<<"Day sau khi sap xep: ";
    print(a,n);
    delete[] a;
    cout<<"\nCac hoan vi duoc thuc hien trong Quick Sort:\n";
    quicksortcount(temp,0,n-1);
    delete[] temp;
    return 0;
}
