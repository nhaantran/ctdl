#include <iostream>
using namespace std;
struct Tnode
{
    int info;
    Tnode *right;
    Tnode *left;
};
typedef Tnode *Tree;
int themnode(Tree &t, int x)
{
    if(t!=NULL)
    {
        if(t->info==x) return 0;
        if(t->info>x) return themnode(t->left,x);
        else return themnode(t->right,x);
    }
    t=new Tnode;
    t->info=x;
    t->right=NULL;
    t->left=NULL;
    return 1;
}
void taocay(Tree &t)
{
    int x;
    while(1)
    {
        cin>>x;
        if(x==0)break;
        themnode(t,x);
    }
}
int snt(int x)
{
    if(x<2) return 0;
    else
    {
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0) return 0;
        }
    }
    return 1;
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
void xoanode(Tree &t,int data)
{
    if (data < t->info)
    {
        xoanode(t->left, data);
    }
    else if (data > t->info)
    {
        xoanode(t->right, data);
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
void LNR(Tree t, List& l,int &count, int max)
{
    if(t!=NULL)
    {
        LNR(t->left,l,count,max);
        if(snt(t->info)==1&&count<max)
        {
            count++;
            node*p = createnode(t->info);
            addtail(l,p);
        }
        LNR(t->right,l,count,max);
    }
}
void LNRcout(Tree t)
{
    if (t != NULL)
    {
        LNRcout(t->left);
        cout<<t->info<<" ";
        LNRcout(t->right);
    }
}
int main()
{
    int max;
    List l; createlist(l);
    Tree t=NULL;
    taocay(t);
    cin>>max;
    int count=0;
    LNR(t,l,count,max);
    node *p=l.phead;
    while (p!=NULL)
    {
        // cout<<p->data<<" ";
        xoanode(t,p->data);
        p=p->pnext;
    }
    cout << endl;
    if(t!=NULL) LNRcout(t);
    else cout<<"Not found tree!"<<endl;
    return 0;
}