//������ÿ����㶼�ᾭ�����Σ��ֱ���ǰ�����򣬺���
//�����Ǳ���һ�ξͻᾭ��ͬһ���������

#include<stdio.h>
#include<windows.h>

struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
};
typedef struct BiTNode BiTNode;
typedef struct BiTNode* BiTree;

//ǰ��
void pre_putout_tree(BiTree root)
{
	if (root == NULL)
	{
		return;
	}
	//�ȸ���������
	printf("%d\n", root->data);

	if (root->lchild != NULL)
	{
		pre_putout_tree(root->lchild);
	}
	
	pre_putout_tree(root->rchild);

	return;
}

//����
void in_putout_tree(BiTree root)
{
	if (root == NULL)
	{
		return;
	}
	//�����ٸ�����
	if (root->lchild != NULL)
	{
		in_putout_tree(root->lchild);
	}
	printf("%d\n",root->data);

	in_putout_tree(root->rchild);
	
	return;
}

//����
void la_putout_tree(BiTree root)
{
	if (root == NULL)
	{
		return;
	}
	//���������ٸ�
	if (root->lchild != NULL)
	{
		la_putout_tree(root->lchild);
	}
	
	la_putout_tree(root->rchild);

    printf("%d\n", root->data);

	return;
}

//�õ��������
void count_leaves(BiTree root,int *sum)
{
	if (root == NULL)//�����ʹ�ݹ����жϵ���䣬����ʡ
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
	//������
	n1.lchild = &n2;
	n1.rchild = &n3;
	n3.lchild = &n4;
	n3.rchild = &n5;

	//��Ҷ��ָ��NULL
    n2.lchild = NULL;
	n2.rchild = NULL;
	n4.lchild = NULL;
	n4.rchild = NULL;
	n5.lchild = NULL;
	n5.rchild = NULL;

	
	BiTree root = &n1;
	//����
	in_putout_tree(root);
	printf("\n");
	pre_putout_tree(root);
	printf("\n");
	la_putout_tree(root);
	printf("\n");
	//��Ҷ����
	int sum = 0;
	count_leaves(root,&sum);
	printf("%d\n",sum);
	printf("\n");

	//������
	sum = 0;
	count_height(root, &sum);
	printf("%d\n", sum);
	printf("\n");

	system("pause");
	return 0;
}