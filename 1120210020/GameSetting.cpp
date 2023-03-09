// GameSetting.cpp: 实现文件
//

#include "pch.h"
#include "1120210020.h"
#include "GameSetting.h"
#include "afxdialogex.h"


// GameSetting 对话框

IMPLEMENT_DYNAMIC(GameSetting, CDialogEx)

GameSetting::GameSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GameSetting, pParent)
{

}

GameSetting::~GameSetting()
{
}

void GameSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_UserName, 玩家名称);
	DDX_Control(pDX, IDC_EDIT_keys, 自定义按键);
	DDX_Control(pDX, IDC_COMBO_Diffculty, 游戏难度);
}


BEGIN_MESSAGE_MAP(GameSetting, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_UserName, &GameSetting::OnEnChangeEditUsername)
	ON_EN_CHANGE(IDC_EDIT_keys, &GameSetting::OnEnChangeEditkeys)
	ON_CBN_SELCHANGE(IDC_COMBO_Diffculty, &GameSetting::OnCbnSelchangeComboDiffculty)
END_MESSAGE_MAP()


// GameSetting 消息处理程序


void GameSetting::OnEnChangeEditUsername()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	玩家名称.GetWindowTextW(Global_items::g_username);
}


void GameSetting::OnEnChangeEditkeys()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	自定义按键.GetWindowTextW(Global_items::g_ShipMoveCommand);
	//cmd = (LPSTR)(LPCTSTR)Global_items::g_ShipMoveCommand;
}


void GameSetting::OnCbnSelchangeComboDiffculty()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (游戏难度.GetCurSel())
	{
	case 0:
	{
		Global_items::g_GameDifficulty = 0;
		Global_items::g_score = 0;
		break;
	}
	case 1:
	{
		Global_items::g_GameDifficulty = 1;
		Global_items::g_score = 51;
		break;
	}
	case 2:
	{
		Global_items::g_GameDifficulty = 2;
		Global_items::g_score = 101;
		break;
	}

	default:
	{
		//Global_items::g_FaceColor = RGB(201, 185, 122);
		Global_items::g_GameDifficulty = 0;
		break;
	}
	}
}
