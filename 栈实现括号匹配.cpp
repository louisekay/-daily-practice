#include<stdio.h>
#include<windows.h>
#include"malloc.h"

typedef struct listnode//保存下一位的指针
{
	struct listnode * next;
	int length;
}Listnode;

typedef struct Sstack
{
	Listnode node;
	void * item;//指向栈元素
}Stack;

Stack * stack_create(int capacity)//创建头结点，item保存容量大小
{
	Stack * stack = (Stack *)malloc(sizeof(Stack));
	stack->node.next = NULL;
	stack->node.length = capacity;
	return stack;
}

void stack_destroy(Stack * stack)//删除栈的空间
{
	Stack * p = stack;
	if (stack == NULL)
	{
		return;
	}
	while (stack != NULL)
	{
		p = (Stack *)stack->node.next;
		free(stack);
		stack = p;
	}
	return;
}

void stack_clear(Stack * stack)//只剩头结点
{
	Stack * p = stack, *p1 = stack;
	if (stack == NULL)
	{
		return;
	}
	p = (Stack *)stack->node.next;//跳过头结点
	while (p != NULL)//只删除头结点外的空间
	{
		p1 = (Stack *)stack->node.next;
		free(p);
		p = p1;
	}
	stack->node.next = NULL;//最后把头结点指向NULL
	return;
}

int stack_push(Stack * stack, void * item)//入栈
{
	if (stack->node.length == 0)
	{
		printf("栈空间不足，插入失败！\n");
		return -1;
	}

	Stack * b1 = (Stack *)malloc(sizeof(Stack));
	b1->item = (void *)malloc(sizeof(item));//创建item指向的空间
	b1->node.next = stack->node.next;//连接
	stack->node.next = (Listnode *)b1;
	//再把item保存的指针放进去b1的item
	b1->item = item;
	stack->node.length--;//减一是指空间减一
	return 0;
}

void * stack_pop(Stack * stack)
{
	if (stack->node.next == NULL)//判断栈是否为空
	{
		printf("栈空，无法弹出！\n");
		return NULL;
	}
	void * item;
	Stack * p = (Stack *)stack->node.next;
	item = p->item;
	stack->node.next = p->node.next;
	free(p);
	return item;
}

int match(Stack * s1,char a)
{
	switch (a)
	{
		case ')':
		{
			char  c = (char )stack_pop(s1);
			if ( c == '(')
			{
				return 0;
			}
			break;
		}
		case ']':
		{   char  c = (char )stack_pop(s1);
		    if (c == '[')
			{
				return 0;
			}
			break;
		}
		case '}':
		{  char  c = (char)stack_pop(s1);
		    if (c == '}')
			{
				return 0;
			}
			break;
		}
		case '\'':
		{   char  c = (char)stack_pop(s1);
		    if (c == '\'')
			{
				return 0;
			}
			break;
		}
		case '\"':
		{   char  c = (char)stack_pop(s1);
		    if (c == '\"')
			{
				return 0;
			}
			break;
		}
	}

	return 0;
}

int main()
{
	Stack * s1 = stack_create(10);
	int i = 0;
	char a[50] = { "(afdsa){faf}[ada]  'afaf'    \"ada\"   " };
	for (i = 0; i < 50; i++)
	{
		if (a[i] == '(' || a[i] == '[' || a[i] == '{' || a[i] == '\'' || a[i] == '\"')
		{
			stack_push(s1, (void *)a[i]);
		}
		if (a[i] == ')' || a[i] == ']' || a[i] == '}' || a[i] == '\'' || a[i] == '\"')
		{
			match(s1,a[i]);
		}
	}

	if (s1->node.next == NULL)
	{
		printf("无错误！\n");
	}
	else
	{
		printf("出错！\n");
	}

	for (i = 0; i < 4; i++)
	{
		printf("%d\n", (int *)stack_pop(s1));
	}

	system("pause");
	return 0;
}