#pragma once
#include "Global_items.h"

enum BitmapType
{
	红色灯浮,
	绿色灯浮,
	水深点,
};

class CCreatePoint
{
protected:
	//CPoint P;
	CString tempstr;
public:
	CDC* pDC;
	CCreatePoint()
	{
		//P.x = P.y = 0;
		pDC = NULL;
		tempstr = _T("");
	}
	void OnLButtonDown(UINT nFlags, CPoint point);
};

