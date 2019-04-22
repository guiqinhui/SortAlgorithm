#pragma once
class SortMethodClass
{
public:
	SortMethodClass();
	bool SortData(int SortMethod,unsigned char *pSrcBuf, unsigned char *pDestBuf, int BufLen);
	bool Sort_Bubble(unsigned char *pSrcBuf, unsigned char *pDestBuf, int BufLen);
	bool Sort_Select();
	bool Sort_Quick();
	bool Sort_Insert();
	bool Sort_Shell();
	bool Sort_Merage();

	virtual ~SortMethodClass();
};

