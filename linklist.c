#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//node
struct linknode {
	void* val;
	struct linknode* next;
	
};
//list
struct myList {
	struct linknode pHeader;//ͷ���
	int m_size;//����	
};
//���з�װ����ֹ�������
typedef void * LinkList;

//init 
LinkList init() {
struct myList *list = malloc(sizeof(struct linknode));

if (list  == NULL) {
	return NULL;
}
list->pHeader.val = NULL;
list->pHeader.next = NULL;
list->m_size = 0;
return list;
}

//insert
void insertLinkList(LinkList list1 ,int pos ,void *data) {
	//λ�ø���
	if (list1 == NULL) return;
	if (data == NULL) return;
	//����ת��
	struct myList *l1 = list1;
	if (pos<0 || pos>l1->m_size) {
		pos = l1->m_size;
	}
	//�ҵ�������ǰ�����λ��
	struct linknode *pCurrent = &l1->pHeader;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	//init new node 
	struct linknode* node = malloc(sizeof(struct linknode));
	node->val = data;
	node->next = NULL;
	//�����ڵ��ϵ
	node->next = pCurrent->next;
	pCurrent->next = node;
	//��Ϊ���Ĺ�ϵ�ǵ�������
	//����������
	l1->m_size++;
}
//��������,��ӻص�����
void foreach_Linklist(LinkList l1,void(*myForeach)(void*)) {
	
	if (l1 == NULL) {
		return;
	}
	struct myList* l2 = l1;
	struct linknode* nodenew = l2->pHeader.next;
	for (int i = 0; i < l2->m_size; i++) {
		//��Ҫһ���ص�����
		myForeach(nodenew->val);
		nodenew=nodenew->next;
	}
}
 //test
struct Person {
	char name[64];
	int age;
};
void personPrint(void* data) {
	struct Person* p = data;
	printf("����%s,����%d\n", p->name, p->age);
}
void test() {
	struct Person p1 = { "��1",18 };
	struct Person p2 = { "��2",19 };
	struct Person p3 = { "��3",20 };
	LinkList l1=init();
	insertLinkList(l1, 0, &p1);
	insertLinkList(l1, 1, &p2);
	insertLinkList(l1, 2, &p3);
	foreach_Linklist(l1, personPrint);
}

#include <stdio.h>
int main() {
	printf("linklist");
	test();
}
