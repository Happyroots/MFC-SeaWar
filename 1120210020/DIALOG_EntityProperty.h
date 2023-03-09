#pragma once


// DIALOG_EntityProperty 对话框

class DIALOG_EntityProperty : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_EntityProperty)

public:
	DIALOG_EntityProperty(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DIALOG_EntityProperty();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EntityProperty };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	afx_msg void OnCbnSelchangeComboLinecloor();
	afx_msg void OnCbnSelchangeComboLinestyle();
	CComboBox 线颜色;
	CComboBox 线型;
//	int 线宽;
	afx_msg void OnEnChangeEditLinewidth();
	afx_msg void OnBnClickedCancel();
	CEdit 线宽;
	afx_msg void OnCbnSelchangeComboFacecolor();
	CComboBox 面颜色;
	afx_msg void OnEnChangeEditGreenlightintro();
	CEdit 绿色灯浮介绍文字;
	afx_msg void OnEnChangeEditRedlightintro();
	CEdit 红色灯浮介绍文字;
	CEdit 水深;
	afx_msg void OnEnChangeEditWaterdepth();
};
