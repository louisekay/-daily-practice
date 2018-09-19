//链表操作：创建，删除，初始化，取长度，插入，拿特定结点指针

#include<stdio.h>
#include<windows.h>
#include<malloc.h>
#include"string.h"

typedef struct list
{
	List * next;

}List;

typedef struct Teacher
{
	List l1;
	char name[10];
	int age;
}Teacher;

//只是创建头结点
List * L_create(List * p)
{
	p = (List *)malloc(sizeof(Teacher));
	p->next = NULL;
	((Teacher *)p)->age = 0;
	return p;
}
//删除链表
int L_destroy(List * p)
{	
	for (; p->next != NULL; p = p->next)
	{
		free((Teacher *)p);
	}
	return 0;
}
//初始化
int L_clear(List * p)
{
	//还可以判断传进来的p是否指向链表，这里懒得写
	
	if (p->next == NULL)
	{
		return 0;
	}
	else
	{
		p = p->next;
		for (; p->next != NULL; p = p->next)
		{
			strcpy(((Teacher *)p)->name, "0");
			((Teacher *)p)->age = 0;
		}
	}
	return 0;
}
//取链表结点个数
int L_length(List * p)
{
	return ((Teacher *)p)->age;
}
//插入
int L_insert(List * p1, List * p2)
{
	//分配新空间
	List * p = (List *)malloc(sizeof(Teacher));
	strcpy(((Teacher *)p)->name, ((Teacher *)p2)->name);
	((Teacher *)p)->age = ((Teacher *)p2)->age;

	List *p3 = p1->next;
	p1->next = p;
	p->next = p3;
	return 0;
}
//获取某个结点的指针
List * L_get(List * p,int pos)
{
	int i = 0;
	p = p->next;
	for (i = 1; i < pos; i++)
	{
		if (p->next == NULL)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	return p;
}
int main()
{
	Teacher * p = NULL;
	p = (Teacher *)L_create((List*)p);
	L_clear((List *)p);
	Teacher t1;
	t1.age = 4124;
	strcpy(t1.name, "wfeg");	
	L_insert((List *)p, (List *)&t1);

	L_destroy((List*)p);


	system("pause");
	return 0;
}