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
void addhead(List &l, node *p)
{
    if(l.phead==NULL)
        l.phead=l.ptail=p;
    else
    {
        p->pnext=l.phead;
        l.phead=p;
    }
}
void addtail(List &l, node *p)
{
    if(l.phead==NULL)
        l.phead=l.ptail=p;
    else
    {
        l.ptail->pnext=p;
        l.ptail=p;
    }
}
void addlistnolimit(List &l)
{
    int info;
    while(true)
    {
        cin>>info;
        if(info==0)break;
        node *p=createnode(info);
        addtail(l,p);
    }
}
void printlist(List l)
{
    node *p=l.phead;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->pnext;
    }
}
void addlistwithlimit(List &l)
{
    int n;
    cin>>n;
    int info;
    for(int i=0;i<n;i++)
    {
        cin>>info;
        node *p=createnode(info);
        addtail(l,p);
    }
}


// xoa node
void xoa1node(List &l, node *bp, node *p)
{
    if(p==l.phead)
    {
        l.phead=l.phead->pnext;
        delete p;
    }
    else
    {
        bp->pnext=p->pnext;
        if(p==l.ptail) l.ptail=bp;
        delete p;
    }
}
    // xoa node co cung gia tri
void xoanode(List &l, int x)
{

}


// split list co dieu kien
void Split(List l, List &l1, List &l2)
{
    node *p1, *p2, *p=l.phead;
    while(p!=NULL)
    {
        node *head = l.phead;
        if(p==l.phead)
        {
            if (p->info % 2 == 0) {p1 = createnode(p->info);addtail(l1,p1);}
            if (p->info % 2 != 0) {p2 = createnode(p->info);addtail(l2,p2);}
        }
        else 
        {
            while(head->pnext!=p->pnext||head->pnext!=NULL)
            {
                if(head->info==p->info) break;
                else head=head->pnext;
            }
            if (head->pnext==p->pnext)
            {
                if (p->info % 2 == 0) {p1 = createnode(p->info);addtail(l1,p1);}
                if (p->info % 2 != 0) {p2 = createnode(p->info);addtail(l2,p2);}
            }
        }
        p=p->pnext;
    }
}
void reverselist(List &l)
{
    node *p=l.phead;
    node *bp=NULL;
    node *ap=NULL;
    while(p!=NULL)
    {
        ap=p->pnext;
        p->pnext=bp;
        bp=p;
        p=ap;
    }
    l.phead=bp;
}

// quicksort
void quick_sort(List &l)  
{        
    List l1;List l2;  
    if(l.phead==NULL) 
        return;  
    else  
    createlist(l1);  
    createlist(l2);  
    node *x=l.phead;  
    l.phead=x->pnext;  
    while(l.phead!=NULL)
    {  
        node *p=l.phead;  
        l.phead=p->pnext;  
        p->pnext=NULL;  
        if((p->info)%10000000<=(x->info)%10000000)  
            addhead(l1,p);  
        else  
            addhead(l2,p);  
    }  
    quick_sort(l1);  
    quick_sort(l2);  
    if(l1.phead==NULL)  
        l.phead=x;  
    else  
    {  
        l.phead = l1.phead;  
        l1.ptail->pnext = x;  
    }  
    x->pnext = l2.phead;  
    if(l2.phead==NULL)  
        l.ptail = x;  
    else  
    {  
        l.ptail = l2.ptail;  
    }  
}  
// bubble sort 
// void swap(int &x, int &y)
// {
//     int temp=x;
//     x=y;y=temp;
// }
// void bubblesort(List &l)
// {
//     bool haveswap=false;
//     node *bq=l.phead;
//     while(bq->pnext!=NULL)
//     {
//         haveswap=false;
//         node *q=bq;
//         while(q->pnext!=NULL)
//         {
//             if(q->x>q->pnext->x) {swap(q->x,q->pnext->x);swap(q->y,q->pnext->y);haveswap=true;}
//             q=q->pnext;
//         }
//         if(haveswap==false) bq=bq->pnext;
//     }
// }