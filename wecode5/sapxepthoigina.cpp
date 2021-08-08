#include <iostream>
#include <string>
using namespace std;
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
int partition(string *List, int low, int high)
{
    string key = List[high];
    int left = low;
    int right = high-1;
    while(1)
    {
        while(left<=right&&List[left]<key)left++;
        while(left<=right&&List[right]>key)right++;
        if(left>=right)break;
        swap(List[left],List[right]);
        left++;
        right--;
    }
    swap(List[left],List[high]);
    return left;
}
void quicksort(string *List, int low, int high)
{
    if(low < high)
    {
        int key=partition(List,low,high);
        quicksort(List,0,key-1);
        quicksort(List,key+1,high);
    }
}
void qsort(string *a, int low, int high)
{
    if (low <= high)
    {
        string pivot = a[(low + high) / 2];
        int left = low, right = high;
        while (left <= right)
        {
            while (a[left] < pivot) left++;
            while (a[right] > pivot) right--;
            if (left <= right)
            {
                swap(a[left], a[right]);
                left++;
                right--;
            }
        }
        if (low < left) qsort(a, low, left);
        if (high > right) qsort(a, right, high);
    }
}
int main()
{
    int soluong;cin>>soluong;
    string *List = new string[soluong];
    for(int i=0;i<soluong;i++) {cin.ignore();cin>>List[i];}
    qsort(List,0,soluong-1);
    for(int i=0;i<soluong;i++) cout<<List[i]<<endl;
}