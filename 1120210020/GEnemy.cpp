#include "pch.h"
#include "GEnemy.h"

GEnemy::GEnemy()
{
	//加载图片
	CString imgPath = _T("res\\敌船.png");
	ship.Load(imgPath);
	//设定小敌机的初始位置
	x = 350;
	y = 0;
}
