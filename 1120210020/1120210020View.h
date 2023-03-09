
// 1120210020View.h: CMy1120210020View 类的接口
//

#pragma once
#include "CCreateLine.h"
#include "CCreateFace.h"
#include "CCreatePoint.h"
#include "GMyShip.h"
#include "GEnemy.h"
#include "GBigEnemy.h"
#include "GBullet.h"
#include "GeBullet.h"



class CMy1120210020View : public CView
{
protected: // 仅从序列化创建
	CMy1120210020View() noexcept;
	DECLARE_DYNCREATE(CMy1120210020View)

// 特性
public:
	CMy1120210020Doc* GetDocument() const;
	//画图类
	CCreateLine* tempDrawLine;
	CCreateFace* tempDrawFace;
	CCreatePoint* tempDrawPoint;

	enum mode
	{
		海图 = 0,
		开始游戏 = 1,
		暂停游戏 = 2,
		继续游戏 = 3,
	};

	enum 游戏难度
	{
		第一关,
		第二关,
		第三关,
	};
	//游戏类
	GMyShip Myship;
	GEnemy Enemy[5];
	GBigEnemy BigEnemy;
	GBullet Bullet[30];
	GeBullet eBullet[6];
	CRect m_client;
	int Mode = 1;	//软件游戏模式还是画图模式
	char* cmd ;
	CString scoreOut;
	//为什么复制不了？
	CDC *cacheDc;
	int Tip;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy1120210020View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32794();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//afx_msg void OnRButtonDown(UINT nFlags, CPoint point, CDC* pDC);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void On32772();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32776();
	afx_msg void On32777();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int StartGame();
	//int Mode;
//	CDC cacheDc;
	int GetChartBack();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	int EndGame();
	afx_msg void On32779();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void On32780();
	afx_msg void On32781();
	afx_msg void On32782();
	afx_msg void On32783();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnCbnSelchangeComboDiffculty();
};

#ifndef _DEBUG  // 1120210020View.cpp 中的调试版本
inline CMy1120210020Doc* CMy1120210020View::GetDocument() const
   { return reinterpret_cast<CMy1120210020Doc*>(m_pDocument); }
#endif

