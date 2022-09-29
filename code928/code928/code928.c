/*zdc
* 动态数组源码
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//结构体
struct  dynamicArray
{
	void** pAdrr;//维护真实在堆中创建的数组指针
	int m_capacity;
	int m_size;
};
//初始化函数
struct dynamicArray* initDynamicArray(int capacity) {
	if (capacity < 0) {
		return NULL;
	}
	//malloc space 
	struct dynamicArray* array = malloc(sizeof(struct dynamicArray));
	if (array == NULL) {
		return NULL;
	}
	//将真实数据开辟在堆区
	array->pAdrr = malloc(sizeof(void*) * capacity);
	array->m_capacity = capacity;
	array->m_size = 0;
	return array;
}
//数组元素的插入
void insertArray(struct dynamicArray* array, int pos, void* data) {
	if (array == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	//无效位置进行尾插法
	if (pos < 0 || pos>array->m_size) {
		pos = array->m_size;
	}
	//容量满了
	if (array->m_size == array->m_capacity) {
		//cal
		int newCapacity = array->m_capacity * 2;
		//init
		void** newSpace = malloc(sizeof(void*) * newCapacity);
		//copy
		memcpy(newSpace, array->pAdrr, sizeof(void*)* array->m_capacity);
		//free
		free(array->pAdrr);
		//update
		array->m_capacity = newCapacity;
		array->pAdrr = newSpace;
	}
	//insert
	//尾部每一个元素向后面移动，一直移动到开始
	//注意下标位置关系
	for (int i = array->m_size-1;i>=pos;i--) {
		array->pAdrr[i + 1] = array->pAdrr[i];		
	}
	array->pAdrr[pos] = data;
	array->m_size++;
}
//动态数组的遍历功能
//添加回调函数
void foreach(struct dynamicArray* array,void(*myPrint)(void*)) {
	if (array->pAdrr==NULL) {
		return;
	}
	//回调函数为空
	if (myPrint==NULL) {
		return;
	}
	for (int i = 0; i < array->m_size; i++) {
		//printf("动态数组元素第%d个元素是%d\n",i array->pAdrr[i]);
	//对void元素实现输出
		myPrint(array->pAdrr[i]);
	}

}
struct Person {
	char name[64];
	int age;
};
//回调函数的创建
void personPrint(void *data) {
	struct Person* p = data;
	printf("姓名%s,年龄%d\n",p->name, p->age);
}
int main()
{ 
	struct dynamicArray* array = initDynamicArray(5);
	struct Person p1 = { "人1",18 };
	struct Person p2 = { "人2",19 };
	struct Person p3 = { "人3",20 };
	insertArray(array, 3, &p1);
	insertArray(array, 2, &p2);
	insertArray(array, 1, &p3);
	printf("动态数组的大小为：%d，容量为%d\n",array->m_size,array->m_capacity );
	//这里并没有实现数组容量的添加
	foreach(array, personPrint);
	system("pause");
	return 0;		
}

