#pragma once
#include "CGameObject.h"
class GMyShip :
    public CGameObject
{
public:
	CImage MyShipBoom;
public:
	GMyShip();
	//设定战机的大小
	void shipDRAW(CDC* cDC) 
	{
		ship.Draw(*cDC, x, y, 80, 80);
	}
	//加入爆炸效果函数
	void MyShipBoomDraw(CDC* cDC, int x, int y)
	{
		//战机被敌机碰撞将变成爆炸状
		MyShipBoom.Draw(*cDC, x, y, 100, 100);
	}
};

