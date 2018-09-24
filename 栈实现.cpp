#include<stdio.h>
#include<windows.h>
#include"malloc.h"

typedef struct listnode//������һλ��ָ��
{
	struct listnode * next;
}Listnode;

typedef struct big
{
	Listnode node;
	void * item;//ָ��ջԪ��
}Big;

Big * stack_create(int capacity)//����ͷ��㣬item����������С
{
	Big * stack = (Big *)malloc(sizeof(Big));
	stack->node.next = NULL;
	stack->item = (void *)malloc(sizeof(int));
	*((int *)stack->item) = capacity;
	return stack;
}

void stack_destroy(Big * stack)//ɾ��ջ�Ŀռ�
{
	Big * p = stack;
	if (stack == NULL)
	{
		return ;
	}
	while (stack != NULL)
	{
		p = (Big *)stack->node.next;
		free(stack->item);//���������ξ�Ҫfree����
		free(stack);
		stack = p;
	}
	return;
}

void stack_clear(Big * stack)//ֻʣͷ���
{
	Big * p = stack, *p1 = stack;
	if (stack == NULL)
	{
		return;
	}
	p = (Big *)stack->node.next;//����ͷ���
	while (p != NULL)//ֻɾ��ͷ�����Ŀռ�
	{
		p1 = (Big *)stack->node.next;
		free(p->item);
		free(p);
		p = p1;
	}
	stack->node.next = NULL;//����ͷ���ָ��NULL
	return;
}

int stack_push(Big * stack, void * item)//��ջ
{
	if (*((int *)stack->item) == 0)
	{
		printf("ջ�ռ䲻�㣬����ʧ�ܣ�\n");
		return -1;
	}

	Big * b1 = (Big *)malloc(sizeof(Big));
	b1->item = (void *)malloc(sizeof(item));//����itemָ��Ŀռ�
	b1->node.next = stack->node.next;//����
	stack->node.next = (Listnode *)b1;
	//�ٰ�item�����ָ��Ž�ȥb1��item
	b1->item = item;
	*((int *)stack->item) = *((int *)stack->item) - 1;//��һ��ָ�ռ��һ
	return 0;
}

void * stack_pop(Big * stack)
{
	if (stack->node.next == NULL)//�ж�ջ�Ƿ�Ϊ��
	{
		printf("ջ�գ��޷�������\n");
		return NULL;
	}
    Big * p = (Big *)stack->node.next;
	stack->node.next = p->node.next;
	free(p);
	//��Ҫfreeitemָ��Ŀռ�
	return NULL;
}

int main()
{
	Big * s1 = stack_create(10);

	system("pause");
	return 0;
}
/*
stack * create(int capacity)����
void destroy(stack *)ɾ��ջ
void clear(stack *)���ջ
int push(stack *,void *)����
void * pop(stack *)����
void * top(stack *)��ȡ
int size(stack *)ջ���ݴ�С
int capacity(stack *)ջ��С
*/