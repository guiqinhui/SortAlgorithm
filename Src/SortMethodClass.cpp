#include <string.h>
#include   "stdio.h"  
#include "SortMethodClass.h"


SortMethodClass::SortMethodClass()
{
	SortMethod = BUBBLE_SORT;
}
void SortMethodClass::swap(unsigned char x, unsigned char y)
{
	return;
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
			Sort_Select(SortDir, pSrcBuf, BufLen);
		}break;
		case QUICK_SORT:
		{
			Sort_Quick(SortDir, pSrcBuf,0,BufLen);
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
//			第二次遍历n - 2个数，找到最小的数值与第二个元素交换；
//			。。。
//			第n - 1次遍历，找到最小的数值与第n - 1个元素交换，排序完成。
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
//基本思想：先从数列中取出一个数作为key值；
//			将比这个数小的数全部放在它的左边，大于或等于它的数全部放在它的右边；
//			对左右两个小数列重复第二步，直至各区间只有1个数。
//平均时间复杂度：O(N*logN)
bool SortMethodClass::Sort_Quick(int SortDir, unsigned char *pSrcBuf, int Start,int End)
{
	int i = Start, j = End;
	unsigned char temp = 0, KeyValue = 0;
	if ((NULL == pSrcBuf)
		|| (Start > End))
	{
		return false;
	}
	KeyValue = pSrcBuf[Start];
	while (i != j)
	{
		//一定要先从后往前找：先从右边找到小于基准值的数
		while((pSrcBuf[j] >= KeyValue)&&(i<j))
		{
			j--;
		}
		//再从前往后找:从左边找到大于基准值的数
		while ((pSrcBuf[i] <= KeyValue) && (i<j))
		{
			i++;
		}
		if (i < j)
		{//将比基准值小的换左边，比基准值大的放右边
			temp = pSrcBuf[i];
			pSrcBuf[i] = pSrcBuf[j];
			pSrcBuf[j] = temp;
		}
	}
	//将基准数归位
	pSrcBuf[Start] = pSrcBuf[i];
	pSrcBuf[i] = KeyValue;

	Sort_Quick(SortDir,pSrcBuf,Start, i - 1);
	Sort_Quick(SortDir,pSrcBuf,i+1,End);
	return true;
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
