#include <iostream>
using namespace std;
void heapify(int *a, int i, int n);
void heapsort(int *a, int n)
{
    for(int i=n/2 - 1;i>=0;i--) heapify(a,i,n);
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}
void heapify(int *a, int i, int n)
{
    int largest=i;
    int left=i*2 + 1;
    int right=i*2 + 2;
    if(left<n&&a[largest]<a[left])largest=left;
    if(right<n&&a[largest]<a[right])largest=right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,largest,n);
    }
}
int main()
{
    int n; cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    heapsort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<endl;
    return 0;
}