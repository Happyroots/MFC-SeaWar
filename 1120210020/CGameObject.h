#pragma once
#include <afx.h>
class CGameObject :
    public CObject
{
    DECLARE_SERIAL(CGameObject)
public:
    CImage ship;
    int x;
    int y;
    //void shipDRAW(CDC* cDC) 
    //{  //设定船或子弹的大小
    //    ship.Draw(*cDC, x, y, 100, 50);//图片的宽为100，高50
    //}
    CGameObject();
};


