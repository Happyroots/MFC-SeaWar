#include "pch.h"
#include "GBullet.h"

GBullet::GBullet()
{

	//加载子弹图片
	CString imgPath = _T("res\\子弹.png");
	ship.Load(imgPath);
	//加载爆炸图片
	CString imgPath1 = _T("res\\爆炸.png");
	Boom.Load(imgPath1);
	//设定子弹初始位置
	x = 320;
	y = 600;
}
