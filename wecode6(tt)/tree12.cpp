
#include <iostream>

using namespace std;


struct node{
    int data;
    node *left;
    node *right;
};

int kiemTraNhanhTrai(node* root, int x);
int kiemTraNhanhPhai(node* root, int x);

void inDanhSachGiamDan(node* TREE);

string chuyenNhiPhan(int x);

bool kiemTraDoiXung(string s);
void demSoChuoiDoiXung(node* TREE, int &cnt);

node* themPhanTuVaoCay(node* &root, int x);

int main (){
    node* TREE = NULL;
    int x, cnt = 0;
    while (scanf("%d", &x)){
        if (x == 0){
            inDanhSachGiamDan(TREE);
            cout << endl;
            demSoChuoiDoiXung(TREE, cnt);
            cout << "Co " << cnt << " node thoa de bai." << endl;
            break;
        }
        else
            themPhanTuVaoCay(TREE, x);
    }
}
node* themPhanTuVaoCay(node* &root, int x)
{
    if(root!=NULL)
    {
        if(x<root->data) return themPhanTuVaoCay(root->left,x);
        else return themPhanTuVaoCay(root->right,x);
    }
    root=new node;
    root->data=x;
    root->left=root->right=NULL;
    return root;
}
void inDanhSachGiamDan(node* TREE)
{
    if(TREE != NULL)
    {
        inDanhSachGiamDan(TREE->right);
        cout<<TREE->data<<" ";
        inDanhSachGiamDan(TREE->left);
    }
}
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
void demSoChuoiDoiXung(node* TREE, int &cnt)
{
    while(TREE!=NULL)
    {
        demSoChuoiDoiXung(TREE->left,TREE->left->data);
        string s=chuyenNhiPhan(TREE->data);
        if(kiemTraDoiXung(s)==1) cnt++;
        demSoChuoiDoiXung(TREE->right,TREE->right->data); 
    }
}
