#include <iostream>
#include <string>
using namespace std;
int main()
{
    string *a;
    int n;
    cin>>n;
    a = new string[n];
    for(int i=0;i<n;i++) {cin.ignore();cin>>a[i];}
    string find; cin>>find;
    for(int i=0;i<n;i++)
    {
        int temp = a[i].find(find);
        if(temp==0){cout<<i;break;}
    }
    return 0;
}