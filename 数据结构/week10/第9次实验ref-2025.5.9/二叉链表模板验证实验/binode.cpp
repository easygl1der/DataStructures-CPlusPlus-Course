#include <iostream>
using namespace std;
#include "binode.h"



template<typename T>  
BiTree<T>::BiTree( ){root = Creat(root);}         //构造函数，建立一棵二叉树

template<typename T>  
BiTree<T>::	~BiTree( ){Release(root);}          //析构函数，释放各结点的存储空

template<typename T>  
void BiTree<T>::PreOrder( ){PreOrder(root);}     //前序遍历二叉树


template<typename T>    
void BiTree<T>::Release(BiNode<T> *bt)
{
	if (bt != NULL){                  
	     Release(bt->lchild);   //释放左子树
         Release(bt->rchild);   //释放右子树
         delete bt;
	}  

}

template<typename T>   
BiNode<T> *BiTree<T>::Creat(BiNode<T> *bt)
{
	char ch;
	cout<<"请输入创建一棵二叉树的结点数据"<<endl;
	cin>>ch;
    if (ch=='#') return NULL;
    else{ 
	     bt = new BiNode<T>;       //生成一个结点
         bt->data=ch;
         bt->lchild = Creat(bt->lchild);    //递归建立左子树
         bt->rchild = Creat(bt->rchild);    //递归建立右子树
    } 
    return bt;

}     


template<typename T> 
void BiTree<T>::PreOrder(BiNode<T> *bt)
{
	if(bt==NULL)  return;
	else {		
		cout<<bt->data<<" ";
        PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

template<typename T>
void BiTree<T>::InOrder(BiNode<T> *bt)
{
	if (bt==NULL)  return;      //递归调用的结束条件	          
    else {	
        InOrder(bt->lchild);    //中序递归遍历root的左子树
        cout<<bt->data<<" ";    //访问根结点的数据域
        InOrder(bt->rchild);    //中序递归遍历root的右子树
	}
}

template<typename T>
void BiTree<T>::PostOrder(BiNode<T> *bt)
{
	if (bt==NULL)  return;       //递归调用的结束条件
    else {	
        PostOrder(bt->lchild);    //后序递归遍历root的左子树
        PostOrder(bt->rchild);    //后序递归遍历root的右子树
        cout<<bt->data<<" ";      //访问根结点的数据域
	}
}

template<typename T>
void BiTree<T>::LeverOrder( )
{
	const int MaxSize=100;
	int front=0, rear=0;  //采用顺序队列，并假定不会发生上溢
	BiNode<T> *Q[MaxSize], *q;
	if (root==NULL) return;
	else {
		Q[rear++]=root;
		while (front!=rear)
		{
			q=Q[front++];
     		cout<<q->data<<" "; 		
    		if (q->lchild!=NULL)  Q[rear++]=q->lchild;		
			if (q->rchild!=NULL)  Q[rear++]=q->rchild;
		}
	}
}



