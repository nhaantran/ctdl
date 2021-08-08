#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp=x;
    x=y;y=temp;
}
struct node
{
    int x, y;
    node *pnext;
};
struct List
{
    node *phead, *ptail;
};
void createlist(List &l)
{
    l.phead=NULL;
    l.ptail=NULL;
}
node* createnode(int x, int y)
{
    node *p = new node;
    p->x=x;
    p->y=y;
    p->pnext=NULL;
    return p;
}

void addtail(List &l, node *p)
{
    if(l.phead==NULL)
    {
        l.phead=p;
        l.ptail=p;
    }
    else
    {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}

void bubblesort(List &l)
{
    bool haveswap=false;
    node *bq=l.phead;
    while(bq->pnext!=NULL)
    {
        haveswap=false;
        node *q=bq;
        while(q->pnext!=NULL)
        {
            if(q->x>q->pnext->x) {swap(q->x,q->pnext->x);swap(q->y,q->pnext->y);haveswap=true;}
            q=q->pnext;
        }
        if(haveswap==false) bq=bq->pnext;
    }
}

int main()
{
    List danhsach;
    createlist(danhsach);
    node* cay;
    int x,y;
    while(1)
    {   
        cin>>x;if(x==0)break;
        cin>>y;
        cay=createnode(x,y);
        addtail(danhsach,cay);
    }
    node *p = danhsach.phead;
    bubblesort(danhsach);
    int count=1;
    cout<<count<<endl;
    while(p!=NULL)
    {
        cout<<p->x<<" "<<p->y<<endl;
        if(p->pnext!=NULL)
        if(p->pnext->x>p->x+500) {count++;cout<<count<<endl;}
        p=p->pnext;
    }
    return 0;
}