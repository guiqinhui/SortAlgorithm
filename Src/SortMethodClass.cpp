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
//ð������
//����˼�룺�������Ƚϴ�С���ϴ�����³�����С����ð�����������ȽϽ���
//�㷨���Ӷ�O(n2)
bool SortMethodClass::Sort_Bubble(int SortDir, unsigned char *pSrcBuf,int BufLen)
{
	int i = 0,j = 0;
	unsigned char temp = 0;
	bool flag = false;//�Ż�
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
		{//δ�������ݽ�������ʾ�Ѿ��ź����ˣ�ֱ���˳�
			break;
		}
	}
	return true;
}
//ѡ������
//����˼�룺�ڳ���ΪN�����������У���һ�α���n-1�������ҵ���С����ֵ���һ��Ԫ�ؽ�����
//			�ڶ��α���n - 2�������ҵ���С����ֵ��ڶ���Ԫ�ؽ�����
//			������
//			��n - 1�α������ҵ���С����ֵ���n - 1��Ԫ�ؽ�����������ɡ�
//�㷨���Ӷ�O(n2)
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
//��������
//����˼�룺�ȴ�������ȡ��һ������Ϊkeyֵ��
//			���������С����ȫ������������ߣ����ڻ����������ȫ�����������ұߣ�
//			����������С�����ظ��ڶ�����ֱ��������ֻ��1������
//ƽ��ʱ�临�Ӷȣ�O(N*logN)
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
		//һ��Ҫ�ȴӺ���ǰ�ң��ȴ��ұ��ҵ�С�ڻ�׼ֵ����
		while((pSrcBuf[j] >= KeyValue)&&(i<j))
		{
			j--;
		}
		//�ٴ�ǰ������:������ҵ����ڻ�׼ֵ����
		while ((pSrcBuf[i] <= KeyValue) && (i<j))
		{
			i++;
		}
		if (i < j)
		{//���Ȼ�׼ֵС�Ļ���ߣ��Ȼ�׼ֵ��ķ��ұ�
			temp = pSrcBuf[i];
			pSrcBuf[i] = pSrcBuf[j];
			pSrcBuf[j] = temp;
		}
	}
	//����׼����λ
	pSrcBuf[Start] = pSrcBuf[i];
	pSrcBuf[i] = KeyValue;

	Sort_Quick(SortDir,pSrcBuf,Start, i - 1);
	Sort_Quick(SortDir,pSrcBuf,i+1,End);
	return true;
}

//��������
bool SortMethodClass::Sort_Insert()
{
	return false;
}
//ϣ������
bool SortMethodClass::Sort_Shell()
{
	return false;
}
//�鲢����
bool SortMethodClass::Sort_Merage()
{
	return false;
}

SortMethodClass::~SortMethodClass()
{
}
