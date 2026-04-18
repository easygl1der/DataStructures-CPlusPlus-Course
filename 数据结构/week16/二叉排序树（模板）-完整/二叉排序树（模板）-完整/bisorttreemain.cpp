#include <iostream>
using namespace std;
#include "bisortnode.cpp"

int  main()
{   int a[10]={63,55,90,58,70,42,10,45,83,67};
	BiSortTree<int> T(a,10); //创建一棵树
	cout<<"------前序遍历------ "<<endl;
	T.PreOrder( );
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;
	T.InOrder( );
	/*cout << endl;
	cout<<"------后序遍历------ "<<endl;
	T.PostOrder( );
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;
	T.LeverOrder();
	cout<<endl;
	*/
	BiNode<int> *root, *q;
	root=T.GetRoot();     //取树的根 
	q=T.SearchBST(root, 70);    //在二叉排序树中查找70 
    if (q==NULL) cout<<"Not found"<<endl;   //未找到  
	else cout<<q->data<<endl;               //找到输出找到的元素值 
	
	cout<<"\n\n测试删除一个结点";
	root=T.GetRoot();     //取树的根 
	T.DeleteBST(root, 70);    //在二叉排序树中删除70 
	cout<<70<<endl;
	cout<<"------前序遍历------ "<<endl;
	T.PreOrder( );
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;
	T.InOrder( );
	
	return 0;
}
