//���������������ɾ������ʼ����ȡ���ȣ����룬���ض����ָ��

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

//ֻ�Ǵ���ͷ���
List * L_create(List * p)
{
	p = (List *)malloc(sizeof(Teacher));
	p->next = NULL;
	((Teacher *)p)->age = 0;
	return p;
}
//ɾ������
int L_destroy(List * p)
{	
	for (; p->next != NULL; p = p->next)
	{
		free((Teacher *)p);
	}
	return 0;
}
//��ʼ��
int L_clear(List * p)
{
	//�������жϴ�������p�Ƿ�ָ��������������д
	
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
//ȡ���������
int L_length(List * p)
{
	return ((Teacher *)p)->age;
}
//����
int L_insert(List * p1, List * p2)
{
	//�����¿ռ�
	List * p = (List *)malloc(sizeof(Teacher));
	strcpy(((Teacher *)p)->name, ((Teacher *)p2)->name);
	((Teacher *)p)->age = ((Teacher *)p2)->age;

	List *p3 = p1->next;
	p1->next = p;
	p->next = p3;
	return 0;
}
//��ȡĳ������ָ��
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