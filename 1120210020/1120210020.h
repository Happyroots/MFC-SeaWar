
// 1120210020.h: 1120210020 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号
#include "Global_items.h"

// CMy1120210020App:
// 有关此类的实现，请参阅 1120210020.cpp
//

class CMy1120210020App : public CWinAppEx
{
public:
	CMy1120210020App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1120210020App theApp;
