#include "pch.h"
#include "GMyShip.h"

GMyShip::GMyShip()
{

	//加载战机图片
	CString imgPath = _T("res\\本船.png");
	ship.Load(imgPath);
	//爆炸图片
	CString imgPath1 = _T("res\\爆炸.png");
	MyShipBoom.Load(imgPath1);
	//设定战机的初始位置
	x = 350;
	y = 630;
}
