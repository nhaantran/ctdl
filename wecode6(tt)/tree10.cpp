#include <iostream>
using namespace std;
struct Tnode
{
    int info;
    Tnode *right;
    Tnode *left;
};
typedef Tnode *tree;
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
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertnode(t,x);
    }
}
void duyetcay(tree t, int &count)
{
    if(t!=NULL)
    {
        if(t->left==NULL&&t->right!=NULL)count++;
        else if(t->right==NULL&&t->left!=NULL)count++;
        duyetcay(t->left,count);
        duyetcay(t->right,count);
    }
}
int main()
{
    tree t=NULL;
    taocay(t);
    int count=0;
    duyetcay(t,count);
    cout<<"So node bac 1 cua cay la: "<<count<<endl;
    return 0;
}