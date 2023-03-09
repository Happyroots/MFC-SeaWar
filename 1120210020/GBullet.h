#pragma once
#include "CGameObject.h"
class GBullet :
    public CGameObject
{
public:
    CImage Boom;
public:
    GBullet();

	//设置子弹的大小;
	void shipDRAW(CDC* cDC) {
		ship.Draw(*cDC,  x,  y, 20, 20);
	}
	//设置爆炸效果
	void BoomDRAW(CDC* cDC, int x, int y) {
		Boom.Draw(*cDC, x, y, 50, 50);//子弹碰到敌机，将会变成爆炸状
	}
};

