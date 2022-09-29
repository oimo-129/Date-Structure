// code928.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include<stdio.h>
#include<stdlib.h>
//dynamic array
//结构体
//struct  dynamicArray
//{
//	void** pAdrr;//维护真实在堆中创建的数组指针
//	int m_capacity;
//	int m_size;
//};
//struct dynamicArray* initDynamicArray(int capacity) {
//	if (capacity < 0) {
//		return NULL;
//	}
//	//malloc space 
//	struct dynamicArray* array = malloc(sizeof(struct dynamicArray));
//	if (array == NULL) {
//		return NULL;
//	}
//	//将真实数据开辟在堆区
//	array->pAdrr = malloc(sizeof(void*) * capacity);
//	array->m_capacity = capacity;
//	array->m_size = 0;
//	return array;
//}
struct  dynamicArray
{
	char* pAdrr;//维护真实在堆中创建的数组指针
	int m_capacity;
	int m_size;
};
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
	array->pAdrr = malloc(sizeof(char) * capacity);
	array->m_capacity = capacity;
	array->m_size = 0;
	return array;
}
int main()
{
	struct dynamicArray* array = initDynamicArray(5);
	printf("动态数组的大小为：%d，容量为%d\n",array->m_size,array->m_capacity );
	system("pause");
	return 0;
		
}

