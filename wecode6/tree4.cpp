#include <iostream>
using namespace std;
struct Tnode
{
    double info;
    Tnode *right;
    Tnode *left;
};
typedef Tnode *tree;
int themnode(tree &t, double x)
{
    if(t!=NULL)
    {
        if(t->info==x) return 0;
        if(t->info>x) return themnode(t->left,x);
        else return themnode(t->right,x);
    }
    t = new Tnode;
    t->info=x;
    t->right=NULL;
    t->left=NULL;
    return 1;
}
void taocay(tree &t)
{
    int n;
    cin>>n;
    double x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        themnode(t,x);
    }
}
void LNR(tree t)
{
    if(t!=NULL)
    {
        LNR(t->left);
        cout<<t->info<<" ";
        LNR(t->right);
    }
}
void timnode(tree t,tree &t1, int &count)
{
    if(t!=NULL)
    {
        if(t->left==NULL&&t->right==NULL) {count++;themnode(t1,t->info);}
        timnode(t->left,t1,count);
        timnode(t->right,t1,count);
    }
}
int main()
{
    tree t=NULL;
    tree t1=NULL;
    taocay(t);
    int count=0;
    timnode(t,t1,count);
    cout<<count<<endl;
    LNR(t1);
    return 0;
}