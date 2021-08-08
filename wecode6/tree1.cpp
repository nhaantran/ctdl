#include <iostream>
using namespace std;

struct Tnode
{
    int Key;
    Tnode *pleft;
    Tnode *pright;
};
typedef Tnode *Tree;

int insertnode(Tree &T, int X)
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
    int x;
    while(1)
    {
        cin>>x;
        if(x==0) break;
        insertnode(t,x);
    }
}
void LNR(Tree t)
{
    if (t != NULL)
    {
        LNR(t->pleft);
        cout<<t->Key<<" ";
        LNR(t->pright);
    }
}
void LRN(Tree t)
{
    if (t != NULL)
    {
        LRN(t->pleft);
        LRN(t->pright);
        cout<<t->Key<<" ";
    }
}
void RNL(Tree t)
{
    if (t != NULL)
    {
        RNL(t->pright);
        cout<<t->Key<<" ";
        RNL(t->pleft);
    }
}
void RLN(Tree t)
{
    if (t != NULL)
    {
        RLN(t->pright);
        RLN(t->pleft);
        cout<<t->Key<<" ";
    }
}
void NLR(Tree t)
{
    if (t != NULL)
    {
        cout<<t->Key<<" ";
        NLR(t->pleft);
        NLR(t->pright);
    }
}
void NRL(Tree t)
{
    if (t != NULL)
    {
        cout<<t->Key<<" ";
        NRL(t->pright);
        NRL(t->pleft);
    }
}
int main()
{
    Tree t=NULL;
    taocay(t);
    cout<<"LNR: ";LNR(t);cout<<endl;
    cout<<"LRN: ";LRN(t);cout<<endl;
    cout<<"RNL: ";RNL(t);cout<<endl;
    cout<<"RLN: ";RLN(t);cout<<endl;
    cout<<"NLR: ";NLR(t);cout<<endl;
    cout<<"NRL: ";NRL(t);cout<<endl;
    return 0;
}