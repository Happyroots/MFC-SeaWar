#pragma once
class Global_items
{
public:
	static int					g_CurLineStyle;
	static int					g_CurLineWidth;
	static COLORREF				g_CurColor;
	static COLORREF				g_FaceColor;
	static int					g_BitmapType;
	static CString				g_redLightIntro;
	static CString				g_greenLightIntro;
	static CString				g_waterDepth;
	static CString				g_username;
	static CString				g_ShipMoveCommand;
	static int					g_GameDifficulty;
	static int					g_score;
public:
	Global_items();
};

