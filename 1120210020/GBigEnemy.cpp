#include "pch.h"
#include "GBigEnemy.h"

GBigEnemy::GBigEnemy()
{
	//加载图片
	CString imgPath = _T("res\\大敌船.png");
	ship.Load(imgPath);
	//初始化大敌机的位置
	x = 300;
	y = 0;
}
