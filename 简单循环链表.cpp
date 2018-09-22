#include<stdio.h>
#include<windows.h>
#include"malloc.h"

typedef struct list
{
	struct list * next;
	int slider;
	int value;
	int length;
}List;

//����ͷ��㲢���
List * list_create()
{
	List * p = (List *)malloc(sizeof(List));
	p->length = 0;
	p->next = NULL;
	p->slider = 0;
	p->value = 0;
	return p;
}

//β��
int list_insert(List * l1,List * p)
{
	List * current = l1;
	int i = 0;
	List * p1 = (List *)malloc(sizeof(List));//��̬����ռ�
	p1->value = p->value;//���ƹ�ȥ

	if (l1->length == 0)//ֻ��ͷ���������Ԫ����Ϊ��һ�����
	{
		l1->next = p1;//ͷ���ָ���һ��Ԫ��
		p1->next = p1;//��Ϊֻ��һ����㣬���Խ�βָ���Լ�
		l1->length++;
		p1->slider == l1->length;
	}


	else if (l1->length > 0)//���ڵ���һ�����ʱ
	{
		//���ò����Ԫ�ر����һ������ָ��
		p1->next = l1->next;
		//Ȼ������ҵ����һ�����
		for (i = 0; i < l1->length; i++)
		{
			current = current->next;
		}
		//����Ԫ�ر������Ԫ�ص�ָ��
		current->next = p1;//�����������

		l1->length++;//�ĺó���
		p1->slider == l1->length;
	}
	return 0;
}

int list_destroy(List * l1)
{
	List * current = l1;
	for (current = current->next; current != l1->next; current = current->next)//��freeѭ��
	{
		free(current);
	}
	free(l1);//���freeͷ���
	return 0;
}

int main()
{
	List * l1 = list_create();
	int i = 0;

	list node1,node2,node3,node4;
	node1.value = 1;//����value������scanf����Ϊ������ֱ�Ӹ�ֵ��
	node2.value = 2;
	node3.value = 3;
	node4.value = 4;

	list_insert(l1,&node1);
	list_insert(l1,&node2);
	list_insert(l1,&node3);
	list_insert(l1,&node4);
	
	l1 = l1->next;//��ӡҪ����һ��Ԫ��
	for (i = 0; i < 13; i++)
	{
		printf("%d\n",l1->value);
		l1 = l1->next;
	}

	list_destroy(l1);

	system("pause");
	return 0;
}