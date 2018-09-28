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
		return;
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

int iffirst(char c)
{
	if (c == '+' || c == '-')
	{
		return 1;
	}
	if (c == '*' || c == '/' || c == '(')
	{
		return 2;
	}
	return 0;
}

char * trans(Big * s1,char a[20],char b[20])
{
	int i = 0,j = 0;
	while (a[i] != '\0')
	{	
		if (a[i] == '(')//遇到左括号直接进栈
		{
			stack_push(s1, (void *)a[i]);
			i++;
			continue;
		}
		if (a[i] == '*' || a[i] == '/' || a[i] == '+' || a[i] == '-' && a[i] != '(' && a[i] != ')')//遇到四个操作符时
		{
			if (s1->node.next == NULL)
			{
				stack_push(s1, (void *)a[i]);
			}
			else
			{
				char c1 = (char)stack_pop(s1);//栈顶元素
				if (iffirst(a[i]) < iffirst(c1))//a[i]优先级低则换位
				{
					stack_push(s1, (void *)a[i]);
					stack_push(s1, (void *)c1);
				}
				else//否则按原来顺序入栈
				{ 
					stack_push(s1, (void *)c1);
					stack_push(s1, (void *)a[i]);
				}
			}
			i++;
			continue;
		}
		if (a[i] == ')')
		{
			char c2 = 0;
			do
			{
				 c2 = (char)stack_pop(s1);
				 if (c2 == '(')
				 {
					 break;
				 }
				 b[j++] = c2;
			}while (c2 != '(');
			i++;
			continue;
		}
		b[j++] = a[i];//不满足上面的if的就是数字，直接输出
		i++;
	}
	while (s1->node.next != NULL)
	{
		b[j++] = (char)stack_pop(s1);
	}

	return NULL;
}




//这里的char与int之间转换太傻逼了，必须改掉。。。。这个单独写
int   calculate1(Big * s1, char b[20])
{
	
	//遇到运算符则栈顶元素做右操作数，第二个元素做左操作数，运算结果入栈
	int i = 0;
	while (b[i] != '\0')
	{
		//遇到数字全入栈
		if (b[i] != '+' && b[i] != '-' && b[i] != '*' && b[i] != '/')
		{
			stack_push(s1, (void *)b[i]);
			i++;
			continue;
		}
		else
		{
			switch (b[i])
			{
			case '+': {
				int right = (char)stack_pop(s1) - '0';
				int left = (char)stack_pop(s1) - '0';//char - '0'会变成整型
				char res = left + right + '0';//整型转回char
				stack_push(s1, (void *)(res));
				break;
			}
			case '-': {
				int right = (char)stack_pop(s1) - '0';
				int left = (char)stack_pop(s1) - '0';
				char res = left - right + '0';
				stack_push(s1, (void *)(res));
				break;
			}
			case '*': {
				int right = (char)stack_pop(s1) - '0';
				int left = (char)stack_pop(s1) - '0';
				char res = left * right + '0';
				stack_push(s1, (void *)(res));
				break;
			}
			case '/': {
				int right = (char)stack_pop(s1) - '0';
				int left = (char)stack_pop(s1) - '0';
				char res = left / right + '0';
				stack_push(s1, (void *)(res));
				break;
			}
			}
			i++;
			continue;
		}
		i++;
	}

	return ((int)stack_pop(s1) - '0');
}

int main()
{
	Big * s1 = stack_create(30);
	int i = 0;
	char a[20] = { "1+2*(3-1)" };//现在只是实现一位数转换
	char b[20] = { 0 };
	trans(s1,a,b);
    printf("%s\n",b);

	int result = calculate1(s1,b);

	printf("%d\n", result);
	
	stack_destroy(s1);
	system("pause");
	return 0;
}
