#include <iostream>
using namespace std;
string chuyenNhiPhan(int x)
{
    string nhiphan="";
    while(x>0)
    {
        int a = x%2;
        if(a==0) nhiphan.push_back('0');
        else nhiphan.push_back('1');
        x/=2;
    }
    string convert;
    for(int i=0;i<nhiphan.length();i++)
    {
        int j = nhiphan.length()-i-1;
        if(nhiphan.at(j)=='0') convert.push_back('0');
        else convert.push_back('1');
    }
    return convert;
}
bool kiemTraDoiXung(string s)
{
    int length=s.length();
    for(int i=0;i<length;i++)
    {
        if(s.at(0)!=s.at(s.length()-i-1))return 0;
    }
    return 1;
}

int main()
{
   string a = chuyenNhiPhan(4);
   cout <<a<<endl;
   for(int i=0;i<a.length();i++) cout<<a.at(i)<< " ";
   cout<<endl;
   if(kiemTraDoiXung(a)==1)cout<<"Doi xung."<<endl;
   else cout<<"Khong doi xung."<<endl;
   return 0;
}