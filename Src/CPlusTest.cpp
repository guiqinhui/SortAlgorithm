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
	unsigned char Array[] = {9,3,5,10,8,6,4,2,7,1,11};
	SortMethodClass SortArry;
	printf("Array：\r\n");
	for (int i = 0; i < sizeof(Array); i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\r\n");
	if (SortArry.SortData(SortArry.INSERT_SORT, SortArry.SORT_INCREASE, Array, sizeof(Array)))
	{
		printf("Sort failed！！\r\n");
		getchar();
		return   0;
	}
	printf("Sort Increase：\r\n");
	for (int i = 0; i < sizeof(Array); i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\r\n");
	getchar();
	return   0;
}
