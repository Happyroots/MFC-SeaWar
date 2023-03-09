#pragma once
#include "Global_items.h"
class CChartPoint:public CObject
{
	DECLARE_SERIAL(CChartPoint)
protected:
	COLORREF	m_color;   // 图元颜色
	UINT		m_lineStyle; // 图元的线型
	int			m_lineWidth; // 图元的线宽	
public:
	CDC* pDC;
	CChartPoint();
	~CChartPoint();
	void DrawLine();
	void Serialize(CArchive& ar);
	char lon[20] = {};				//初始化，全为0
	char lat[20] = {};
	int type;
	char color[3] = { 0,0,0 };	    //字符描述
	char intr[20] = { "暂无" };	    //说明是哪种灯标，19个字够用了 
	CChartPoint* pNext;

public:
	CPoint m_begin, m_end;

	//操作函数
public:
	//CChartPoint operator=(const CChartPoint& cchartPoint);

private:

};

