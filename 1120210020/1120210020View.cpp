
// 1120210020View.cpp: CMy1120210020View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "1120210020.h"
#endif

#include "1120210020Doc.h"
#include "1120210020View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "DIALOG_EntityProperty.h"


#include "stdio.h"
#include "math.h"

// CMy1120210020View

IMPLEMENT_DYNCREATE(CMy1120210020View, CView)

BEGIN_MESSAGE_MAP(CMy1120210020View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy1120210020View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32794, &CMy1120210020View::On32794)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(32772, &CMy1120210020View::On32772)
	ON_COMMAND(ID_32774, &CMy1120210020View::On32774)
	ON_COMMAND(ID_32775, &CMy1120210020View::On32775)

	ON_COMMAND(ID_32776, &CMy1120210020View::On32776)
	ON_COMMAND(ID_32777, &CMy1120210020View::On32777)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_32779, &CMy1120210020View::On32779)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32780, &CMy1120210020View::On32780)
	ON_COMMAND(ID_32781, &CMy1120210020View::On32781)
	ON_COMMAND(ID_32782, &CMy1120210020View::On32782)
	ON_COMMAND(ID_32783, &CMy1120210020View::On32783)
	//ON_CBN_SELCHANGE(IDC_COMBO_Diffculty, &CMy1120210020View::OnCbnSelchangeComboDiffculty)
END_MESSAGE_MAP()

// CMy1120210020View 构造/析构

CMy1120210020View::CMy1120210020View() noexcept
{
	// TODO: 在此处添加构造代码
	tempDrawLine = NULL;
	tempDrawFace = NULL;
	tempDrawPoint = NULL;
	Mode = 1;//0海图 1游戏
	cacheDc = NULL;
	cacheDc = new CDC;
	Tip = 1;
	cmd = NULL;
}

CMy1120210020View::~CMy1120210020View()
{
	//ChartDC.DeleteDC();	//DC是有限的
	//cacheDc->DeleteDC();
	//cacheDc->DeleteDC();

}

BOOL CMy1120210020View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy1120210020View 绘图

void CMy1120210020View::OnDraw(CDC* pDC)
{
	CMy1120210020Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//->指向内存, ” .“(点) 选择元素
	CChart* temList = pDoc->head->hNext;	//赋予相同的地址，不用拷贝构造
	// TODO: 在此处为本机数据添加绘制代码
	while (TRUE)
	{
	if (temList->point->pNext)
	{
		temList->point = temList->point->pNext;
	}
	


//	Myship.shipDRAW(&cacheDc);//画战机
//
//
////子弹
//	for (int b1 = 0; b1 < 30; b1++)
//	{
//		//用坐标x,y 判断子弹是否和大战船碰撞，粗糙
//		//CRect类？
//		if (Bullet[b1].x < BigEnemy.x + 100 && Bullet[b1].x >BigEnemy.x - 100 && Bullet[b1].y < BigEnemy.y + 50 && Bullet[b1].y >BigEnemy.y - 50)
//		{	//如果碰撞了
//			int xx = BigEnemy.x;
//			int yy = BigEnemy.y;
//			Bullet[b1].BoomDRAW(&cacheDc, xx, yy);//若两者产生碰撞，则出现爆炸效果
//			Bullet[b1].y = Myship.y;
//			Bullet[b1].x = Myship.x + 30;//发生爆炸的子弹，重新回到战机的子弹口
//			BigEnemy.x = rand() % 400;  //大敌机从上面的随机位置重新出现
//			while (BigEnemy.x < 20)//如果太靠右，则重新生成
//				BigEnemy.x = rand() % 400;
//			BigEnemy.y = 0;
//		}
//		else if (Bullet[b1].y < 0)//如果子弹飞到最高处，重回战机子弹口
//		{
//			Bullet[b1].y = Myship.y;
//			Bullet[b1].x = Myship.x + 30;
//		}
//		else
//			Bullet[b1].y = Bullet[b1].y - 10;//否则，继续上升
//		for (int i1 = 0; i1 < 5; i1++)
//		{
//			if (Bullet[b1].x < Enemy[i1].x + 50 && Bullet[b1].x >Enemy[i1].x - 50 && Bullet[b1].y <Enemy[i1].y + 50 && Bullet[b1].y >Enemy[i1].y - 50)//判断每台小敌机是否和子弹碰撞
//			{
//				int xx1 = Enemy[i1].x;
//				int yy1 = Enemy[i1].y;
//				Enemy[i1].x = rand() % 400;//若碰撞，小敌机重新从上面的随机位置降落
//				while (Enemy[i1].x < 20)
//					Enemy[i1].x = rand() % 400;
//				Enemy[i1].y = -30;
//				Bullet[b1].BoomDRAW(&cacheDc, xx1, yy1);//爆炸状态
//				Bullet[b1].y = Myship.y;
//				Bullet[b1].x = Myship.x + 30;//子弹重新回到战机子弹口
//			}
//		}
//		Bullet[b1].shipDRAW(&cacheDc);//画子弹
//	}
//
//	//小敌机
//	for (int j = 0; j < 5; j++)
//	{	//判断战机是否和小战机碰撞
//		if (Myship.x < Enemy[j].x + 50 && Myship.x >Enemy[j].x - 50 && Myship.y < Enemy[j].y + 50 && Myship.y >Enemy[j].y - 50)
//		{
//			int xxx = Myship.x;
//			int yyy = Myship.y;
//			Myship.MyShipBoomDraw(&cacheDc, xxx, yyy);//若碰撞，发生战机爆炸
//			Sleep(500);//停止500ms
//			Enemy[j].x = rand() % 400;
//			//有用吗？
//			while (BigEnemy.x < 20)
//				Enemy[j].x = rand() % 400;//小敌机重新随机降落
//			BigEnemy.y = 0;
//			Myship.x = 300;
//			Myship.y = 500;//战机回到初始位置
//		}
//		//若小敌机走出游戏界面，则重新随机降落
//		else if (Enemy[j].y > 690)
//		{
//			Enemy[j].x = rand() % 400;
//			while (Enemy[j].x < 20)
//				Enemy[j].x = rand() % 400;
//			Enemy[j].y = 0;
//		}
//		Enemy[j].y += 10;//小战机下降
//		Enemy[j].shipDRAW(&cacheDc);
//	}
//
//	//大敌机
//	//判断战机是否和大敌机发生碰撞
//	if (Myship.x < BigEnemy.x + 100 && Myship.x >BigEnemy.x - 100 && Myship.y < BigEnemy.y + 80 && Myship.y >BigEnemy.y - 80)
//	{
//		int xxx = Myship.x;
//		int yyy = Myship.y;
//		Myship.MyShipBoomDraw(&cacheDc, xxx, yyy);//若碰撞，战机爆炸，大敌机重新随机降落
//		Sleep(500);//停止500ms
//		BigEnemy.x = rand() % 400;
//		while (BigEnemy.x < 20)
//			BigEnemy.x = rand() % 400;
//		BigEnemy.y = 0;
//		Myship.x = 300;//战机回到初始位置
//		Myship.y = 500;
//	}
//	if (BigEnemy.y < 650)//大敌机下降
//		BigEnemy.y = BigEnemy.y + 10;
//	else
//		BigEnemy.y = 0;//若大飞机飞出游戏界面 ，重新随机降落
//	BigEnemy.shipDRAW(&cacheDc); //画大敌机
	//画一次背景存到缓存DC（cacheDc）内
	CRect rc;
	GetClientRect(&rc);
	GetChartBack();
	//一次性贴入
	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), cacheDc, 0, 0, SRCCOPY);

	//ChartDC.BitBlt(0, 0, rc.Width(), rc.Height(), &cacheDc, 0, 0, SRCCOPY);

	//贴两回吗？一次背景，一次战船和子弹？会闪烁
	//销毁资源//DC资源
	cacheDc->DeleteDC();
	break;
	}//while(TRUE)
}//OnDraw()


// CMy1120210020View 打印


void CMy1120210020View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy1120210020View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy1120210020View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy1120210020View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMy1120210020View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy1120210020View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{

	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_ContextMENU);
	CMenu* pMenu;
	pMenu = menu.GetSubMenu(0);

	pMenu->EnableMenuItem(ID_32794, MF_BYCOMMAND | MF_ENABLED);
	//pMenu->EnableMenuItem(ID_32772, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	pMenu->Detach();
	menu.DestroyMenu();

}


// CMy1120210020View 诊断

#ifdef _DEBUG
void CMy1120210020View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1120210020View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1120210020Doc* CMy1120210020View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1120210020Doc)));
	return (CMy1120210020Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1120210020View 消息处理程序

//添加线
void CMy1120210020View::On32794()
{
	// TODO: 在此添加命令处理程序代码
	tempDrawLine = new CCreateLine;
}


void CMy1120210020View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//GetChartBack();
	CDC* pDC0 = GetDC();
	////获取屏幕长宽
	//CRect rc;
	//GetClientRect(&rc);
	//pDC0->BitBlt(0, 0, rc.Width(), rc.Height(), CMy1120210020View::cacheDc, 0, 0, SRCCOPY);

	//pDC->SelectObject(pOldPen);
	//设立基类，声明虚函数可以简化
	//利用基类操作派生类函数
	if (CMy1120210020View::tempDrawPoint)
	{
		//EndGame();
		tempDrawPoint->pDC = pDC0;
		tempDrawPoint->OnLButtonDown(nFlags, point);
	}
	if (CMy1120210020View::tempDrawLine)
	{
		tempDrawLine->Line->pDC = pDC0;
		tempDrawLine->OnLButtonDown(nFlags, point);
	}
	if (CMy1120210020View::tempDrawFace)
	{
		//需要PDC0画线
		tempDrawFace->pDC = pDC0;
		tempDrawFace->OnLButtonDown(nFlags, point);
	}

	ReleaseDC(pDC0);
	CView::OnLButtonDown(nFlags, point);
}


void CMy1120210020View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC* pDC0 = GetDC();
	if (tempDrawPoint)
	{
		delete tempDrawPoint;
		tempDrawPoint = NULL;
	}
	if (tempDrawLine)
	{
		delete tempDrawLine;
		tempDrawLine = NULL;
	}
	if (tempDrawFace)
	{
		//需要PDC0画 面
		tempDrawFace->pDC = pDC0;
		tempDrawFace->DrawFace();
		//释放资源
		delete tempDrawFace;
		tempDrawFace = NULL;
	}
	ReleaseDC(pDC0);
	CView::OnRButtonDown(nFlags, point);
}


void CMy1120210020View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	tempDrawFace = new CCreateFace;

}

//红灯浮
void CMy1120210020View::On32774()
{
	// TODO: 在此添加命令处理程序代码
	Global_items::g_BitmapType = 0;
	tempDrawPoint = new CCreatePoint;
}

//绿灯浮
void CMy1120210020View::On32775()
{
	// TODO: 在此添加命令处理程序代码
	Global_items::g_BitmapType = 1;
	tempDrawPoint = new CCreatePoint;
}


	//水深点
void CMy1120210020View::On32776()
{
	// TODO: 在此添加命令处理程序代码
	Global_items::g_BitmapType = 2;
	tempDrawPoint = new CCreatePoint;
}

//图元属性对话框
void CMy1120210020View::On32777()
{
	// TODO: 在此添加命令处理程序代码
	//直接使用标准对话框类，如CFontDialog
	DIALOG_EntityProperty dlg;
	if (dlg.DoModal() == IDOK)
	{
	}

}

//双击响应
void CMy1120210020View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CDC* pDC0 = GetDC();
	//if (tempDrawFace)
	//{
	//	//需要PDC0画 面
	//	tempDrawFace->pDC = pDC0;
	//	tempDrawFace->DrawFace();
	//}
	CView::OnLButtonDblClk(nFlags, point);
}
#include <Windows.h>
#include <mmsystem.h>
#include "GameSetting.h"
#pragma comment (lib, "winmm.lib")

int CMy1120210020View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	//testDC = new CDC;
	//testDC->CreateCompatibleDC(pDC);
	//CBitmap m_cacheCBitmap4;
	//m_cacheCBitmap4.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	//testDC->SelectObject(&m_cacheCBitmap4);

	// TODO:  在此添加您专用的创建代码
	 //Mode = 10;
	//CMy1120210020View::GetChartBack(CDC cDC);
	//CMy1120210020View::StartGame();
	//初始化战机坐标？

	/////*********初始化ChartDC*********/
	//CDC* pDC = GetDC();
	//cacheDc = new CDC;
	//cacheDc->CreateCompatibleDC(pDC);
	//CRect rc;
	//GetClientRect(&rc);
	//CBitmap m_cacheCBitmap3;
	//m_cacheCBitmap3.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	////缓冲DC选入缓冲位图           //CBitmap* pOldBit2 = 
	//cacheDc->SelectObject(&m_cacheCBitmap3);
	//m_cacheCBitmap3.DeleteObject();
	//ReleaseDC(pDC);
	///*********************************/


	int EnemyInterval = 30;
	for (int e3 = 0; e3 < 5; e3++)
	{
		Enemy[e3].x += EnemyInterval;//开始时，小飞机的横坐标相隔30
		EnemyInterval += 30;
		Enemy[e3].y -= EnemyInterval;//开始时，小飞机的纵坐标相隔30，起到延迟出现的效果
	}
	//小敌军子弹初始位置,敌机  **"初始位置" ** 的算法与之相同
	//EnemyInterval = 30;
	for (int e3 = 0; e3 < 5; e3++)
	{
		eBullet[e3].x = Enemy[e3].x+15;//开始时，小飞机的横坐标相隔30
		//EnemyInterval += 30;
		eBullet[e3].y = Enemy[e3].y + 50;//开始时，小飞机的纵坐标相隔30，起到延迟出现的效果
	}
	eBullet[5].x = BigEnemy.x+80;
	eBullet[5].y = BigEnemy.y + 50;
	//我军子弹一开始的位置
	int BulletNum = 0;
	for (int b2 = 0; b2 < 30; b2++)
	{
		Bullet[b2].y -= BulletNum;//开始时，子弹的纵坐标相隔25，起到延迟出现的效果
		Bullet[b2].x = Myship.x + 30;//子弹的横坐标在战机的正中间
		BulletNum += 25;
	}
	return 0;
}

//按时刷新，判断是否碰撞
void CMy1120210020View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//会闪烁
	switch (Mode)
	{
	case 暂停游戏:
	{
		return;
		break;
	}
	case 继续游戏:
	{
		break;
	}
	default:
	{
		break;
	}
	}
	GetChartBack();//在函数内初始化，做的不好可读性差
	CDC* pDC  = this->GetDC();   //获得当前窗口的DC   
	if (Global_items::g_score<51)
	{
	scoreOut.Format(L"分数：%d/50", Global_items::g_score);
	cacheDc->TextOut(0, 0, scoreOut);
	}
	else if (Global_items::g_score < 101)
	{
		//进来第一回睡觉
		if (Tip == 1)
		{
		CFont font;
		font.CreateFont(
			20, // nHeight
			10, // nWidth
			0, // nEscapement
			0, // nOrientation
			FW_NORMAL, // nWeight
			FALSE, // bItalic
			FALSE, // bUnderline
			0, // cStrikeOut
			ANSI_CHARSET, // nCharSet
			OUT_DEFAULT_PRECIS, // nOutPrecision
			CLIP_DEFAULT_PRECIS, // nClipPrecision
			DEFAULT_QUALITY, // nQuality
			DEFAULT_PITCH | FF_SWISS,
			L"Arial" // nPitchAndFamily
		);
		pDC->SelectObject(&font);//CFont* def_font = 
		pDC->TextOutW(500, 400, L"你已进入第二关！");
		font.DeleteObject();
		Tip++;
		Sleep(2000);
		Global_items::g_GameDifficulty = 第二关;
		}
		scoreOut.Format(L"分数：%d/50", Global_items::g_score - 50);
		cacheDc->TextOutW(0, 0, scoreOut);
	}
	else
	{
		if (Tip <= 2)
		{
		CFont font;
		font.CreateFont(
			20, // nHeight
			10, // nWidth
			0, // nEscapement
			0, // nOrientation
			FW_NORMAL, // nWeight
			FALSE, // bItalic
			FALSE, // bUnderline
			0, // cStrikeOut
			ANSI_CHARSET, // nCharSet
			OUT_DEFAULT_PRECIS, // nOutPrecision
			CLIP_DEFAULT_PRECIS, // nClipPrecision
			DEFAULT_QUALITY, // nQuality
			DEFAULT_PITCH | FF_SWISS,
			L"Arial" // nPitchAndFamily
		);
		pDC->SelectObject(&font);//CFont* def_font = 
		pDC->TextOutW(500, 350, L"敌人装备了导弹，\n");
		pDC->TextOutW(500, 400, L"你必须在被击中之前杀死BOSS！");
		font.DeleteObject();
		Tip++;
		Sleep(4000);//会停止OnTimer(),停止运行函数
		Global_items::g_GameDifficulty = 第三关;
		}

	}
/*********  双缓冲  *************/
	//贴图DC
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);			//与pDC兼容的CDC对象,  同类型？
	//获取屏幕长宽
	CRect rc;
	GetClientRect(&rc);
	//缓冲DC
	//CDC *cacheDc1;
	//cacheDc1 = cacheDc
	//cacheDc.CreateCompatibleDC(pDC);
	////缓存位图
	//CBitmap m_cacheCBitmap;
	//m_cacheCBitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	////缓冲DC选入缓冲位图
	//CBitmap* pOldBit = cacheDc.SelectObject(&m_cacheCBitmap);
	/*********************/

	////画背景？
	//GetClientRect(&m_client);   //获得窗口的尺寸  
	//CRect rect;
	//GetClientRect(rect);
	//cDC->FillSolidRect(rect, RGB(255, 255, 255));
	//先画战机，如果碰撞了，就拿爆炸图片覆盖掉
	Myship.shipDRAW(cacheDc);
	cacheDc->TextOutW(Myship.x, Myship.y+70, Global_items::g_username);//画玩家名字

	//我军子弹：碰撞大敌船，小敌船；出界，继续飞
	//逐一设置30个子弹
	for (int b1 = 0; b1 < 30; b1++)
	{
		//用坐标x,y 判断子弹是否和大战船碰撞，粗糙
		//CRect类？
		if (Bullet[b1].x < BigEnemy.x + 100 && Bullet[b1].x >BigEnemy.x - 20 && Bullet[b1].y < BigEnemy.y + 30 && Bullet[b1].y >BigEnemy.y - 20)
		{	//如果碰撞了
			if (Global_items::g_GameDifficulty == 第三关 && Tip == 3)
			{
				CFont font;
				font.CreateFont(
					20, // nHeight
					10, // nWidth
					0, // nEscapement
					0, // nOrientation
					FW_NORMAL, // nWeight
					FALSE, // bItalic
					FALSE, // bUnderline
					0, // cStrikeOut
					ANSI_CHARSET, // nCharSet
					OUT_DEFAULT_PRECIS, // nOutPrecision
					CLIP_DEFAULT_PRECIS, // nClipPrecision
					DEFAULT_QUALITY, // nQuality
					DEFAULT_PITCH | FF_SWISS,
					L"Arial" // nPitchAndFamily
				);
				pDC->SelectObject(&font);//CFont* def_font = 
				pDC->TextOutW(500, 350, L"你已通关！");
				font.DeleteObject();
				Global_items::g_GameDifficulty = 第一关;
				Tip++;
				Sleep(4000);
				EndGame();
				return;
			}
			Global_items::g_score +=3;
			int xx = BigEnemy.x;
			int yy = BigEnemy.y;
			Bullet[b1].BoomDRAW(cacheDc, xx, yy);//若两者产生碰撞，则出现爆炸效果
			//子弹
			Bullet[b1].y = Myship.y+20;
			Bullet[b1].x = Myship.x + 30;//发生爆炸的子弹，重新回到战机的子弹口
			//大敌船
			BigEnemy.x = rand() % 1000;  //大敌机从上面的随机位置重新出现
			while (BigEnemy.x < 350)//如果太靠右，则重新生成
				BigEnemy.x = rand() % 400;
			BigEnemy.y = 0;
		}
		else if (Bullet[b1].y < 0)//如果子弹飞到最高处，重回战机子弹口
		{
			Bullet[b1].y = Myship.y+20;
			Bullet[b1].x = Myship.x + 30;
		}
		else if (TRUE)
		{
			//每个小敌船逐一判断
			for (int i1 = 0; i1 < 5; i1++)
			{
				//判断每台小敌机是否和子弹碰撞
				if (Bullet[b1].x < Enemy[i1].x + 50 && Bullet[b1].x >Enemy[i1].x - 50 && Bullet[b1].y <Enemy[i1].y + 50 && Bullet[b1].y >Enemy[i1].y - 50)
				{
					Global_items::g_score++;
					int xx1 = Enemy[i1].x;
					int yy1 = Enemy[i1].y;
					Enemy[i1].x = rand() % 1000;//若碰撞，小敌机重新从上面的随机位置降落
					while (Enemy[i1].x < 350)
						Enemy[i1].x = rand() % 1000;
					Enemy[i1].y = -30;
					Bullet[b1].BoomDRAW(cacheDc, xx1, yy1);//爆炸状态
					Bullet[b1].y = Myship.y + 20;
					Bullet[b1].x = Myship.x + 30;//子弹重新回到战机子弹口
				}
			}
		}

		Bullet[b1].y = Bullet[b1].y - 20;//否则，继续上升


		//前面坐标属性都设置完了，就可以画了
		Bullet[b1].shipDRAW(cacheDc);//画子弹
	}

	//小敌机
	for (int j = 0; j < 5; j++)
	{	//判断战机是否和小战机碰撞，比较
		if (Myship.x < Enemy[j].x + 50 && Myship.x >Enemy[j].x - 50 && Myship.y < Enemy[j].y + 50 && Myship.y >Enemy[j].y - 50)
		{
			Global_items::g_score -=5;
			int xxx = Myship.x;
			int yyy = Myship.y;
			Myship.MyShipBoomDraw(pDC, xxx, yyy);//若碰撞，发生战机爆炸
			Sleep(2000);//停止500ms
			Enemy[j].x = rand() % 1000;
			//有用吗？
			while (BigEnemy.x < 350)
				Enemy[j].x = rand() % 1000;//小敌机重新随机降落
			BigEnemy.y = 0;
			Myship.x = 300;
			Myship.y = 500;//战机回到初始位置
		}
		//若小敌机走出游戏界面，则重新随机降落
		else if (Enemy[j].y > 690)
		{
			Enemy[j].x = rand() % 1000;
			while (Enemy[j].x < 350)
				Enemy[j].x = rand() % 1000;
			Enemy[j].y = 0;
		}
		Enemy[j].y += 5;//小战机下降
		Enemy[j].shipDRAW(cacheDc);
	}

	//大敌机
	//判断战机是否和大敌机发生碰撞
	if (Myship.x < BigEnemy.x + 100 && Myship.x >BigEnemy.x - 100 && Myship.y < BigEnemy.y + 80 && Myship.y >BigEnemy.y - 80)
	{
		Global_items::g_score -= 5;
		int xxx = Myship.x;
		int yyy = Myship.y;
		//直接在屏幕上画,不会闪烁,画完直接睡觉
		// 不重叠会有"尾迹",重叠会闪烁
		//睡完直接重绘
		Myship.MyShipBoomDraw(pDC, xxx, yyy);//若碰撞，战机爆炸，大敌机重新随机降落
		Sleep(2000);//停止500ms
		//画新图
		//大敌船
		BigEnemy.x = rand() % 1000;
		while (BigEnemy.x < 350)
			BigEnemy.x = rand() % 1000;
		BigEnemy.y = 0;
		//本船
		Myship.x = 300;//战机回到初始位置
		Myship.y = 500;
	}
	if (BigEnemy.y < 700)//大敌机没出界
		BigEnemy.y = BigEnemy.y + 5;
	else
	{
		BigEnemy.x = rand() % 1000;
		while (BigEnemy.x < 350)
			BigEnemy.x = rand() % 1000;
		BigEnemy.y = 0;//若大飞机飞出游戏界面 ，重新随机降落
	}
	BigEnemy.shipDRAW(cacheDc); //画大敌机
	//敌军子弹
	switch (Global_items::g_GameDifficulty)
	{
	case 第一关:
	{
		break;
	}
	case 第二关://直弹
	{
		//逐一画出敌军子弹
		for (int eb=0;eb<6;eb++)
		{
			//1.敌军子弹与本船碰撞
			if (eBullet[eb].x>Myship.x && eBullet[eb].x<Myship.x+80 && 
				eBullet[eb].y<Myship.y+80 && eBullet[eb].y > Myship.y -20)
			{
				Global_items::g_score -= 5;
				//睡觉，本船爆炸
				Myship.MyShipBoomDraw(pDC,Myship.x, Myship.y);
				Sleep(2000);
				//下一帧图片
				//子弹回到敌船子弹口
				if (eb<5)//小敌船
				{
					eBullet[eb].x = Enemy[eb].x+15;
					eBullet[eb].y = Enemy[eb].y + 50;
				}
				else//大敌船
				{
					eBullet[eb].x = BigEnemy.x + 40;
					eBullet[eb].y = BigEnemy.y + 50;
				}
				//战机回到初始位置
				Myship.x = 350;
				Myship.y = 600;
			}

			// 2.没碰撞，越界了,回到子弹口
			else if(eBullet[eb].y>800)
			{
				//子弹回到敌船子弹口
				if (eb < 5)//小敌船
				{
					eBullet[eb].x = Enemy[eb].x + 15;
					eBullet[eb].y = Enemy[eb].y + 50;
				}
				else//大敌船
				{
					eBullet[eb].x = BigEnemy.x + 40;
					eBullet[eb].y = BigEnemy.y + 50;
				}
			}

			else//没意外情况，继续向下走
				//继续游戏的时候子弹与敌船错位
			{
				eBullet[eb].y += 10;

			}
			eBullet[eb].shipDRAW(cacheDc);
		}
		break;
	}
	case 第三关://追踪弹
	{
		//逐一画出敌军子弹
		for (int eb = 0; eb < 6; eb++)
		{
			//1.敌军子弹与本船碰撞
			if (eBullet[eb].x > Myship.x && eBullet[eb].x < Myship.x + 80 &&
				eBullet[eb].y<Myship.y + 80 && eBullet[eb].y > Myship.y - 20)
			{
				Global_items::g_score -= 5;
				//睡觉，本船爆炸
				Myship.MyShipBoomDraw(pDC, Myship.x, Myship.y);
				Sleep(2000);
				//下一帧图片
				//子弹回到敌船子弹口
				if (eb < 5)//小敌船
				{
					eBullet[eb].x = Enemy[eb].x + 15;
					eBullet[eb].y = Enemy[eb].y + 50;
				}
				else//大敌船
				{
					eBullet[eb].x = BigEnemy.x + 40;
					eBullet[eb].y = BigEnemy.y + 50;
				}
				//战机回到初始位置
				Myship.x = 350;
				Myship.y = 600;
			}

			// 2.没碰撞，越界了,回到子弹口
			else if (eBullet[eb].y > 800)
			{
				//子弹回到敌船子弹口
				if (eb < 5)//小敌船
				{
					eBullet[eb].x = Enemy[eb].x + 15;
					eBullet[eb].y = Enemy[eb].y + 50;
				}
				else//大敌船
				{
					eBullet[eb].x = BigEnemy.x + 40;
					eBullet[eb].y = BigEnemy.y + 50;
				}
			}
			else//没意外情况，继续向下走
			{
				int x_dir = ((Myship.x - eBullet[eb].x)*2) / (abs(Myship.x - eBullet[eb].x)+1);//避免除以0
				int y_dir = (Myship.y - eBullet[eb].y)*2 / (abs(Myship.y - eBullet[eb].y+1)+1);
				eBullet[eb].x += x_dir*8;
				eBullet[eb].y += y_dir*8;

			}
			eBullet[eb].shipDRAW(cacheDc);
		}
		break;
	}
	}



	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), cacheDc, 0, 0, SRCCOPY);
	//销毁资源//DC资源
	//m_cacheCBitmap.DeleteObject();
	cacheDc->DeleteDC();
	ReleaseDC(pDC);


	CView::OnTimer(nIDEvent);
}


int CMy1120210020View::StartGame()
{
	// TODO: 在此处添加实现代码.
	//if (Mode == 1)
	//{
		// 游戏模式
		//IUserNotification::PlaySound(_T("res\\youxi.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//循环播放背景音乐
		//播放音乐
		if (0 == mciSendString((L"open res\\BackMusic.mp3  Alias BackMusic")
			, NULL, 0, NULL))//打开背景音乐
		{
			mciSendString(_T("play BackMusic repeat"), NULL, 0, NULL);//播放
			//mciSendString(_T("close BackMusic"), NULL, 0, m_hWnd);//结束?
		}
		//消息
		this->SetTimer(1, 100, NULL);//设置一个定时器"1"

	//}
	/************准备资源***************/ 
		//获取屏幕长宽
		CRect rc;
		GetClientRect(&rc);
		//缓冲DC
		CDC GameDC;
		CDC* pDC = GetDC();
		GameDC.CreateCompatibleDC(pDC);
		//缓存位图
		CBitmap m_cacheCBitmap2;
		m_cacheCBitmap2.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
		//缓冲DC选入缓冲位图           //CBitmap* pOldBit2 = 
		GameDC.SelectObject(&m_cacheCBitmap2);

		/**************绘图****************/




		/************销毁资源***************/
		ReleaseDC(&GameDC);
		ReleaseDC(pDC);
		m_cacheCBitmap2.DeleteObject();


	return 0;
}


int CMy1120210020View::GetChartBack()
{
	// TODO: 在此处添加实现代码.
	/*********  双缓冲  *************/
	CDC* pDC = GetDC();
	//贴图DC
	CDC MemDC;//获取与位图大小的屏幕？
	MemDC.CreateCompatibleDC(pDC);			//与pDC兼容的CDC对象,  同类型？
	//获取屏幕长宽
	CRect rc;
	GetClientRect(&rc);
	//每次要使用的时候初始化//画完一次图就要销毁
	CMy1120210020View::cacheDc = new CDC;
	CMy1120210020View::cacheDc->CreateCompatibleDC(pDC);
	CBitmap m_cacheCBitmap4;
	m_cacheCBitmap4.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	CMy1120210020View::cacheDc->SelectObject(&m_cacheCBitmap4);

	/*********************/
	//添加背景，点类
	//准备海图背景位图
	CBitmap Chartbackg;						 //位图对象	
	 //装载资源？从应用的可执行文件中加载一个命名的位图资源来初始化位图对象。
	switch (Global_items::g_GameDifficulty)
	{
	case 第一关:
	{
		Chartbackg.LoadBitmap(IDB_BITMAP_backg);
		break;
	}
	case 第二关:
	{
		Chartbackg.LoadBitmap(IDB_BITMAP_superBack);
		break;
	}
	case 第三关:
	{
		Chartbackg.LoadBitmap(IDB_BITMAP_diff3);
		break;

	}
	}
	BITMAP ChartbackgInfo;// 3定义位图变量，
	Chartbackg.GetObject(sizeof(ChartbackgInfo), &ChartbackgInfo);//6将位图对象的图片放入到位图变量中
	MemDC.SelectObject(&Chartbackg);		//获得位图句柄,传的是对象
	//9图片由内存环境传送至缓存环境，最后要传入位图变量，只是需要长度和宽度？
	//ChartbackgInfo.bmWidth，   贴背景   //Copy
	cacheDc->BitBlt(0, 0, ChartbackgInfo.bmWidth, ChartbackgInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
	CMy1120210020View::cacheDc->BitBlt(0, 0, ChartbackgInfo.bmWidth, ChartbackgInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
	Chartbackg.DeleteObject();//卸磨杀驴
	//准备红灯浮位图
	CBitmap Chart_redlight;
	Chart_redlight.LoadBitmap(IDB_BITMAP_redBouy);
	BITMAP Chart_redlightInfo;// 3定义位图变量，
	Chart_redlight.GetObject(sizeof(Chart_redlightInfo), &Chart_redlightInfo);//6将位图对象的图片放入到位图变量中
	//红灯浮
	MemDC.SelectObject(&Chart_redlight);
	cacheDc->SetBkMode(TRANSPARENT);	     //MFC静态文本背景为透明色
	cacheDc->SetTextColor(RGB(0, 0, 0));     //设置字体颜色
	cacheDc->TextOut(1000 + 40, 300, L"大连航道3");
	cacheDc->TextOut(1000 + 43, 300 + 20, L"E1(2)R.4");
	cacheDc->BitBlt(1000, 300, Chart_redlightInfo.bmWidth, Chart_redlightInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
	Chart_redlight.DeleteObject();//卸磨杀驴
	//准备绿灯浮位图
	CBitmap Chart_greenlight;
	//与pDC适配
	//Chart_greenlight.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	Chart_greenlight.LoadBitmap(IDB_BITMAP_greenBouy);
	BITMAP Chart_greenlightInfo;
	Chart_greenlight.GetObject(sizeof(Chart_greenlightInfo), &Chart_greenlightInfo);
	//绿灯浮
	MemDC.SelectObject(&Chart_greenlight);//选完位图立马贴上！
	cacheDc->BitBlt(600, 700, Chart_redlightInfo.bmWidth, Chart_redlightInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);
	Chart_greenlight.DeleteObject();//卸磨杀驴
	cacheDc->TextOut(600 + 40, 700, L"大连航道H5");
	cacheDc->TextOut(600 + 40, 700 + 20, L"E1(2)G.6");

	//一、绘制点类
	//绘制水深点
	//准备参数
	//Point数组 11个Point
	CPoint* waterDepth = new CPoint[11];
	const double PI = 3.14159;
	for (int i = 0; i < 11; i++)
	{
		waterDepth[i].x = 100 + i * 50;
		waterDepth[i].y = 200 + (i % 2) * 50;

		//1.1水深点
		CString s;
		s.Format(_T("%d"), 200 + (i % 2) * 50);
		//s = "100 + i * 50";
		//pDC->Ellipse(pPoint[i].x - 5, pPoint[i].y - 5, pPoint[i].x + 5, pPoint[i].y + 5);
		//waterDepth[10] = waterDepth[0];

		//pDC->SetBkColor(RGB(0, 255, 0));//设置背景颜色
		cacheDc->TextOut(100 + i * 50, 200 + (i % 2) * 50, s);
	}
	//三、绘制面类
	//3.1陆地
	const int L_qury = 200;
	const int B_qury = 100;
	CPoint* land = new CPoint[16];
	land[0].x = land[0].y = land[15].x = 0;
	land[1].y = 150;
	land[2].y = land[3].x = land[3].y = land[4].x = land[7].x = land[8].x = land[11].x = land[12].x = 200;
	land[4].y = land[5].y = 300;
	land[1].x = land[2].x = land[5].x = land[6].x = land[6].y = land[7].y = land[9].x = land[10].x = land[13].x = land[14].x = 400;
	land[8].y = land[9].y = 500;
	land[10].y = land[11].y = 600;
	land[12].y = land[13].y = 700;
	land[14].y = 750;
	land[15].y = 920;

	//准备画笔
	CPen newPen1(PS_DASHDOTDOT, 2,
		(COLORREF)RGB(201, 185, 122));
	CPen* pOldPen1 = cacheDc->SelectObject(&newPen1);	//为当前环境选择画笔

	//填充
	CBrush NewBrush1, * pOldBrush1;
	NewBrush1.CreateSolidBrush(RGB(201, 185, 122));	//实心刷子
	pOldBrush1 = cacheDc->SelectObject(&NewBrush1);
	cacheDc->SetPolyFillMode(WINDING);//填充模式
	//绘制多边形
	cacheDc->Polygon(land, 16);
	//pDoc->	//获取文档？
		//画笔资源
	cacheDc->SelectObject(&pOldBrush1);
	cacheDc->SelectObject(pOldPen1);		//销毁画笔，参数是指针
	//cacheDc.BitBlt(0, 0, rc.Width(), rc.Height(), &MemDC, 0, 0, SRCCOPY);
	MemDC.DeleteDC();	//DC是有限的
	//cacheDc->DeleteDC();
	m_cacheCBitmap4.DeleteObject();
	ReleaseDC(pDC);

	return 0;
}


BOOL CMy1120210020View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值CView::OnEraseBkgnd(pDC)

	return TRUE;
}


int CMy1120210020View::EndGame()
{
	// TODO: 在此处添加实现代码.
	mciSendString(_T("close BackMusic"), NULL, 0, m_hWnd);//结束?
	this->KillTimer(1);//设置一个定时器
	Global_items::g_score = 0;
	Tip = 1;
	//Global_items::g_GameDifficulty = 0;
	Invalidate();
	return 0;
}

//开始游戏
void CMy1120210020View::On32779()
{
	// TODO: 在此添加命令处理程序代码
	StartGame();
	//Draw?
}


void CMy1120210020View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//Mode += 1;
	//CString test;
	//test.Format(L"Mode = %d",Mode);
	//AfxMessageBox(test);
	//char *cmd = (LPSTR)(LPCTSTR)Global_items::g_ShipMoveCommand;
	if (nChar == 37  )//向左移
	{
		if (Myship.x > 350)
			Myship.x -= 10;
	}

	else  if (nChar == 39)//向右移
	{
			if (Myship.x < 1000)
				Myship.x += 10;
	}
	else if (nChar == 38)//向上
	{
		if (Myship.y > 0)
			Myship.y -= 10;
	}
	else if (nChar == 40)//向下
	{
		if (Myship.y < 700)
			Myship.y += 10;

	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

//结束游戏
void CMy1120210020View::On32780()
{
	// TODO: 在此添加命令处理程序代码
	EndGame();
}

//暂停游戏
void CMy1120210020View::On32781()
{
	// TODO: 在此添加命令处理程序代码
	Mode = 暂停游戏;
}

//继续游戏
void CMy1120210020View::On32782()
{
	// TODO: 在此添加命令处理程序代码
	Mode = 继续游戏;
}

//游戏设置
void CMy1120210020View::On32783()
{
	// TODO: 在此添加命令处理程序代码
	Mode = 暂停游戏;
	GameSetting dlg1;
	//响应确定和取消键
	if (dlg1.DoModal() == IDOK)
	{
		Mode = 继续游戏;
	}
	else if (dlg1.DoModal() == IDCANCEL)
	{
		Mode = 继续游戏;
	}
}


BOOL CMy1120210020View::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	cmd = (LPSTR)(LPCTSTR)Global_items::g_ShipMoveCommand;
	if (pMsg->wParam == cmd[4])//向左移
	{
		if (Myship.x > 350)
			Myship.x -= 10;
	}

	else  if (pMsg->wParam == cmd[6])//向右移

	{
		if (Myship.x < 1000)
			Myship.x += 10;
	}
	else if (pMsg->wParam == cmd[0])//向上
	{
		if (Myship.y > 0)
			Myship.y -= 10;
	}
	else if (pMsg->wParam == cmd[2])//向下
	{
		if (Myship.y < 700)
			Myship.y += 10;

	}

	return CView::PreTranslateMessage(pMsg);
}


//void CMy1120210020View::OnCbnSelchangeComboDiffculty()
//{
//	// TODO: 在此添加控件通知处理程序代码
//		// TODO: 在此添加控件通知处理程序代码
//	GameSetting tempdig;
//	switch (tempdig.游戏难度.GetCurSel())
//	{
//	case 0:
//	{
//		/*Global_items::g_GameDifficulty = 0;*/
//		break;
//	}
//	case 1:
//	{
//		/*Global_items::g_GameDifficulty = 1;*/
//		Score = 20;
//		break;
//	}
//	case 2:
//	{
//		//Global_items::g_GameDifficulty = 2;
//		Score = 40;
//		break;
//	}
//
//	default:
//	{
//		//Global_items::g_FaceColor = RGB(201, 185, 122);
//		Global_items::g_GameDifficulty = 0;
//		break;
//	}
//	}
//}
