#pragma once
#include "CGameObject.h"
class GEnemy :
    public CGameObject
{
public:
    void shipDRAW(CDC* cDC) {
        ship.Draw(*cDC, x, y, 50, 50); //Ð¡µÐ»ú¿í50£¬¸ß50
    }
public:
    GEnemy();
};

