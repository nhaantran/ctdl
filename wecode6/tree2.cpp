#include <iostream>
using namespace std;
struct Tnode
{
    double Key;
    Tnode *pleft;
    Tnode *pright;
};
typedef Tnode *Tree;
int insertnode(Tree &T, double X)
{
    if(T!=NULL)
    {
        if(T->Key==X) return 0;
        if(T->Key>X) return insertnode(T->pleft,X);
        else return insertnode(T->pright,X);
    }
    T = new Tnode;
    if(T==NULL) return -1;
    T->Key=X;
    T->pleft=NULL;
    T->pright=NULL;
    return 1;
}
void taocay(Tree &t)
{
    double x;
    while(1)
    {
        cin>>x;
        if(x==0) break;
        insertnode(t,x);
    }
}
bool searchTnode(Tree T, double x)
{
    if(T!=NULL)
    {
        if(T->Key==x) return 1;
        else if(x>T->Key) return searchTnode(T->pright,x);
        else return searchTnode(T->pleft,x);    
    }
    return 0;
}
struct node
{
    double data;
    node *pnext;
};
struct List
{
    node *ptail;
    node *phead;
};
void createlist(List &l)
{
    l.phead=NULL;
    l.ptail=NULL;
}
node *createnode(double x)
{
    node *p = new node;
    p->data=x;
    p->pnext=NULL;
    return p;
}
void addtail(List &l, node *p)
{
    if(l.phead==NULL) {l.phead=p;l.ptail=p;}
    else
    {
       l.ptail->pnext=p;
       l.ptail=p;
    }
}
void taolist(List &l)
{
    double x;
    node *p;
    while(1)
    {
        cin>>x;
        if(x==0) break;
        p=createnode(x);
        addtail(l,p);
    }
}
int main()
{
    Tree t=NULL;
    List l;createlist(l);
    taocay(t);
    taolist(l);
    node *temp=l.phead;
    while(temp!=NULL)
    {
        if(searchTnode(t,temp->data)==1)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
        temp=temp->pnext;
    }
    return 0;
}