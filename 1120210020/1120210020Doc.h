
// 1120210020Doc.h: CMy1120210020Doc 类的接口
//


#pragma once
#include "pch.h"
#include "framework.h"
#include "atlstr.h"
#include "CChart.h"
#include <fstream>
#include "hed.h"

class CMy1120210020Doc : public CDocument
{
protected: // 仅从序列化创建
	CMy1120210020Doc() noexcept;
	DECLARE_DYNCREATE(CMy1120210020Doc)

// 特性
public:
	//链表类的头；		
	hed* head;
// 操作
public:
public:
	int main();
	CChart* rd(CChart* plist, std::ifstream* fin);
	void insertbycnum(hed* head, CChart* plist);
	void inother(hed* head);
	void delet(hed* head);
	void correct(hed* head);
	void search(hed* head);
	void printlist(hed* head);

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy1120210020Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
