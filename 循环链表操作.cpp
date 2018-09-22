#include<stdio.h>
#include<windows.h>
#include"malloc.h"

typedef struct in
{
	int slider;
	struct in * next;
	int length;
	
}In;

typedef struct out
{
	In node;
	int num1;
}Out;


Out * circle_list_create()//创建链表结点
{
	Out * member = (Out *)malloc(sizeof(Out));
	member->node.length = 0;
	member->node.next = NULL;
	member->node.slider = 0;
	return member;
}
//尾插法插入一个结点
int circle_list_insert(Out *list, Out *t1)
{
	int i = 0;

	if (list == NULL)
	{
		printf("circle_list_insert funtion错误\n");
		return -1;
	}


	Out * current = list;//暂存头结点，相当于指标
	Out * t = (Out *)malloc(sizeof(Out));
	t->num1 = t1->num1;//把传过来的信息拷贝到堆创建的结点中

	//只有一个结点时
	if (list->node.length == 0)
	{
		current->node.next = (In *)t;
		list->node.length = 1;
		t->node.next = (In *)t;
	}
	else//多个结点时
	{		
		t->node.next = list->node.next;//作为最后一个结点，先保存开头结点
		for (current = list; current->node.next != list->node.next;current = (Out *)current->node.next);//再遍历到最后一个结点，连接插入的结点
		current->node.next = (In *)t;
		list->node.length++;
    }
/*头插法
	for (i = 0; i < list->node.length; i++)//找到最后一个结点
	{
		current->node.slider++;
		current = (Out *)current->node.next;
	}
	current->node.next = (In *)t;//先把最后一个跟插入的结点连接
	t->node.next = list->node.next;//然后把插入的结点跟头结点连起来
	list->node.next = (In *)t;//最后才让头结点保存插入结点的地址
*/
	return 0;
}

int circle_list_destroy(Out *list)
{
	int i = 0;
	Out * current = NULL;
	if (list == NULL)
	{
		printf("circle_list_destroy funtion错误\n");
		return -1;
	}

	for (i = 0; i < list->node.length; i++)
	{
		current = (Out *)list->node.next;
		free(list);
	}
	return 0;
}

int main()
{
	Out *list = circle_list_create();
	Out t1,t2;
	Out * current = list;
	int i = 0;
	t1.num1 = 1;
	t2.num1 = 2;
	circle_list_insert(list,&t1);
	circle_list_insert(list, &t2);

	for (current = (Out *)list->node.next; current->node.next != list->node.next; current = (Out *)current->node.next)
	{
		printf("%d\n",(Out *)current->num1);		
	}
	circle_list_destroy(list);

	system("pause");
	return 0;
}
