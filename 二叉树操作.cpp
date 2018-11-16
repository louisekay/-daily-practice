//树遍历每个结点都会经过三次，分别是前序，中序，后序。
//而且是遍历一次就会经过同一个结点三次

#include<stdio.h>
#include<windows.h>

struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode BiTNode;
typedef struct BiTNode* BiTree;

//前序
void pre_putout_tree(BiTree root)
{
	if (root == NULL)
	{
		return;
	}
	//先根再左再右
	printf("%d\n", root->data);

	if (root->lchild != NULL)
	{
		pre_putout_tree(root->lchild);
	}
	
	pre_putout_tree(root->rchild);

	return;
}

//中序
void in_putout_tree(BiTree root)
{
	if (root == NULL)
	{
		return;
	}
	//先左再根再右
	if (root->lchild != NULL)
	{
		in_putout_tree(root->lchild);
	}
	printf("%d\n",root->data);

	in_putout_tree(root->rchild);
	
	return;
}

//后序
void la_putout_tree(BiTree root)
{
	if (root == NULL)
	{
		return;
	}
	//先左再右再根
	if (root->lchild != NULL)
	{
		la_putout_tree(root->lchild);
	}
	
	la_putout_tree(root->rchild);

    printf("%d\n", root->data);

	return;
}

//用到中序遍历
void count_leaves(BiTree root,int *sum)
{
	if (root == NULL)//这个是使递归能中断的语句，不能省
	{
		return;
	}
	if (root->lchild != NULL)
	{
		count_leaves(root->lchild, sum);
	}
	if(root->lchild == NULL && root->rchild == NULL)
	{ 
		(*sum)++;
	}
	count_leaves(root->rchild, sum);
	return;
}

void count_height(BiTree root, int *sum)
{
	if (root == NULL)
	{
		return;
	}
	if (root->lchild != NULL)
	{
		count_height(root->lchild,sum);
	}
	

	return;
}

int main()
{
	BiTNode n1, n2, n3, n4, n5;
	n1.data = 1;
	n2.data = 2;
	n3.data = 3;
	n4.data = 4;
	n5.data = 5;
	//连起来
	n1.lchild = &n2;
	n1.rchild = &n3;
	n3.lchild = &n4;
	n3.rchild = &n5;

	//把叶子指向NULL
    n2.lchild = NULL;
	n2.rchild = NULL;
	n4.lchild = NULL;
	n4.rchild = NULL;
	n5.lchild = NULL;
	n5.rchild = NULL;

	
	BiTree root = &n1;
	//遍历
	in_putout_tree(root);
	printf("\n");
	pre_putout_tree(root);
	printf("\n");
	la_putout_tree(root);
	printf("\n");
	//求叶子数
	int sum = 0;
	count_leaves(root,&sum);
	printf("%d\n",sum);
	printf("\n");

	//求树高
	sum = 0;
	count_height(root, &sum);
	printf("%d\n", sum);
	printf("\n");

	system("pause");
	return 0;
}