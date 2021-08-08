#include <iostream>
using namespace std;
struct Tnode
{
    int info;
    Tnode *right;
    Tnode *left;
};
typedef Tnode *tree;
struct node
{
    int info;
    node *pnext;
};
struct List
{
    node *phead;
    node *ptail;
};
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
void createlist(List &l)
{
    l.phead=l.ptail=NULL;
}
node* createnode(int x)
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
void nhaplist(List &l)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==0)break;
        node *p=createnode(x);
        addtail(l,p);
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
    List l; createlist(l);
    tree t=NULL; taocay(t);
    nhaplist(l);
    node *p=l.phead;
    while(p!=NULL)
    {
        int count=0;
        if(searchnode(t,p->info,count)==1) cout<<count;
        else cout<<-1;
        cout<<endl;
        p=p->pnext;
    }
    return 0;
}