#include <iostream>
using namespace std;
struct Tnode
{
    double info;
    Tnode *right;
    Tnode *left;
};
typedef Tnode *Tree;
int themnode(Tree &t, double x)
{
    if(t!=NULL)
    {
        if(t->info==x) return 0;
        if(x<t->info) return themnode(t->left,x);
        else return themnode(t->right,x);
    }
    t = new Tnode;
    t->info=x;
    t->left=NULL;
    t->right=NULL;
    return 1;
}
void taocay(Tree &t, double &trungbinh)
{
    int n;
    cin>>n;
    double x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        trungbinh+=x;
        themnode(t,x);
    }
    trungbinh/=x;
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
bool timnode(Tree &t, double x)
{
    if(t!=NULL)
    {
        if(t->info==x) return 1;
        if(t->info>x) return timnode(t->left,x);
        else return timnode(t->right,x);
    }
    return 0;
}
int main()
{
    double trungbinh=0;
    Tree  t=NULL;
    taocay(t,trungbinh);
    if(timnode(t,trungbinh)==1) cout<<1<<endl;
    else cout<<0<<endl;
    LNR(t);
    return 0;
}