#include<stdio.h>
#include<windows.h>
#include"malloc.h"

typedef struct listnode//������һλ��ָ��
{
	struct listnode * next;
	int length;
}Listnode;

typedef struct Sstack
{
	Listnode node;
	void * item;//ָ��ջԪ��
}Stack;

Stack * stack_create(int capacity)//����ͷ��㣬item����������С
{
	Stack * stack = (Stack *)malloc(sizeof(Stack));
	stack->node.next = NULL;
	stack->node.length = capacity;
	return stack;
}

void stack_destroy(Stack * stack)//ɾ��ջ�Ŀռ�
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

void stack_clear(Stack * stack)//ֻʣͷ���
{
	Stack * p = stack, *p1 = stack;
	if (stack == NULL)
	{
		return;
	}
	p = (Stack *)stack->node.next;//����ͷ���
	while (p != NULL)//ֻɾ��ͷ�����Ŀռ�
	{
		p1 = (Stack *)stack->node.next;
		free(p);
		p = p1;
	}
	stack->node.next = NULL;//����ͷ���ָ��NULL
	return;
}

int stack_push(Stack * stack, void * item)//��ջ
{
	if (stack->node.length == 0)
	{
		printf("ջ�ռ䲻�㣬����ʧ�ܣ�\n");
		return -1;
	}

	Stack * b1 = (Stack *)malloc(sizeof(Stack));
	b1->item = (void *)malloc(sizeof(item));//����itemָ��Ŀռ�
	b1->node.next = stack->node.next;//����
	stack->node.next = (Listnode *)b1;
	//�ٰ�item�����ָ��Ž�ȥb1��item
	b1->item = item;
	stack->node.length--;//��һ��ָ�ռ��һ
	return 0;
}

void * stack_pop(Stack * stack)
{
	if (stack->node.next == NULL)//�ж�ջ�Ƿ�Ϊ��
	{
		printf("ջ�գ��޷�������\n");
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
		printf("�޴���\n");
	}
	else
	{
		printf("����\n");
	}

	for (i = 0; i < 4; i++)
	{
		printf("%d\n", (int *)stack_pop(s1));
	}

	system("pause");
	return 0;
}