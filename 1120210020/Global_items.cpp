#include "pch.h"
#include "Global_items.h"
#ifndef _CGlobal
#define _CGlobal
//对全局变量初始化
COLORREF	Global_items::g_CurColor = RGB(180, 91, 186); //？色
COLORREF	Global_items::g_FaceColor = RGB(201, 185, 122);
int			Global_items::g_CurLineStyle = PS_DASH; //实线
int			Global_items::g_CurLineWidth = 5; //宽1
int			Global_items::g_BitmapType = 0; //默认红色灯浮
CString		Global_items::g_redLightIntro = _T("大连航道3，E1(2)R.4");
CString		Global_items::g_greenLightIntro = _T("大连航道H5，E1(2)G.6");
CString		Global_items::g_waterDepth = _T("0");
CString		Global_items::g_username = _T("1120210020");
CString		Global_items::g_ShipMoveCommand = _T("WASD");
int			Global_items::g_GameDifficulty = 0;
int			Global_items::g_score = 0;
Global_items::Global_items()
{
}

#endif // !CGlobal
