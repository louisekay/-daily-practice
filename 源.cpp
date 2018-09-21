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


Out * circle_list_create()//����������
{
	Out * member = (Out *)malloc(sizeof(Out));
	member->node.length = 0;
	member->node.next = NULL;
	member->node.slider = 0;
	return member;
}
//β�巨����һ�����
int circle_list_insert(Out *list, Out *t1)
{
	int i = 0;

	if (list == NULL)
	{
		printf("circle_list_insert funtion����\n");
		return -1;
	}


	Out * current = list;//�ݴ�ͷ��㣬�൱��ָ��
	Out * t = (Out *)malloc(sizeof(Out));
	t->num1 = t1->num1;//�Ѵ���������Ϣ�������Ѵ����Ľ����

	//ֻ��һ�����ʱ
	if (list->node.length = 0)
	{
		current->node.next = (In *)t;
		list->node.length = 1;
		t->node.next = NULL;
	}
	else//������ʱ
	{		
		t->node.next = list->node.next;//��Ϊ���һ����㣬�ȱ��濪ͷ���
		for (i = 0; i < list->node.length; i++)//�ٱ��������һ����㣬���Ӳ���Ľ��
		{
			current = (Out *)current->node.next;
		}
		current->node.next = (In *)t;
		list->node.length++;
    }
/*ͷ�巨
	for (i = 0; i < list->node.length; i++)//�ҵ����һ�����
	{
		current->node.slider++;
		current = (Out *)current->node.next;
	}
	current->node.next = (In *)t;//�Ȱ����һ��������Ľ������
	t->node.next = list->node.next;//Ȼ��Ѳ���Ľ���ͷ���������
	list->node.next = (In *)t;//������ͷ��㱣�������ĵ�ַ
*/
	return 0;
}

int circle_list_destroy(Out *list)
{
	int i = 0;
	Out * current = NULL;
	if (list == NULL)
	{
		printf("circle_list_destroy funtion����\n");
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
	int i = 0;
	t1.num1 = 1;
	t2.num1 = 2;
	circle_list_insert(list,&t1);
	circle_list_insert(list, &t2);

	for (i = 0; i < list->node.length; i++)
	{
		printf("%d\n",list->num1);
		list = (Out *)list->node.next;
	}
	circle_list_destroy(list);

	system("pause");
	return 0;
}