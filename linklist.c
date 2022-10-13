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
	struct linknode pHeader;//头结点
	int m_size;//长度	
};
//进行封装，防止造成隐患
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
	//位置更新
	if (list1 == NULL) return;
	if (data == NULL) return;
	//类型转化
	struct myList *l1 = list1;
	if (pos<0 || pos>l1->m_size) {
		pos = l1->m_size;
	}
	//找到插入点的前驱结点位置
	struct linknode *pCurrent = &l1->pHeader;
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	//init new node 
	struct linknode* node = malloc(sizeof(struct linknode));
	node->val = data;
	node->next = NULL;
	//建立节点关系
	node->next = pCurrent->next;
	pCurrent->next = node;
	//因为它的关系是单向链表
	//更新链表长度
	l1->m_size++;
}
//遍历功能,添加回调函数
void foreach_Linklist(LinkList l1,void(*myForeach)(void*)) {
	
	if (l1 == NULL) {
		return;
	}
	struct myList* l2 = l1;
	struct linknode* nodenew = l2->pHeader.next;
	for (int i = 0; i < l2->m_size; i++) {
		//需要一个回调函数
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
	printf("姓名%s,年龄%d\n", p->name, p->age);
}
void test() {
	struct Person p1 = { "人1",18 };
	struct Person p2 = { "人2",19 };
	struct Person p3 = { "人3",20 };
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
