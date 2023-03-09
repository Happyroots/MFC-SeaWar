#pragma once
#include "CGameObject.h"
class GBigEnemy :
	public CGameObject
{
public:

	void shipDRAW(CDC* cDC) {  //设定大敌机的大小
		ship.Draw(*cDC, x, y, 100, 50);//图片的宽为100，高50
	}
public:
	GBigEnemy();
};

