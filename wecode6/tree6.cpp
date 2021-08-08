#include <iostream>
using namespace std;
struct Tnode
{
    double info;
    Tnode *right;
    Tnode *left;
};
typedef Tnode *Tree;
struct node
{
    double info;
    node *pnext;
};
struct List
{
    node *phead;
    node *ptail;
};
void createlist(List &l)
{
    l.phead=NULL;
    l.ptail=NULL;
}
node *createnode(double x)
{
    node *p=new node;
    p->info=x;
    p->pnext=NULL;
    return p;
}
void addtail(List &l, node *p)
{
    if(l.phead==NULL)
    {
        l.phead=l.ptail=p;
    }
    else
    {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}
int insertnode(Tree &t, double x)
{
    if(t!=NULL)
    {
        if(t->info==x) return 0;
        if(t->info>x) return insertnode(t->left,x);
        else return insertnode(t->right,x);
    }
    t = new Tnode;
    t->info=x;
    t->left=NULL;
    t->right=NULL;
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
void nhaplist(List &l)
{
    double x;
    node *p;
    while(1)
    {
        cin>>x;
        if(x==0) break;
        p = createnode(x);
        addtail(l,p);
    }
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
int main()
{
    Tree t=NULL;
    List l; createlist(l);
    taocay(t);
    nhaplist(l);
    LNR(t);cout<<endl;
    node*p=l.phead;
    while(p!=NULL)
    {
        int count=0;
        int bac=0;
        dembac(t,p->info,bac);
        cout<<"Node "<<p->info<<" co bac la "<<bac<<"."<<endl;
        p=p->pnext;
    }
    return 0;
}