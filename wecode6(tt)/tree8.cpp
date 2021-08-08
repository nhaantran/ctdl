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
    while(1)
    {
        cin>>x;
        if(x==0)break;
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
void duyetcay(tree t, int i, int m)
{
    if(t!=NULL)
    {
        duyetcay(t->left,i+1,m);
        if(i==m) cout<<t->info<<" ";
        duyetcay(t->right,i+1,m);
    }
}
int main()
{
    tree t=NULL;
    taocay(t);
    int h=0;
    chieucao(t,1,h);
    for(int i=1;i<=h;i++) 
    {
        cout<<"Deep "<<i<<": ";
        duyetcay(t,1,i); cout<<endl;
    }
    return 0;
}