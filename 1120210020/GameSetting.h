#pragma once


// GameSetting 对话框

class GameSetting : public CDialogEx
{
	DECLARE_DYNAMIC(GameSetting)

public:
	GameSetting(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GameSetting();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GameSetting };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit 玩家名称;
	afx_msg void OnEnChangeEditUsername();
	CEdit 自定义按键;
	afx_msg void OnEnChangeEditkeys();
	afx_msg void OnCbnSelchangeComboDiffculty();
	CComboBox 游戏难度;
};
