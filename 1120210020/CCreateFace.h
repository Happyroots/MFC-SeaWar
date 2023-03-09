#pragma once
#include "CCreateLine.h"
#include "Head_CChartPoint.h"
class CCreateFace : public CCreateLine
{
protected:
    //Head_CChartPoint* Head;
    //CPoint* temp;
protected:
    COLORREF	m_color;   // 图元颜色
    UINT		m_lineStyle; // 图元的线型
    int			m_lineWidth; // 图元的线宽	
    //CChartPoint* FacePoint;
    //最多99条边，没有实现动态规划。。。
   // CChartPoint* Line;
    CPoint *Face;
    COLORREF	m_Facecolor;   // 面图元颜色
    int len;
public:
    CDC* pDC;
    //选点
    int OnLButtonDown(UINT nFlags, CPoint point);
    //画线
    void DrawFace();
    void DrawLine();
    CCreateFace();

    ~CCreateFace();

    
};

