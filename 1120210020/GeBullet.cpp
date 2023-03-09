#include "pch.h"
#include "GeBullet.h"

GeBullet::GeBullet()
{
	//加载子弹图片
	CString imgPath = _T("res\\敌军子弹.png");
	ship.Load(imgPath);
	//加载爆炸图片
	CString imgPath1 = _T("res\\爆炸.png");
	Boom.Load(imgPath1);
	//设定子弹初始位置
	x = 365;
	y = 50;
}
