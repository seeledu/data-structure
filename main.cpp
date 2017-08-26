#include <iostream>
#include <bits/stdc++.h>
const int maxn=100000;
struct node
{
    node *lson,*rson;//l son,r son
    int fix,data;//random fix val, if a node
}; //build tree
int n,mod;//the number of nodes,which mod the user choose
int tmp;//临时变量
using namespace std;
int find(node *ind,int va);//寻找结点
void turnleft(node *&ind);//左旋
void turnright(node *&ind);//右旋
int del(node *&ind,int va);//将找到的节点删除（需要先用find确定节点是否存在）
void insert(node *&ind,int va);//插入新的结点
void travel(node *ind);//实现二叉树的遍历功能
void turnleft(node *&ind)//左旋
{
   // cout<<2;
    node *b=ind->rson;
    ind->rson=b->lson;
    b->lson=ind;
    ind=b;
}
void turnright(node *&ind)//右旋
{
   // cout<<3;
    node *b=ind->lson;
    ind->lson=b->rson;
    b->rson=ind;
    ind=b;
}
int del(node *&ind,int va)//将找到的节点删除（需要先用find确定节点是否存在）
{
    if (!ind) return 0;
    if (va==ind->data)
    {
        if (ind->lson&&ind->rson)//假如既有左节点又有右节点，讲它旋转至只有<=一个孩子的状态再删除
        {
            if (ind->lson
                ->fix<ind->rson->fix)
            {
                turnright(ind);
                del(ind->rson,va);
            }
            else
            {
                turnleft(ind);
                del(ind->lson,va);
            }

        }
        else
        {
            node *t=ind;
            if (ind->lson) ind=ind->lson;
            if (ind->rson) ind=ind->rson;
            delete t;
        }
    }
    else if (va>ind->data)  return find(ind->rson,va);
    else return find(ind->lson,va);
}
void insert(node *&ind,int va)//插入新的结点
{
    if (!ind)
    {
        ind=new node;
        ind->data=va;
        ind->fix=rand();
        //delete ind->lson;
       // delete ind->rson;
       // return ;
    }else if (va<=ind->data)
    {
        insert(ind->lson,va);
        if (ind->lson->fix<ind->fix)
            turnright(ind);
    }
    else
    {
        //cout<<ind->data;
        //cout<<2;
        insert(ind->rson,va);
        if(ind->rson->fix<ind->fix)
            turnleft(ind);
    }

}
int find(node *ind,int va)//寻找结点
{
    if (!ind)
    {
        return 0;
    }
    if (va==ind->data) return 1;
    if (va>ind->data)  return find(ind->rson,va);
    else return find(ind->lson,va);
}
void travel(node *ind)//实现二叉树的遍历功能
{
    if (!ind) return ;
    travel(ind->lson);
    printf("%d ",ind->data);
    travel(ind->rson);
}
node *lroot,*root;
int main()
{
    cout<<"请驶入初始节点数：";
    scanf("%d",&n);
    cout<<"请输入初始节点信息：";

    for (int i=1; i<=n; i++)
    {
       // root=lroot;
        scanf("%d",&tmp);
        insert(root,tmp);
        if (!lroot) lroot=root;
        cout<<1;
    }
    cout<<"请选择你想要的功能\n";
    cout<<"1:遍历整棵树";
    cout<<"2:插入节点\n";
    cout<<"3:查找节点\n";
    cout<<"4:删除节点\n";
    cout<<"0:退出\n";
    cin>>mod;
    while (mod!=0)
    {
        switch (mod)
        {
            case 1:
                travel(root);
                break;
            case 2:
                scanf("%d",&tmp);
                insert(root,tmp);
                break;
            case 3:
                scanf("%d",&tmp);
                if (find(root,tmp)) cout<<"查找成功！";else cout<<"查找失败！";
                break;
            case 4:
                scanf("%d",&tmp);
                if (find(root,tmp))
                {
                    del(root,tmp);
                    cout<<"删除成功！";
                }else
                {
                    cout<<"要删除的节点不存在！";
                }
                break;
        }
        cout<<"请选择你想要的功能\n";
        cout<<"1:遍历整棵树\n";
        cout<<"2:插入节点\n";
        cout<<"3:查找节点\n";
        cout<<"4:删除节点\n";
        cout<<"0:退出\n";
        cin>>mod;
    }
    return 0;
}
