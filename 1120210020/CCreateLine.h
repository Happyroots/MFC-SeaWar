#pragma once
#include "CChartPoint.h"
#include "Global_items.h"

class CCreateLine :public CObject
{
    //既隐藏又不影响继承
protected:
 
	int Step;

public:
    CChartPoint* Line;

    CCreateLine();
    ~CCreateLine();

    //选点
    int OnLButtonDown(UINT nFlags, CPoint point);
    //画线
    //void DrawLine();
    //存储
    //void CCreateLine::Serialize(CArchive& ar);
};

