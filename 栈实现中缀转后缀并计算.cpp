#include<stdio.h>
#include<windows.h>
#include"malloc.h"

typedef struct listnode//������һλ��ָ��
{
	struct listnode * next;
	int length;
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
	stack->node.length = capacity;
	return stack;
}

void stack_destroy(Big * stack)//ɾ��ջ�Ŀռ�
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
		free(p);
		p = p1;
	}
	stack->node.next = NULL;//����ͷ���ָ��NULL
	return;
}

int stack_push(Big * stack, void * item)//��ջ
{
	if (stack->node.length == 0)
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
	stack->node.length--;//��һ��ָ�ռ��һ
	return 0;
}

void * stack_pop(Big * stack)
{
	if (stack->node.next == NULL)//�ж�ջ�Ƿ�Ϊ��
	{
		printf("ջ�գ��޷�������\n");
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
		if (a[i] == '(')//����������ֱ�ӽ�ջ
		{
			stack_push(s1, (void *)a[i]);
			i++;
			continue;
		}
		if (a[i] == '*' || a[i] == '/' || a[i] == '+' || a[i] == '-' && a[i] != '(' && a[i] != ')')//�����ĸ�������ʱ
		{
			if (s1->node.next == NULL)
			{
				stack_push(s1, (void *)a[i]);
			}
			else
			{
				char c1 = (char)stack_pop(s1);//ջ��Ԫ��
				if (iffirst(a[i]) < iffirst(c1))//a[i]���ȼ�����λ
				{
					stack_push(s1, (void *)a[i]);
					stack_push(s1, (void *)c1);
				}
				else//����ԭ��˳����ջ
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
		b[j++] = a[i];//�����������if�ľ������֣�ֱ�����
		i++;
	}
	while (s1->node.next != NULL)
	{
		b[j++] = (char)stack_pop(s1);
	}

	return NULL;
}




//�����char��int֮��ת��̫ɵ���ˣ�����ĵ����������������д
int   calculate1(Big * s1, char b[20])
{
	
	//�����������ջ��Ԫ�����Ҳ��������ڶ���Ԫ���������������������ջ
	int i = 0;
	while (b[i] != '\0')
	{
		//��������ȫ��ջ
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
				int left = (char)stack_pop(s1) - '0';//char - '0'��������
				char res = left + right + '0';//����ת��char
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
	char a[20] = { "1+2*(3-1)" };//����ֻ��ʵ��һλ��ת��
	char b[20] = { 0 };
	trans(s1,a,b);
    printf("%s\n",b);

	int result = calculate1(s1,b);

	printf("%d\n", result);
	
	stack_destroy(s1);
	system("pause");
	return 0;
}
