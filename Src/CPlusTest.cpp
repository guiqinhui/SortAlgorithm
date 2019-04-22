// CPlusTest.cpp: 定义控制台应用程序的入口点。
//

#include   "stdio.h"  
#include "SortMethodClass.h"
class FatherClass
{
public:
	FatherClass()
	{
		printf("FatherClass Create!\n");
	}
 ~FatherClass()
	{
		printf("Delete   class   FatherClass\n");
	}
};
class SubClass:public FatherClass
{
public:
	SubClass()
	{
		printf("SubClass Create!\n");
	}
	~SubClass()
	{
		printf("Delete   class   SubClass\n");
	}
};
int main(int   argc, char*   argv[])
{
	unsigned char Array[] = {50,10,32,45,48,12,31,64,21,14,18};
	SortMethodClass SortArry;
	printf("Array：\r\n");
	for (int i = 0; i < sizeof(Array); i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\r\n");
	SortArry.SortData(SortArry.BUBBLE_SORT, SortArry.SORT_INCREASE, Array,sizeof(Array));
	printf("Sort Increase：\r\n");
	for (int i = 0; i < sizeof(Array); i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\r\n");
	getchar();
	return   0;
}
