#include <iostream>
using namespace std;
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
void createlist(List &l)
{
    l.phead=l.ptail=NULL;
}
node *createnode(int info)
{
    node *p=new node;
    p->info=info;
    p->pnext=NULL;
    return p;
}
void push(node *p, List &l)
{
    if (l.phead == NULL)
    {
        l.phead = p;
        l.ptail = p;
    }
    else
    {
        p->pnext = l.phead;
        l.phead = p;
    }
}

void pop(List& l)
{
    node *s = l.phead;
    if (s == l.ptail) 
    {
        l.ptail = NULL; 
        l.phead = NULL; 
    }
    else l.phead = l.phead->pnext;
    delete s;
}
void print(List l)
{
    node *p=l.phead;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->pnext;
    }
}



