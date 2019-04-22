#pragma once
class SortMethodClass
{
public:
	enum EN_SORT_DIR
	{
		SORT_INCREASE = 0,
		SORT_DECREASE = 1
	};
	enum EN_SORT_METHOD
	{
		BUBBLE_SORT = 0,
		SEL_SORT,
		QUICK_SORT,
		INSERT_SORT,
		SHELL_SORT,
		MERGE_SORT,
	};
	int SortMethod;

	SortMethodClass();
	bool SortData(int SortMed,int SortDir,unsigned char *pSrcBuf, int BufLen);
	bool Sort_Bubble(int SortDir, unsigned char *pSrcBuf, int BufLen);
	bool Sort_Select(int SortDir, unsigned char *pSrcBuf, int BufLen);
	bool Sort_Quick();
	bool Sort_Insert();
	bool Sort_Shell();
	bool Sort_Merage();

	virtual ~SortMethodClass();
};

