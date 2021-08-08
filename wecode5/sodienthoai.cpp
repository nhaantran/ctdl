#include <iostream>
using namespace std;
struct node
{
    long long info;
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
node *createnode(long long x)
{
    node* p = new node;
    p->info=x;
    p->pnext=NULL;
    return p;
}
void addhead(List &l, node* p)
{
    if(l.phead==NULL)
    {
        l.phead=p;
        l.ptail=p;
    }
    else
    {
        p->pnext=l.phead;
        l.phead=p;
    }
}
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
int main()
{
    List l;
    createlist(l);
    node *p;
    int n;
    long long a;
    while(1)
    {
        cin>>a;
        if(a==0)break;
        p = createnode(a);
        addhead(l,p);
    }
    quick_sort(l);
    node *q= l.phead;
    while(q!=NULL)
    {
        cout<<0<<q->info<<endl;
        q=q->pnext;
    }
    return 0;
}
// void quicksort(List &l)
// {
//     if (l.phead==l.ptail)return;
//     node *tag = l.phead;
//     l.phead = l.phead->pnext;
//     tag->pnext = NULL;
//     List l1, l2;
//     createlist(l1);createlist(l2);
//     node *p;
//     while (l.phead!=NULL)
//     {
//         p = l.phead;
//         l.phead=l.phead->pnext;
//         p->pnext=NULL;
//         if(last7number(tag->info)>last7number(l.phead->info)) addhead(l1,l.phead);
//         else addhead(l2,l.phead);
//     }
//     quicksort(l1);
//     quicksort(l2);
//     if(l1.phead!=NULL)
//     {
//         l.phead=l1.phead;
//         l1.ptail->pnext = tag;
//     }
//     else l.phead = tag;
//     tag->pnext = l2.phead;
//     if(l2.phead!=NULL)
//     {
//         l.ptail-l2.ptail;
//     }
//     else l.ptail=tag;
// }
//    long long add;
// add=1000000000;
        // while( q->info/add < 1)
        // {
        //     add/=10;
        //     cout<<"0";
        // }