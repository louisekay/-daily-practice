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

//创建头结点并清空
List * list_create()
{
	List * p = (List *)malloc(sizeof(List));
	p->length = 0;
	p->next = NULL;
	p->slider = 0;
	p->value = 0;
	return p;
}

//尾插
int list_insert(List * l1,List * p)
{
	List * current = l1;
	int i = 0;
	List * p1 = (List *)malloc(sizeof(List));//动态分配空间
	p1->value = p->value;//复制过去

	if (l1->length == 0)//只有头结点则插入的元素作为第一个结点
	{
		l1->next = p1;//头结点指向第一个元素
		p1->next = p1;//因为只有一个结点，所以结尾指向自己
		l1->length++;
		p1->slider == l1->length;
	}


	else if (l1->length > 0)//大于等于一个结点时
	{
		//先让插入的元素保存第一个结点的指针
		p1->next = l1->next;
		//然后遍历找到最后一个结点
		for (i = 0; i < l1->length; i++)
		{
			current = current->next;
		}
		//最后的元素保存插入元素的指针
		current->next = p1;//到此连接完成

		l1->length++;//改好长度
		p1->slider == l1->length;
	}
	return 0;
}

int list_destroy(List * l1)
{
	List * current = l1;
	for (current = current->next; current != l1->next; current = current->next)//先free循环
	{
		free(current);
	}
	free(l1);//最后free头结点
	return 0;
}

int main()
{
	List * l1 = list_create();
	int i = 0;

	list node1,node2,node3,node4;
	node1.value = 1;//这里value可以是scanf，因为方便我直接赋值了
	node2.value = 2;
	node3.value = 3;
	node4.value = 4;

	list_insert(l1,&node1);
	list_insert(l1,&node2);
	list_insert(l1,&node3);
	list_insert(l1,&node4);
	
	l1 = l1->next;//打印要先跳一个元素
	for (i = 0; i < 13; i++)
	{
		printf("%d\n",l1->value);
		l1 = l1->next;
	}

	list_destroy(l1);

	system("pause");
	return 0;
}