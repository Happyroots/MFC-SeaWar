#include "pch.h"
#include "CCreateFace.h"


CCreateFace::CCreateFace()
{
	m_color = Global_items::g_CurColor;
	m_lineStyle = Global_items::g_CurLineStyle;
	m_lineWidth = Global_items::g_CurLineWidth;
	Face = new CPoint[101]; 
	m_Facecolor = Global_items::g_FaceColor;
	Line = NULL;
	len = 0;
}

CCreateFace::~CCreateFace()
{
	delete[]Face;
	delete Line;
}


void CCreateFace::DrawFace()
{

	//准备资源CDC* pDC
	//CDC* pDC = GetDC();
	//CPoint *Face = new CPoint[len];
	//CChartPoint* Headp = Head->P;
	//while (Head)
	//{
	//	*Face = Headp->m_begin;
	//	Headp = Headp->pNext;
	//}
	 
	//封闭图形
	Face[len] = Face[0];
	//画笔
	CPen	pen;
	//参数顺序：样式，宽度，颜色
	pen.CreatePen(m_lineStyle, m_lineWidth, m_Facecolor);	//不擦除，直接覆盖
	CPen* pOldPen1 = pDC->SelectObject(&pen); // 得到原来的画笔
	//刷子
	CBrush NewBrush, * pOldBrush;
	NewBrush.CreateSolidBrush(m_Facecolor);	//实心刷子
	pOldBrush = pDC->SelectObject(&NewBrush);
	pDC->SetPolyFillMode(WINDING);//填充模式

	/******画图********/
	//pDC无效? //在一个大括号里创建完就
	pDC->Polygon(Face,len+1);
	/***************/

	//销毁资源
	pDC->SelectObject(&pOldBrush);
	//pDC->SelectObject(pOldPen1);

	//ReleaseDC(*pDC);
	//pDC = NULL;
}




int CCreateFace::OnLButtonDown(UINT nFlags, CPoint point)
{
	//FacePoint = new CChartPoint;
	//if (len == 0)
	//{
	//	//地址相同
	//	//那应该操作同一块内存啊
	//	Head = new Head_CChartPoint;
	//	Head->P = FacePoint;
	//}
	switch (Step)
	{
	case 0:
	{	
		Line = new CChartPoint;
		Line->m_begin = point;
		//temp = Line->m_end;
		//Line = Line->pNext;
		break;
	}
	case 1:
	{
		//Line = new CChartPoint;
		Line->m_end = point;
		//Line->m_begin = point;
		DrawLine();
		//Step = -1;
		//画折线？
		Step = 0;
		Line->m_begin = Line->m_end;
		//Line = Line->pNext;
		//Line = NULL;
		break;
	}
	}
	Face[len] = point;
	len++;
	Step++;

	//如何析构？
	//FacePoint->m_begin = point;
	//FacePoint = FacePoint->pNext;
	return Step;
}

void CCreateFace::DrawLine()
{

	//准备资源CDC* pDC
	//CDC* pDC = GetDC();
	CPen	pen;
	//参数顺序：样式，宽度，颜色
	pen.CreatePen(m_lineStyle, m_lineWidth, m_color);
	CPen* pOldPen1 = pDC->SelectObject(&pen); // 得到原来的画笔

	/******画图********/
	//pDC无效? //在一个大括号里创建完就
	pDC->MoveTo(Line->m_begin);
	pDC->LineTo(Line->m_end);
	/***************/

	//销毁资源
	pDC->SelectObject(pOldPen1);

	//ReleaseDC(*pDC);
	//pDC = NULL;
}

