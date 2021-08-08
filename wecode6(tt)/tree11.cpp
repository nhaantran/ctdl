#include <iostream>
using namespace std;
struct Tnode
{
    int info;
    Tnode *right;
    Tnode *left;
};
typedef Tnode *tree;
int insertnode(tree &t, int x)
{
    if(t!=NULL)
    {
        if(t->info==x)return 0;
        else if(t->info>x) return insertnode(t->left,x);
        else return insertnode(t->right,x);
    }
    t=new Tnode;
    t->info=x;
    t->right=t->left=NULL;
    return 1;
}
void taocay(tree &t)
{
    int x;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertnode(t,x);
    }
}
void chieucao(tree t, int i, int &h)
{
    if (t!=NULL)
    {
        if(i>h) h=i;
        chieucao(t->left,i+1,h);
        chieucao(t->right,i+1,h);
    }
}
void duyetcay(tree t, int i, int m, int &count)
{
    if(t!=NULL)
    {
        if(i==m)count++;
        duyetcay(t->left,i+1,m,count);
        duyetcay(t->right,i+1,m,count);
    }
}
int main()
{
    tree t=NULL;
    taocay(t);
    int h=0;
    chieucao(t,1,h);
    for(int i=0;i<h;i++) 
    {
        int count=0;
        duyetcay(t,0,i,count);
        cout<<"So node muc "<<i<<" cua cay la: "<<count<<endl;
    }
    return 0;
}