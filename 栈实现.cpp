#include<stdio.h>
#include<windows.h>
#include"malloc.h"

typedef struct listnode//保存下一位的指针
{
	struct listnode * next;
	int length;
}Listnode;

typedef struct big
{
	Listnode node;
	void * item;//指向栈元素
}Big;

Big * stack_create(int capacity)//创建头结点，item保存容量大小
{
	Big * stack = (Big *)malloc(sizeof(Big));
	stack->node.next = NULL;
	stack->node.length = capacity;
	return stack;
}

void stack_destroy(Big * stack)//删除栈的空间
{
	Big * p = stack;
	if (stack == NULL)
	{
		return ;
	}
	while (stack != NULL)
	{
		p = (Big *)stack->node.next;		
		free(stack);
		stack = p;
	}
	return;
}

void stack_clear(Big * stack)//只剩头结点
{
	Big * p = stack, *p1 = stack;
	if (stack == NULL)
	{
		return;
	}
	p = (Big *)stack->node.next;//跳过头结点
	while (p != NULL)//只删除头结点外的空间
	{
		p1 = (Big *)stack->node.next;
		free(p);
		p = p1;
	}
	stack->node.next = NULL;//最后把头结点指向NULL
	return;
}

int stack_push(Big * stack, void * item)//入栈
{
	if (stack->node.length == 0)
	{
		printf("栈空间不足，插入失败！\n");
		return -1;
	}

	Big * b1 = (Big *)malloc(sizeof(Big));
	b1->item = (void *)malloc(sizeof(item));//创建item指向的空间
	b1->node.next = stack->node.next;//连接
	stack->node.next = (Listnode *)b1;
	//再把item保存的指针放进去b1的item
	b1->item = item;
	stack->node.length--;//减一是指空间减一
	return 0;
}

void * stack_pop(Big * stack)
{
	if (stack->node.next == NULL)//判断栈是否为空
	{
		printf("栈空，无法弹出！\n");
		return NULL;
	}
	void * item;
    Big * p = (Big *)stack->node.next;
	item = p->item;
	stack->node.next = p->node.next;
	free(p);
	return item;
}

int main()
{
	Big * s1 = stack_create(10);
	int i = 0;
	int a[4] = {0};
	for (i = 0; i < 4; i++)
	{
		a[i] = i + 1;
	}
	stack_push(s1, (void *)a[0]);//入栈
	stack_push(s1, (void *)a[1]);
	stack_push(s1, (void *)a[2]);
	stack_push(s1, (void *)a[3]);

	for (i = 0; i < 4; i++)
	{
		printf("%d\n", (int *)stack_pop(s1));
	}

	system("pause");
	return 0;
}
/*
stack * create(int capacity)创建
void destroy(stack *)删除栈
void clear(stack *)清空栈
int push(stack *,void *)插入
void * pop(stack *)弹出
void * top(stack *)获取
int size(stack *)栈内容大小
int capacity(stack *)栈大小
*/