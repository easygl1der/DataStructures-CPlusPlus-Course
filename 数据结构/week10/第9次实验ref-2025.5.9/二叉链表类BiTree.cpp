/************************************************* 
   对应教材5.5.2节，二叉链表类BiTree的使用范例 
**************************************************/
#include <iostream>
using namespace std;

template <class DataType>
struct BiNode
{
 	DataType data;
  	BiNode<DataType> *lchild, *rchild;
};

template <class DataType>
class BiTree
{
public:
  	BiTree( ){root = Creat(root);}             //构造函数，建立一棵二叉树
  	~BiTree( ){Release(root);}               //析构函数，释放各结点的存储空间
  	void PreOrder( ){PreOrder(root);}          //前序遍历二叉树
  	void InOrder( ){InOrder(root);}           //中序遍历二叉树
  	void PostOrder( ){PostOrder(root);}        //后序遍历二叉树
  	void LeverOrder( );                     //层序遍历二叉树
private:
  	BiNode<DataType> *Creat(BiNode<DataType> *bt);       //构造函数调用
  	void Release(BiNode<DataType> *bt);                   //析构函数调用
  	void PreOrder(BiNode<DataType> *bt);                  //前序遍历函数调用
  	void InOrder(BiNode<DataType> *bt);                   //中序遍历函数调用
  	void PostOrder(BiNode<DataType> *bt);                 //后序遍历函数调用
  	
  	BiNode<DataType> *root;                             //指向根结点的头指针
};

template <class DataType>
void BiTree<DataType> :: PreOrder(BiNode<DataType> *bt) 
{
	if (bt == NULL) return;              //递归调用的结束条件
	else {
		cout << bt->data;                  //访问根结点bt的数据域
		PreOrder(bt->lchild);               //前序递归遍历bt的左子树
		PreOrder(bt->rchild);               //前序递归遍历bt的右子树  
	}
}

template <class DataType>
void BiTree<DataType> :: InOrder(BiNode<DataType> *bt) 
{
	if (bt == NULL) return;              //递归调用的结束条件
	else {
		InOrder(bt->lchild);               //前序递归遍历bt的左子树
		cout << bt->data;                  //访问根结点bt的数据域
		InOrder(bt->rchild);               //前序递归遍历bt的右子树  
	}
}

template <class DataType>
void BiTree<DataType> :: PostOrder(BiNode<DataType> *bt) 
{
	if (bt == NULL) return;              //递归调用的结束条件
	else {
		PostOrder(bt->lchild);               //前序递归遍历bt的左子树
		PostOrder(bt->rchild);               //前序递归遍历bt的右子树
		cout << bt->data;                  //访问根结点bt的数据域  
	}
}

template <class DataType>
void BiTree<DataType> :: LeverOrder( )
{
  	BiNode<DataType> *Q[100], *q = NULL;      //顺序队列最多100个结点
  	int front = -1, rear = -1;                      //队列初始化
  	if (root == NULL) return;                    //二叉树为空，算法结束
  	Q[++rear] = root;                           //根指针入队
  	while (front != rear)          //当队列非空时
  	{
		q = Q[++front];           //出队
	  	cout << q->data;   
	  	if (q->lchild != NULL)  Q[++rear] = q->lchild;
	  	if (q->rchild != NULL)  Q[++rear] = q->rchild;
  	}	
}

template <class DataType>
BiNode<DataType> *BiTree<DataType> :: Creat(BiNode<DataType> *bt)
{
	char ch;
	cout << "请输入扩展二叉树的前序遍历序列，每次输入一个字符:";
	cin >> ch;                      //输入结点的数据信息，假设为字符
	if (ch == '#') bt = NULL;                //建立一棵空树
	else {
		bt = new BiNode<DataType>; bt->data = ch;        
		bt->lchild = Creat(bt->lchild);          //递归建立左子树
		bt->rchild = Creat(bt->rchild);          //递归建立右子树
	}
	return bt;
}

template <class DataType>
void BiTree<DataType> :: Release(BiNode<DataType> *bt)
{
	if (bt == NULL) return;
	else{
		Release(bt->lchild);                   //释放左子树
		Release(bt->rchild);                   //释放右子树
		delete bt;                            //释放根结点
	}
}

int main( )
{	// A B # D # # C # # 
	BiTree<char> T;                           //定义对象变量T
    cout << "\n该二叉树的前序遍历序列是：";
	T.PreOrder( );
	cout << "\n该二叉树的中序遍历序列是：";
	T.InOrder( );
	cout << "\n该二叉树的后序遍历序列是：";
	T.PostOrder( );
	cout << "\n该二叉树的层序遍历序列是：";
    T.LeverOrder( );
	return 0;
}
