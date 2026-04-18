/*
***************************************************************
  对应教材7.3.1节，二叉排序树的类定义、成员函数定义及使用范例
****************************************************************
*/
#include <iostream>
using namespace std;

template <typename DataType>
struct BiNode
{
	DataType data;
	BiNode<DataType>* lchild, * rchild;
};

class BiSortTree
{
public:
	BiSortTree(int a[], int n);                   //建立查找集合a[n]的二叉排序树
	~BiSortTree() { Release(root); }             //析构函数，同二叉链表的析构函数
	void InOrder() { InOrder(root); }               //中序遍历二叉树

	BiNode<int>* InsertBST(int x) { return InsertBST(root, x); } //插入记录x
	void DeleteBST(BiNode<int>* & p, BiNode<int>* f);          //删除f的左孩子p
	BiNode<int>* SearchBST(int k) { return SearchBST(root, k); }  //查找值为k的结点

private:
	void Release(BiNode<int>* bt);
	BiNode<int>* InsertBST(BiNode<int>* & bt, int x);
	BiNode<int>* SearchBST(BiNode<int>* & bt, int k);
	void InOrder(BiNode<int>* bt);                   //中序遍历函数调用

	BiNode<int>* root;                                //二叉排序树的根指针
};

void  BiSortTree::InOrder(BiNode<int>* bt)
{
	if (bt == NULL) return;              //递归调用的结束条件
	else {
		InOrder(bt->lchild);               //前序递归遍历bt的左子树
		cout << bt->data << "\t";                  //访问根结点bt的数据域
		InOrder(bt->rchild);               //前序递归遍历bt的右子树  
	}
}

BiNode<int>* BiSortTree::SearchBST(BiNode<int>* & bt, int k)
{
	if (bt == NULL) return NULL;
	if (bt->data == k) return bt;
	else if (bt->data > k) return SearchBST(bt->lchild, k);
	else return SearchBST(bt->rchild, k);
}

BiNode<int>* BiSortTree::InsertBST(BiNode<int>* & bt, int x)
{
	if (bt == NULL) {                         //找到插入位置
		BiNode<int>* s = new BiNode<int>;
		s->data = x;
		s->lchild = NULL; s->rchild = NULL;
		bt = s;
		//return bt;
	}
	else if (bt->data > x) bt->lchild = InsertBST(bt->lchild, x);
	else bt->rchild = InsertBST(bt->rchild, x);
	return bt;
}

BiSortTree::BiSortTree(int a[], int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
		root = InsertBST(root, a[i]);
}

void BiSortTree::DeleteBST(BiNode<int>* & p, BiNode<int>* f)
{
	if ((p->lchild == NULL) && (p->rchild == NULL)) {     //p为叶子
		f->lchild = NULL; delete p; return;
	}
	if (p->rchild == NULL) {                 //p只有左子树
		f->lchild = p->lchild; delete p; return;
	}
	if (p->lchild == NULL) {                 //p只有右子树
		f->lchild = p->rchild; delete p; return;
	}
	BiNode<int>* par = p, * s = p->rchild;          //p的左右子树均不空
	while (s->lchild != NULL)               //查找最左下结点
	{
		par = s;
		s = s->lchild;
	}
	p->data = s->data;
	if (par == p) par->rchild = s->rchild;      //特殊情况，p的右孩子无左子树
	else par->lchild = s->rchild;
	delete s;
}

void BiSortTree::Release(BiNode<int>* bt)
{
	if (bt == NULL) return;
	else {
		Release(bt->lchild);                   //释放左子树
		Release(bt->rchild);                   //释放右子树
		delete bt;                            //释放根结点
	}
}

int main()
{
	BiNode<int>* p = NULL;
	int arr[10] = { 7 ,2, 3, 10, 5, 6, 1, 8, 9, 4 };
	BiSortTree B(arr, 10);
	B.InOrder();
	int key;
	cout << "\n请输入查找的元素值: ";
	cin >> key;
	p = B.SearchBST(key);
	if (p != NULL)
		cout << p->data << endl;
	else
		cout << "查找失败" << endl;

	system("pause");
	return 0;

}
