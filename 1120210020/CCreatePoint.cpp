#include "pch.h"
#include "CCreatePoint.h"
#include "resource.h"

void CCreatePoint::OnLButtonDown(UINT nFlags, CPoint point)
{
	///准备海图背景位图
	CBitmap Chartbackg;						 //位图对象	
	//双缓冲
	CDC MemDC;

	pDC->SetBkMode(TRANSPARENT);	     //MFC静态文本背景为透明色
	pDC->SetTextColor(RGB(0, 0, 0));     //设置字体颜色

	//装载资源？从应用的可执行文件中加载一个命名的位图资源来初始化位图对象。
	switch (Global_items::g_BitmapType)
	{
	case 红色灯浮:
	{
		//为什么非得Copy一遍？,不用
		Chartbackg.LoadBitmap(IDB_BITMAP_redBouy);
		pDC->TextOut(point.x+40, point.y, Global_items::g_redLightIntro);
		break;
	}
	case 绿色灯浮:
	{
		Chartbackg.LoadBitmap(IDB_BITMAP_greenBouy);
		pDC->TextOut(point.x + 40, point.y,  Global_items::g_greenLightIntro);
		break;
	}
	case 水深点:
	{
		pDC->TextOut(point.x, point.y, Global_items::g_waterDepth);
		return;
		break;
	}
	default:
	{
		break;
	}
	}
	BITMAP ChartbackgInfo;// 3定义位图变量，
	Chartbackg.GetObject(sizeof(ChartbackgInfo), &ChartbackgInfo);//6将位图对象的图片放入到位图变量中

	MemDC.CreateCompatibleDC(pDC);		//与pDC兼容的CDC对象
	MemDC.SelectObject(&Chartbackg);		//获得位图句柄,传的是对象
	//将对象复制到显示界面上？
	//9图片由内存环境传送至设备环境，最后要传入位图变量，只是需要长度和宽度？
	pDC->BitBlt(point.x, point.y, ChartbackgInfo.bmWidth, ChartbackgInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
	
	//释放资源
	Chartbackg.DeleteObject();
	MemDC.DeleteDC();	//DC是有限的
}
