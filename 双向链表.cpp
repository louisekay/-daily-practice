#include<stdio.h>
#include<windows.h>
#include"malloc.h"


typedef struct tag_listnode
{
	struct tag_listnode * next;
	struct tag_listnode * pre;
	int length;
}Listnode;

typedef struct value
{
	Listnode node;
	int val;	
}Value;


Value * list_create()
{
	Value * p = (Value *)malloc(sizeof(Value));
	p->val = 0;
	p->node.length = 0;
	p->node.next = NULL;
	p->node.pre = NULL;
	return p;
}

//β��
int list_insert(Value * list,value v1)
{
	Value * current = list;
	Value * p = (Value *)malloc(sizeof(Value));
	p->val = v1.val;//�ȸ���

	//ֻ��һ��ͷ���
	if (list->node.length == 0)
	{
		list->node.next = (Listnode *)p;
		p->node.next = NULL;
		p->node.pre = NULL;
		list->node.length++;
	}
	else
	{
		for (current = list; current->node.next != NULL; current = (Value *)current->node.next);
		current->node.next = (Listnode *)p;//����Ԫ������
		p->node.next = NULL;//����Ԫ��ָ��null
		p->node.pre = (Listnode *)current;//�����ָ��ǰ��
		list->node.length++;
	}
	return 0;
}

int main()
{
	int i = 0;
	Value * list = list_create();
	Value * current = list;
	Value * tail = NULL;
	Value v1,v2,v3,v4;
	v1.val = 1;
	v2.val = 2;
	v3.val = 3;
	v4.val = 4;

	list_insert(list,v1);
	list_insert(list, v2);
	list_insert(list, v3);
	list_insert(list, v4);


	
	for (current = (Value *)list->node.next; current != NULL; current = (Value *)current->node.next)
	{
		printf("%d\n",current->val);		
		tail = current;
	}
	for (; tail != NULL; tail = (Value *)tail->node.pre)
	{
		printf("%d\n", tail->val);
	}

	system("pause");
	return 0;
}