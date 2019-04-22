#include <string.h>
#include   "stdio.h"  
#include "SortMethodClass.h"


SortMethodClass::SortMethodClass()
{
	SortMethod = BUBBLE_SORT;
}
//
bool SortMethodClass::SortData(int SortMed, int SortDir, unsigned char *pSrcBuf, int BufLen)
{
	SortMethod = SortMed;
	switch (SortMethod)
	{
		case BUBBLE_SORT:
		{
			Sort_Bubble(SortDir, pSrcBuf,BufLen);
		}break;
		case SEL_SORT:
		{
		}break;
		case QUICK_SORT:
		{
		}break;
		case INSERT_SORT:
		{
		}break;
		case SHELL_SORT:
		{
		}break;
		case MERGE_SORT:
		{
		}break;
		default:
		{
			printf("Sort Method[%d] is Not supported!", SortMethod);
			return false;
		};
	}
	return false;
}
//冒泡排序
//基本思想：两个数比较大小，较大的数下沉，较小的数冒起来，两两比较交换
//算法复杂度O(n2)
bool SortMethodClass::Sort_Bubble(int SortDir, unsigned char *pSrcBuf,int BufLen)
{
	int i = 0,j = 0;
	unsigned char temp = 0;
	bool flag = false;//优化
	if ((NULL == pSrcBuf)
		|| (0 > BufLen))
	{
		return false;
	}

	for (i=0;i<BufLen-1;i++)
	{
		flag = false;
		for (j = BufLen-1; j >i; j--)
		{
			if (pSrcBuf[j] < pSrcBuf[j-1])
			{
				temp = pSrcBuf[j];
				pSrcBuf[j] = pSrcBuf[j-1];
				pSrcBuf[j-1] = temp;
				flag = true;
			}
		}
		if (!flag)
		{//未发生数据交换，表示已经排好序了，直接退出
			break;
		}
	}
	return true;
}
//选择排序
//基本思想：在长度为N的无序数组中，第一次遍历n-1个数，找到最小的数值与第一个元素交换；
//第二次遍历n - 2个数，找到最小的数值与第二个元素交换；
//。。。
//第n - 1次遍历，找到最小的数值与第n - 1个元素交换，排序完成。
//算法复杂度O(n2)
bool SortMethodClass::Sort_Select(int SortDir, unsigned char *pSrcBuf, int BufLen)
{
	int i = 0, j = 0;
	unsigned char temp = 0;
	if ((NULL == pSrcBuf)
		|| (0 > BufLen))
	{
		return false;
	}
	for (i = 0; i<BufLen; i++)
	{
		for (j = i; j < BufLen; j++)
		{
			if (pSrcBuf[i] > pSrcBuf[j])
			{
				temp = pSrcBuf[i];
				pSrcBuf[i] = pSrcBuf[j];
				pSrcBuf[j] = temp;
			}
		}
	}
	return true;
}
//快速排序
//基本思想
//
bool SortMethodClass::Sort_Quick()
{

	return false;
}

//插入排序
bool SortMethodClass::Sort_Insert()
{
	return false;
}
//希尔排序
bool SortMethodClass::Sort_Shell()
{
	return false;
}
//归并排序
bool SortMethodClass::Sort_Merage()
{
	return false;
}

SortMethodClass::~SortMethodClass()
{
}
