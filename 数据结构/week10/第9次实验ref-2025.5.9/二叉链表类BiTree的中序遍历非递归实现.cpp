/****************************************** 
   二叉链表类BiTree的中序遍历非递归实现 
*******************************************/
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
  	~BiTree( ){Release(root);}                 //析构函数，释放各结点的存储空间
  	void InOrder( );                          //中序遍历二叉树
private:
  	BiNode<DataType> *Creat(BiNode<DataType> *bt);       //构造函数调用
  	void Release(BiNode<DataType> *bt);                   //析构函数调用
  	
  	BiNode<DataType> *root;                             //指向根结点的头指针
};

template <typename DataType> 
void BiTree<DataType> :: InOrder( )
{
	BiNode<DataType> *bt = root;
	BiNode<DataType> *S[100];       //顺序栈，最多100个结点指针
	int top = -1;                     //顺序栈初始化
	while (bt != NULL || top != -1)      //两个条件都不成立才退出循环
	{
		while (bt != NULL)
    	{
			S[++top] = bt;               //将根指针bt入栈
			bt = bt->lchild;  
		}
		if (top != -1) {                //栈非空
			bt = S[top--];
			cout << bt->data;
      		bt = bt->rchild;  
		}
		//else return;    //或者 bt=NULL; 
	}
}

template <class DataType>
BiNode<DataType> *BiTree<DataType> :: Creat(BiNode<DataType> *bt)
{
	char ch;
	cout << "请输入扩展二叉树的前序遍历序列，每次输入一个字符:";
	//A B # D # # C # #
	//AB#D##C##
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
{	
	BiTree<char> T;                           //定义对象变量T
    cout << "该二叉树的中序遍历序列是：";
	T.InOrder( );
	return 0;
}
