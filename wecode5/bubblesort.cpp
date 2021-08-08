#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubblesort(int *a, int i, int n)
{
    int j=n-1;
    if(n>i)
    {
        while(j>=i)
        {
            if(a[j]<a[j-1]) 
            {
                cout<<a[j]<<" "<<a[j-1]<<endl;
                swap(a[j],a[j-1]);
            }
            j--;
        }
        bubblesort(a,i+1,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    bubblesort(a,0,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}