#include <iostream>
#include <bits/stdc++.h>
const int maxn=100000;
struct node
{
    node *lson,*rson;//l son,r son
    int fix,data;//random fix val, if a node
}; //build tree
int n,mod;//the number of nodes,which mod the user choose
int tmp;//��ʱ����
using namespace std;
int find(node *ind,int va);//Ѱ�ҽ��
void turnleft(node *&ind);//����
void turnright(node *&ind);//����
int del(node *&ind,int va);//���ҵ��Ľڵ�ɾ������Ҫ����findȷ���ڵ��Ƿ���ڣ�
void insert(node *&ind,int va);//�����µĽ��
void travel(node *ind);//ʵ�ֶ������ı�������
void turnleft(node *&ind)//����
{
   // cout<<2;
    node *b=ind->rson;
    ind->rson=b->lson;
    b->lson=ind;
    ind=b;
}
void turnright(node *&ind)//����
{
   // cout<<3;
    node *b=ind->lson;
    ind->lson=b->rson;
    b->rson=ind;
    ind=b;
}
int del(node *&ind,int va)//���ҵ��Ľڵ�ɾ������Ҫ����findȷ���ڵ��Ƿ���ڣ�
{
    if (!ind) return 0;
    if (va==ind->data)
    {
        if (ind->lson&&ind->rson)//���������ڵ������ҽڵ㣬������ת��ֻ��<=һ�����ӵ�״̬��ɾ��
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
void insert(node *&ind,int va)//�����µĽ��
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
int find(node *ind,int va)//Ѱ�ҽ��
{
    if (!ind)
    {
        return 0;
    }
    if (va==ind->data) return 1;
    if (va>ind->data)  return find(ind->rson,va);
    else return find(ind->lson,va);
}
void travel(node *ind)//ʵ�ֶ������ı�������
{
    if (!ind) return ;
    travel(ind->lson);
    printf("%d ",ind->data);
    travel(ind->rson);
}
node *lroot,*root;
int main()
{
    cout<<"��ʻ���ʼ�ڵ�����";
    scanf("%d",&n);
    cout<<"�������ʼ�ڵ���Ϣ��";

    for (int i=1; i<=n; i++)
    {
       // root=lroot;
        scanf("%d",&tmp);
        insert(root,tmp);
        if (!lroot) lroot=root;
        cout<<1;
    }
    cout<<"��ѡ������Ҫ�Ĺ���\n";
    cout<<"1:����������";
    cout<<"2:����ڵ�\n";
    cout<<"3:���ҽڵ�\n";
    cout<<"4:ɾ���ڵ�\n";
    cout<<"0:�˳�\n";
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
                if (find(root,tmp)) cout<<"���ҳɹ���";else cout<<"����ʧ�ܣ�";
                break;
            case 4:
                scanf("%d",&tmp);
                if (find(root,tmp))
                {
                    del(root,tmp);
                    cout<<"ɾ���ɹ���";
                }else
                {
                    cout<<"Ҫɾ���Ľڵ㲻���ڣ�";
                }
                break;
        }
        cout<<"��ѡ������Ҫ�Ĺ���\n";
        cout<<"1:����������\n";
        cout<<"2:����ڵ�\n";
        cout<<"3:���ҽڵ�\n";
        cout<<"4:ɾ���ڵ�\n";
        cout<<"0:�˳�\n";
        cin>>mod;
    }
    return 0;
}
