#include <iostream>
using namespace std;
#include "bisortnode.h"

template<typename T> 
void BiSortTree<T>::InsertBST(BiNode<T>  *&root, BiNode<T> *&s)
{  
    if (root == NULL)  
       root = s;
    else  if (s->data < root->data)
                InsertBST(root->lchild, s);
            else   InsertBST(root->rchild, s);
}

template<typename T>  
BiSortTree<T>::BiSortTree( ){root=NULL; root = Creat(root);}         //构造函数，建立一棵二叉树

template<typename T>
BiSortTree<T>::BiSortTree(T  r[ ], int n)
{   int i;    
    BiNode<T> *s;
    root=NULL;
    for (i = 0; i < n; i++)
    {
       s = new BiNode<int>; 
       s->data = r[i];
       s->lchild = s->rchild = NULL;
       InsertBST(root, s);
    }
}


template<typename T>  
BiSortTree<T>::	~BiSortTree( ){Release(root);}          //析构函数，释放各结点的存储空


template<typename T> 
BiNode<T> *BiSortTree<T>::GetRoot()
{
  return root;	
}

template<typename T>  
BiNode<T> *BiSortTree<T>::SearchBST(BiNode<T> *&root, T k)
{
    if (root == NULL)
    return NULL;
    else if (root->data == k) 
              return root;
           else if (k < root->data) 
                      return SearchBST(root->lchild, k);
                  else return SearchBST(root->rchild, k);
}


template <class T>
bool BiSortTree<T>::DeleteBST(BiNode<T> *&root, T k)
 {//在以 root 为根的二叉搜索树中删除含 k 的结点
    BiNode<T> *temp;
    if (root != NULL) {
         if (k < root->data) DeleteBST (root->lchild,k);	
                                           //在左子树中执行删除
	     else if (k > root->data) DeleteBST (root->rchild,k);
					  //在右子树中执行删除
		 else if (root->lchild != NULL && root->rchild != NULL)
		 {       //root指示关键码为k的结点，它有两个子女
		    temp = root->rchild;  
		     //到右子树搜寻中序下第一个结点
		    while (temp->lchild != NULL) 
		        temp = temp->lchild;
		    root->data = temp->data;
				       //用该结点数据代替根结点数据
		   DeleteBST (root->rchild,root->data);
		 }
		 else {	//root指示关键码为k的结点有一个子女
		        temp = root;
			    if (root->lchild == NULL) root = root->rchild;
		         else root = root->lchild;
		        delete temp;
			    return true;
			  }
		}
		return false;
}
							  



template<typename T>  
void BiSortTree<T>::PreOrder( ){PreOrder(root);}     //前序遍历二叉树


template<typename T>    
void BiSortTree<T>::Release(BiNode<T> *bt)
{
	if (bt != NULL){                  
	     Release(bt->lchild);   //释放左子树
         Release(bt->rchild);   //释放右子树
         delete bt;
	}  

}


template<typename T>   
BiNode<T> *BiSortTree<T>::Creat(BiNode<T> *bt)
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
void BiSortTree<T>::PreOrder(BiNode<T> *bt)
{
	if(bt==NULL)  return;
	else {		
		cout<<bt->data<<" ";
        PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

template<typename T>
void BiSortTree<T>::InOrder(BiNode<T> *bt)
{
	if (bt==NULL)  return;      //递归调用的结束条件	          
    else {	
        InOrder(bt->lchild);    //中序递归遍历root的左子树
        cout<<bt->data<<" ";    //访问根结点的数据域
        InOrder(bt->rchild);    //中序递归遍历root的右子树
	}
}

template<typename T>
void BiSortTree<T>::PostOrder(BiNode<T> *bt)
{
	if (bt==NULL)  return;       //递归调用的结束条件
    else {	
        PostOrder(bt->lchild);    //后序递归遍历root的左子树
        PostOrder(bt->rchild);    //后序递归遍历root的右子树
        cout<<bt->data<<" ";      //访问根结点的数据域
	}
}

template<typename T>
void BiSortTree<T>::LeverOrder( )
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

