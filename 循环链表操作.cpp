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
		list->node.length++;
		t->node.slider == list->node.length;
		t->node.next = (In *)t;
	}
	else if (list->node.length > 0)//大于等于一个结点时
	{
		//先让插入的元素保存第一个结点的指针
		t->node.next = list->node.next;
		//然后遍历找到最后一个结点
		for (i = 0; i < list->node.length; i++)
		{
			current = (Out *)current->node.next;
		}
		//最后的元素保存插入元素的指针
		current->node.next = (In *)t;//到此连接完成

		list->node.length++;//改好长度
		t->node.slider == list->node.length;
	}
/*头插法(头插没调试过，不知道会出现什么情况)
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
	Out t1,t2,t3,t4;
	Out * current = list;
	int i = 0;
	t1.num1 = 1;
	t2.num1 = 2;
	t3.num1 = 3;
	t4.num1 = 4;

	circle_list_insert(list, &t1);
	circle_list_insert(list, &t2);
	circle_list_insert(list, &t3);
	circle_list_insert(list, &t4);

	current = (Out *)current->node.next;//先后移一下
	for (i = 0; i < 8; i++)
	{
		printf("%d\n",(Out *)current->num1);	
		current = (Out *)current->node.next;		
	}

	circle_list_destroy(list);

	system("pause");
	return 0;
}