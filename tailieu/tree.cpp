#include <iostream>
using namespace std;
struct Tnode
{
    int info;
    Tnode *right;
    Tnode *left;
};
typedef Tnode *Tree;
int insertnode(Tree &t, int x)
{
    if(t!=NULL)
    {
        if(x==t->info) return 0;
        else if(x<=t->info) return insertnode(t->left,x);
        else return insertnode(t->right,x);
    }
    t=new Tnode;
    t->info=x;
    t->right=t->left=NULL;
    return 1;
}
void taocay(Tree &t)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==0)break;
        insertnode(t,x);
    }
}
bool searchTnode(Tree T, double x)
{
    if(T!=NULL)
    {
        if(T->info==x) return 1;
        else if(x>T->info) return searchTnode(T->right,x);
        else return searchTnode(T->left,x);    
    }
    return 0;
}
void LNR(Tree t)
{
    if(t!=NULL)
    {
        LNR(t->left);
        cout<<t->info<<" ";
        LNR(t->right);
    }
}
void LRN(Tree t)
{
    if(t!=NULL)
    {
        LRN(t->left);
        LRN(t->right);
        cout<<t->info<<" ";
    }
}
void RNL(Tree t)
{
    if(t!=NULL)
    {
        RNL(t->right);
        cout<<t->info<<" ";
        RNL(t->left);
    }
}
void RLN(Tree t)
{
    if(t!=NULL)
    {
        RLN(t->right);
        RLN(t->left);
        cout<<t->info<<" ";
    }
}
void NLR(Tree t)
{
    if(t!=NULL)
    {
        cout<<t->info<<" ";
        NLR(t->left);
        NLR(t->right);
    }
}
void NRL(Tree t)
{
    if(t!=NULL)
    {
        cout<<t->info<<" ";
        NRL(t->right);
        NRL(t->left);
    }
}
void thaythe(Tree &p, Tree &T)
{
    if (T->left != NULL)
        thaythe(p, T->left);
    else
    {
        p->info = T->info;
        p = T;
        T = T->right;
    }
}
void xoatnode(Tree &t,int data)
{
    if (data < t->info)
    {
        xoatnode(t->left, data);
    }
    else if (data > t->info)
    {
        xoatnode(t->right, data);
    }
    else
    {
        Tnode *X = t;
        if (t->left == NULL)
            t = t->right; 
        else if (t->right == NULL)
            t = t->left;
        else
            thaythe(X, t->right);
        delete X;
    }
}
bool dembac(Tree t, double x, int &bac)
{
    if(t!=NULL)
    {
        if(t->info==x)
        {
            if(t->left==NULL&&t->right==NULL) {bac=0;return 1;}
            else if(t->left!=NULL&&t->right!=NULL) {bac=2;return 1;}
            else {bac=1;return 1;}
        }
        if(t->info>x) return dembac(t->left,x,bac);
        else return dembac(t->right,x,bac);
    }
    return 0;
}
void chieucao(Tree t, int i, int &h)
{
    if (t!=NULL)
    {
        if(i>h) h=i;
        chieucao(t->left,i+1,h);
        chieucao(t->right,i+1,h);
    }
}
void duyetcay(Tree t, int i, int middle)
{
    if(t!=NULL)
    {
        duyetcay(t->left,i+1,middle);
        if(i==middle) cout<<t->info<<" ";
        duyetcay(t->right,i+1,middle);
    }
}