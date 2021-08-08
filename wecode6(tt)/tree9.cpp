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
bool searchnode(tree t, int x, int &count)
{
    if(t!=NULL)
    {
        if(t->info>x) {count++;return searchnode(t->left,x,count);}
        else if(t->info<x) {count++;return searchnode(t->right,x,count);}
        else return 1;
    }
    return 0;
}
int main()
{
    tree t=NULL;
    taocay(t);
    int i=1;int h=0;
    chieucao(t,i,h);
    cout<<"Chieu cao cua cay la: "<<h<<endl;
    return 0;
}