// DIALOG_EntityProperty.cpp: 实现文件
//

#include "pch.h"
#include "1120210020.h"
#include "DIALOG_EntityProperty.h"
#include "afxdialogex.h"


// DIALOG_EntityProperty 对话框

IMPLEMENT_DYNAMIC(DIALOG_EntityProperty, CDialogEx)

DIALOG_EntityProperty::DIALOG_EntityProperty(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EntityProperty, pParent)
	/*, 线宽(0)*/
{

	//为什么代码不好用？
	//添加字符串内容
	//线颜色.AddString(L"红花");
	//线颜色.AddString(L"雪碧");

	//线颜色.SetCurSel(1);//显示显示第1项

	////获取组合框中当前选中项的下标
	//int index = 线颜色.GetCurSel();
	//CString str;
	//线颜色.GetLBText(index, str); //获取指定下标的内容
	//MessageBox(str);

	//线颜色.DeleteString(0); //删除第0项字符串

	//线颜色.InsertString(0, _T("hello")); //在第0位置插入“hello”

}

DIALOG_EntityProperty::~DIALOG_EntityProperty()
{
}

void DIALOG_EntityProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//控件的变量：线颜色
	DDX_Control(pDX, IDC_COMBO_LineCloor, 线颜色);
	DDX_Control(pDX, IDC_COMBO_LineStyle, 线型);
	//  DDX_Text(pDX, IDC_EDIT_LineWidth, 线宽);
	//  D//  DV_MinMaxInt(p//  DX, 线宽, 0, 30);
	DDX_Control(pDX, IDC_EDIT_LineWidth, 线宽);
	DDX_Control(pDX, IDC_COMBO_FaceColor, 面颜色);
	DDX_Control(pDX, IDC_EDIT_GreenLightIntro, 绿色灯浮介绍文字);
	DDX_Control(pDX, IDC_EDIT_RedLightIntro, 红色灯浮介绍文字);
	DDX_Control(pDX, IDC_EDIT_WaterDepth, 水深);
}


BEGIN_MESSAGE_MAP(DIALOG_EntityProperty, CDialogEx)
	
	//对话框及控件消息
	ON_CBN_SELCHANGE(IDC_COMBO_LineCloor, &DIALOG_EntityProperty::OnCbnSelchangeComboLinecloor)
	ON_CBN_SELCHANGE(IDC_COMBO_LineStyle, &DIALOG_EntityProperty::OnCbnSelchangeComboLinestyle)
	ON_EN_CHANGE(IDC_EDIT_LineWidth, &DIALOG_EntityProperty::OnEnChangeEditLinewidth)
	ON_BN_CLICKED(IDCANCEL, &DIALOG_EntityProperty::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO_FaceColor, &DIALOG_EntityProperty::OnCbnSelchangeComboFacecolor)
	ON_EN_CHANGE(IDC_EDIT_GreenLightIntro, &DIALOG_EntityProperty::OnEnChangeEditGreenlightintro)
	ON_EN_CHANGE(IDC_EDIT_RedLightIntro, &DIALOG_EntityProperty::OnEnChangeEditRedlightintro)
	ON_EN_CHANGE(IDC_EDIT_WaterDepth, &DIALOG_EntityProperty::OnEnChangeEditWaterdepth)
END_MESSAGE_MAP()


// DIALOG_EntityProperty 消息处理程序

//屏蔽Enter键
void DIALOG_EntityProperty::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	
	//CDialogEx::OnOK();
}




//组合框被选中后的事件响应
void DIALOG_EntityProperty::OnCbnSelchangeComboLinecloor()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (线颜色.GetCurSel())
	{
	case 0:
	{
		Global_items::g_CurColor = RGB(180, 91, 186);
		break;
	}
	case 1:
	{
		Global_items::g_CurColor = RGB(82, 90, 92);
		break;
	}
	case 2:
	{
		Global_items::g_CurColor = RGB(131, 178, 146);
	}
	default:
	{
		Global_items::g_CurColor = RGB(50, 100, 50);
		break;
	}
	}
}

void DIALOG_EntityProperty::OnCbnSelchangeComboLinestyle()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (线型.GetCurSel())
	{
	case 0:
	{
		Global_items::g_CurLineStyle = PS_DASH; //虚线
		break;
	}
	case 1:
	{
		Global_items::g_CurLineStyle = PS_SOLID; //实线
		break;
	}
	default:
	{
		break;
	}
	}
}




void DIALOG_EntityProperty::OnEnChangeEditLinewidth()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);
	CString temp;
	线宽.GetWindowText(temp);
	Global_items::g_CurLineWidth = _ttoi(temp);
}
//LOGBRUSH logBrush;
//logBrush.lbStyle = BS_SOLID;
//logBrush.lbColor = RGB(255, 0, 0);
//CPen pen;
//pen.CreatePen(PS_DASH | PS_GEOMETRIC | PS_ENDCAP_ROUND, 3, &logBrush);



void DIALOG_EntityProperty::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnCancel();
}

//面颜色
void DIALOG_EntityProperty::OnCbnSelchangeComboFacecolor()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (面颜色.GetCurSel())
	{
	case 0:
	{
		Global_items::g_FaceColor = RGB(180, 91, 186);
		break;
	}
	case 1:
	{
		Global_items::g_FaceColor = RGB(82, 90, 92);
		break;
	}
	case 2:
	{
		Global_items::g_FaceColor = RGB(131, 178, 146);
		break;
	}
	case 3:
	{
		Global_items::g_FaceColor = RGB(201, 185, 122);
		break;
	}

	default:
	{
		//Global_items::g_FaceColor = RGB(201, 185, 122);
		break;
	}
	}
}

//绿色灯浮介绍文字
void DIALOG_EntityProperty::OnEnChangeEditGreenlightintro()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	绿色灯浮介绍文字.GetWindowText(Global_items::g_greenLightIntro);
}

//红色灯浮介绍文字
void DIALOG_EntityProperty::OnEnChangeEditRedlightintro()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	红色灯浮介绍文字.GetWindowText(Global_items::g_redLightIntro);

}


void DIALOG_EntityProperty::OnEnChangeEditWaterdepth()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	水深.GetWindowText(Global_items::g_waterDepth);

}
