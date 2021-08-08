#include <iostream>
using namespace std;


int snt(int x)
{
    if(x<2) return 0;
    else
        for(int i=2;i*i<=x;i++)
            if(x%i==0) return 0;
    return 1;
}

void swap(int &x, int &y)
{
    int temp=x;
    x=y;
    y=temp;
}

