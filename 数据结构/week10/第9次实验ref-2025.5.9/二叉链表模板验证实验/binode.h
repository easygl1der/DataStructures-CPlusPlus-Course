#ifndef BINODE_H
#define BINODE_H
/*
template<class T> //为是BiNode类的友员类而声明
class BiTree;

template<class T>
class BiNode
{
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
public:
	BiNode(T ch){data=ch;lchild=NULL;rchild=NULL;} //有参构造函数
	~BiNode(){}                                    //析构函数
	void insert_value(const T& val)
	{
		if(val==data)
		{
			//root=NULL;
			return;
		}
	    if(val<data)
		{
			if(!lchild)
			{
				lchild=new BiNode<T>(val);
			}
			else
			{
				lchild->insert_value(val);
			}
		}
		else
		{
			if(!rchild)
			{
				rchild=new BiNode<T>(val);
			}
			else
			{
				rchild->insert_value(val);
			}
		}
		
	}
	friend class BiTree<T>;                        //将BiTree类设为友元类   
};
*/
template<typename  T1>
struct BiNode   //二叉树的结点结构
{  
	T1 data;       
	BiNode<T1> *lchild, *rchild;
};

template<typename  T>
class BiTree
{
public:
	BiTree( );  //{root = Creat(root);}         //构造函数，建立一棵二叉树
	~BiTree( );  //{Release(root);}          //析构函数，释放各结点的存储空间
	void PreOrder( );  //{PreOrder(root);}     //前序遍历二叉树
	void InOrder( ){InOrder(root);}       //中序遍历二叉树
	void PostOrder( ){PostOrder(root);}   //后序遍历二叉树
	void LeverOrder( );                 //层序遍历二叉树
	
private:
	BiNode<T> *root;                             //指向根结点的头指针
	BiNode<T> *Creat(BiNode<T> *bt);       //构造函数调用
	void Release(BiNode<T> *bt);                   //析构函数调用
	void PreOrder(BiNode<T> *bt);                  //前序遍历函数调用
	void InOrder(BiNode<T> *bt);                     //中序遍历函数调用
	void PostOrder(BiNode<T> *bt);                 //后序遍历函数调用
};
#endif
