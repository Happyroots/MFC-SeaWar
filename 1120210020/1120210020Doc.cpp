
// 1120210020Doc.cpp: CMy1120210020Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "1120210020.h"
#endif

#include "1120210020Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy1120210020Doc

IMPLEMENT_DYNCREATE(CMy1120210020Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy1120210020Doc, CDocument)
END_MESSAGE_MAP()


// CMy1120210020Doc 构造/析构

CMy1120210020Doc::CMy1120210020Doc() noexcept
{
	// TODO: 在此添加一次性构造代码
		//链表类的头；		
	head = new hed;
	main();
}

CMy1120210020Doc::~CMy1120210020Doc()
{
}

BOOL CMy1120210020Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMy1120210020Doc 序列化

void CMy1120210020Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMy1120210020Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMy1120210020Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMy1120210020Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy1120210020Doc 诊断

#ifdef _DEBUG
void CMy1120210020Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1120210020Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy1120210020Doc 命令

#include <stdio.h>
#include <string>
#include <vector>
#include "hed.h"
#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;

int CMy1120210020Doc::main()
{
	AfxMessageBox(L"右键可实现增删改查等功能");

	CChart* plist = new CChart;			//创建时自动调用析构函数
	std::ifstream* fin = new std::ifstream;
	fin->open("海图目录.txt");
	//std::assert(fin.is_open());
	if (!fin)								//鲁棒性
	{
		std::cout << "打开文件失败" << std::endl;
		exit(1);
	}
	//定位信息
	string s;
	string condition = "修改日期";
	while (*fin >> s)
	{
		if (s.compare(condition) == 0)
		{
			break;
		}

	}
	//fin->seekg(90);			//将文件位置指针指向下一行
		//读入数据
	if (!fin->eof())
	{
		plist = rd(plist, fin);					//海图类的基本信息都存进去了
		head->hNext = plist;					//为什么出去给我释放内存了？
		plist = plist->pNext;		//提前申请空间	//链表已经存入，创建新的,指向后面的指针即可完成操作
		plist = new CChart;
		//申请的空间只能用delet删除？
	}
	//一开始的plist弄丢了？
	//cout << plist->bscinfo.cnum << endl;
	while (!fin->eof())						//判断有无数据
	{
		plist = rd(plist, fin);					//rd()函数 创建了新链表，并将文件信息存入了链表
		//按cnum插入主链表，首个不插入
		insertbycnum(head, plist);		//起到了排序功能
		//plist->的链表类没变，位置变了可能	
		CChart* tail = head->hNext;
		while (tail)
		{
			tail = tail->pNext;
		}
		plist = tail;				//确保创建的新链表接到链表类尾！
		plist = new CChart;
	}
	printlist(head);
	inother(head);
	//delet(head);
	//printlist(head);
	///correct(head);
	//printlist(head);
	///search(head);



	return 0;
}

//读取海图目录
CChart* CMy1120210020Doc::rd(CChart* plist, std::ifstream* fin)
{
	// TODO: 在此处添加实现代码.
	//创建链表,申请空间并存入数据


	//准备存取容器
	std::string s;					//一个S只能存储一个字符串，一个单词
	std::vector<std::string> vec;			//临时容器
	int time = -1;					//为什么要初始化来着？
	int i = -1;
	//尝试将数据存入链表,结果：完美存入
	while (time < 8 && *fin >> s) //一次循环只读入一个单词/字符串，利用了短路功能
	{
		/************调试代码**********************/
		//String->Cstring转换
		CString temp;
		temp = s.c_str();
		//AfxMessageBox(temp);
		/******************************************/

		time++;//注意是先加后用
		i = time % 9;
		//字符串存入vec
		vec.push_back(s);
		//字符串存入链表
		int len = vec[i].size();
		//AfxMessageBox(len);
		if (plist) //判断是否申请到了内存
		{

			switch (i)
			{
			case 0:
				//重复劳动？
				//memcpy(plist->bscinfo.cnum, vec[0].c_str(), len);   不需要操作函数，没截断数组也没出现乱码
				//精简代码？好像也不至于，这样更安全了
				plist->corcnum(vec[i].c_str(), len);
				plist->bscinfo.cnum[len] = '\0';			 //添加‘\0’字符！截断 数组
				break;
			case 1:
				plist->corllat(vec[i].c_str(), len);
				plist->bscinfo.llat[len] = '\0';
				break;
			case 2:
				plist->corllong(vec[i].c_str(), len);
				plist->bscinfo.llong[len] = '\0';
				break;
			case 3:
				plist->corrlat(vec[i].c_str(), len);
				plist->bscinfo.rlat[len] = '\0';
				break;
			case 4:
				plist->corllong(vec[i].c_str(), len);
				plist->bscinfo.llong[len] = '\0';
				break;
			case 5:
				plist->corscale(vec[i].c_str(), len);
				plist->bscinfo.scale[len] = '\0';
				break;
			case 6:
				plist->corcname(vec[i].c_str(), len);
				plist->bscinfo.cname[len] = '\0';
				break;
			case 7:
				plist->corisudate(vec[i].c_str(), len);
				plist->bscinfo.isudate[len] = '\0';
				break;
			case 8:
				plist->corcordate(vec[i].c_str(), len);
				plist->bscinfo.cordate[len] = '\0';
				break;
			default:
				break;
			}
		}
	}
	//	cout << plist << endl;
	return plist;

}
//二、
//将单链表插入总链表，按cnum大小，考虑更新
void CMy1120210020Doc::insertbycnum(hed* head, CChart* plist)
{
	CChart* temp = head->hNext;						//=plist,一定非空
	CChart* pret = temp;
	//按cnum排序，且一个链表类时不操作；
	//若两者相等，不会执行循环,同一指针，访问冲突
	//第一个对不？
	while (memcmp(temp->bscinfo.cnum, plist->bscinfo.cnum, 20) < 0 && temp->pNext != NULL)
		//找到比plist大的链表类
	{
		pret = temp;							//不要看名字，看操作的哪个链表
		temp = temp->pNext;						//向后挪//空指针怎么弄？
	}
	if (strcmp(temp->bscinfo.cnum, plist->bscinfo.cnum) == 0)	//上面的循环保证了temp非空
	{
		temp = plist;							//更新
	}
	else
	{
		plist->pNext = pret->pNext;
		pret->pNext = plist;
	}

	return;
}

//三、
// 循环顶呱呱！！！
//读入海图的其他信息；	要考虑顺序吗？不需要，数据的顺序不能变
void CMy1120210020Doc::inother(hed* head)
{
	CChart* list = head->hNext;
	string filename;
	while (list != NULL)	//遍历所有链表，读入每个链表类对应的信息，直到完成循环
	{
		//打开每个链表类对应的文件		只执行一次才可以
		filename = list->bscinfo.cnum;
		filename = filename + ".txt";

		/**********调试代码************/
		CString tempname;
		tempname = filename.c_str();
		//AfxMessageBox(tempname);
		/************调试代码**********/

		ifstream finother(filename);
		if (!finother)	//判断文件是否存在
		{
			CString warning = L"文件不存在，无法读取点线面等详细信息！";
			AfxMessageBox(tempname + warning);
			list = list->pNext;			//读取下一张海图
			continue;
		}
		string s;		//只申请了一次内存吗？
		//finother.tellg();//寻找想要的位置，挺有用的！
		//cout << filename << "文件的信息" << endl;
		while (!finother.eof())
		{
			string s;
			finother >> s;
			if (s == "说明")
			{
				//	cout << finother.tellg() << endl;
				break;
			}
		}
		//finother.seekg(269);		//找到对应的信息，269 magic number不好

		//读取点类信息, 需要制作链表头！
		list->point = new CChartPoint;
		int key = 0;		//确定是哪种信息。
		finother >> s;

		//读取点类信息
		while (s != "//线类信息(坐标对，折线）")	//直到线类信息才截止， 可以无限加，动态扩展
		{

			enum type { 经度, 纬度, 性质, 颜色, 说明 };
			//做一个读取点类信息的函数？
			switch (key % 5)
			{
			case 经度:
				memcpy(list->point->lon, s.c_str(), s.length() + 1);
				//cout << s << endl;
				break;
			case 纬度:
				memcpy(list->point->lat, s.c_str(), s.length() + 1);
				//cout << s << endl;
				break;
			case 性质:
				list->point->type = stoi(s.c_str());	//好邪恶啊
				//cout << s << endl;
				break;
			case 颜色:
				memcpy(list->point->color, s.c_str(), s.length() + 1);
				//cout << s << endl;
				break;
			case 说明:
				memcpy(list->point->intr, s.c_str(), s.length() + 1);
				//cout << "说明" << s << endl;
				break;
			default:
				break;
			}
			key++;
			if (key % 5 == 0)
			{
				list->point = list->point->pNext = new CChartPoint;	//需要申请空间，是不是临时空间？
				//VS非必要不销毁
			}
			finother >> s;
		}

		//读取线类信息
		list->line = new CChartLine;
		int linekey = 0;		//确定是哪种信息。
		finother >> s;
		while (s != "//面类信息")
		{
			if (s == "Lend")
			{
				list->line->point = list->line->point->next = new CChartLine::line;	//需要申请空间
				finother >> s;
				continue;
			}
			switch (linekey % 2)			//有x个case就对x取余
			{
			case 0:
				list->line->point = new CChartLine::line;		//空指针需要申请空间才能使用
				list->line->point->p[0] = stold(s.c_str());
				//cout << setprecision(10) <<list->line->point->p[0] << endl;
				break;
			case 1:
				list->line->point->p[1] = stold(s.c_str());
				//cout << setprecision(10) << list->line->point->p[1] << endl;
				break;
			default:
				break;
			}
			linekey++;
			finother >> s;
		}

		//读取面类信息
		list->face = new CChartFace;
		int facekey = 0;		//确定是哪种信息。
		finother >> s;
		while (s != "ENDofALL")
		{
			if (s == "Pend")
			{
				list->line->point = list->line->point->next = new CChartLine::line;	//需要申请空间
				finother >> s;
				continue;
			}
			switch (facekey % 2)			//有x个case就对x取余
			{
			case 0:
				list->line->point = new CChartLine::line;		//空指针需要申请空间才能使用
				list->line->point->p[0] = stold(s.c_str());
				//cout << setprecision(10) << list->line->point->p[0] << endl;
				break;
			case 1:
				list->line->point->p[1] = stold(s.c_str());
				//cout << setprecision(10) << list->line->point->p[1] << endl;
				break;
			default:
				break;
			}
			facekey++;
			finother >> s;
		}
		list = list->pNext;			//读取下一张海图
	}
}
//完美运行！！！


//finother.tellg();//寻找想要的位置，挺有用的！
//while (!finother.eof())
//{
//	string s2;
//	finother >> s2;
//	if (s2 == "说明")
//	{
//		cout << finother.tellg() << endl;
//		break;
//	}
//}


//四、删除
// // 删除p后面的链表类,是否合法？,按cnum删除
//删除一次，调用一次回调函数，不需要循环 
void CMy1120210020Doc::delet(hed* head)
{
	cout << "请输入要删除的海图" << endl;
	cout << "不需要删除就输入非海图图号" << endl;
	char cnum[20] = {};
	cin >> cnum;
	CChart* temp = head->hNext;
	//对第一个链表的处理，特殊：删除时需要前面的节点，而第一个节点不同
	if (memcmp(temp->bscinfo.cnum, cnum, 8) == 0)
	{
		CChart* s = temp;
		head->hNext = s->pNext;
		delete s;				//先调用析构函数，再删除指针指向的内存
		//删除指针，前面加 []	//删除的是什么？：指针指向的空间
		s = NULL;			//避免野指针！		
		//p=NULL是个好习惯
			//就像你蹲完厕所要洗手一样
		cout << "删除成功!" << endl;
		return;			//退出当前函数，exit()退出整个程序
	}
	//第二个
	while (memcmp(temp->pNext->bscinfo.cnum, cnum, 8))
		//找到对应的海图链表类节点
	{
		temp = temp->pNext;
		if (temp->pNext == NULL)
		{
			cout << "没有此海图，无法删除!" << endl;
			return;//exit(1);
		}
	}
	CChart* s = temp->pNext;
	temp->pNext = s->pNext;
	delete s;		//操作类要用new ,delete
	cout << "删除成功!" << endl;
}


//五、修改
void CMy1120210020Doc::correct(hed* head)
{
	cout << "请输入要修改的海图图号" << endl;
	char cnum[20] = {};
	cin >> cnum;
	CChart* plist = head->hNext;
	while (memcmp(plist->bscinfo.cnum, cnum, 8))
		//找到对应的海图链表类节点
	{
		plist = plist->pNext;
		if (plist == NULL)
		{
			cout << "没有此海图，无法修改!" << endl;
			return;//exit(1);
		}
	}
	cout << "请输入要更改的信息\n";
	cout << "海图图号, 左上角经度, 左上角纬度, 右下角经度,右下角纬度, 海图比例尺, 图名, 发行日期, 修改日期 \n";
	cout << "海图图号请输入0，左上角经度请输入1，以此类推\n";
	enum cInfo { 海图图号, 左上角经度, 左上角纬度, 右下角经度, 右下角纬度, 海图比例尺, 图名, 发行日期, 修改日期 };
	int type = -1;
	cin >> type;
	char corinfo[30];
	cout << "请输入要修改的信息" << endl;
	cin >> corinfo;
	int len = sizeof(corinfo);
	switch (type)
	{
	case 海图图号:
		//重复劳动？
		//memcpy(plist->bscinfo.cnum, vec[0].c_str(), len);   不需要操作函数，没截断数组也没出现乱码
		//精简代码？好像也不至于，这样更安全了
		plist->corcnum(corinfo, len);
		//添加‘\0’字符！截断 数组
		break;
	case 左上角经度:
		plist->corllat(corinfo, len);
		break;
	case 左上角纬度:
		plist->corllong(corinfo, len);
		break;
	case 右下角经度:
		plist->corrlat(corinfo, len);
		break;
	case 右下角纬度:
		plist->corllong(corinfo, len);
		break;
	case 海图比例尺:
		plist->corscale(corinfo, len);
		break;
	case  图名:
		plist->corcname(corinfo, len);
		break;
	case  发行日期:
		plist->corisudate(corinfo, len);
		break;
	case 修改日期:
		plist->corcordate(corinfo, len);
		break;
	default:
		break;
	}
}

//六、查询
void CMy1120210020Doc::search(hed* head)
{
	cout << "请输入查询的海图图号" << endl;
	char cnum[20] = {};
	cin >> cnum;
	CChart* plist = head->hNext;
	while (memcmp(plist->bscinfo.cnum, cnum, 8))
		//找到对应的海图链表类节点
	{
		plist = plist->pNext;
		if (plist == NULL)
		{
			cout << "没有此海图!" << endl;
			return;//exit(1);
		}
	}
	cout << "请输入要查询的信息\n";
	cout << "海图图号, 左上角经度, 左上角纬度, 右下角经度,右下角纬度, 海图比例尺, 图名, 发行日期, 修改日期 \n";
	cout << "海图图号请输入0，左上角经度请输入1，以此类推\n";
	enum cInfo { 海图图号, 左上角经度, 左上角纬度, 右下角经度, 右下角纬度, 海图比例尺, 图名, 发行日期, 修改日期 };
	int type = -1;
	cin >> type;
	//char corinfo[30];
	//cout << "请输入要查询的信息" << endl;
	//cin >> corinfo;
	switch (type)
	{
	case 海图图号:
		//重复劳动？
		//memcpy(plist->bscinfo.cnum, vec[0].c_str(), len);   不需要操作函数，没截断数组也没出现乱码
		//精简代码？好像也不至于，这样更安全了
		cout << "海图图号： " << plist->bscinfo.cnum;
		//添加‘\0’字符！截断 数组
		break;
	case 左上角经度:
		cout << "左上角经度： " << plist->bscinfo.llong;
		break;
	case 左上角纬度:
		cout << "左上角纬度： " << plist->bscinfo.llat;
		break;
	case 右下角经度:
		cout << "右下角经度： " << plist->bscinfo.rlong;
		break;
	case 右下角纬度:
		cout << "右下角纬度： " << plist->bscinfo.rlat;
		break;
	case 海图比例尺:
		cout << "海图比例尺： " << plist->bscinfo.scale;
		break;
	case 图名:
		cout << "图名： " << plist->bscinfo.cname;
		break;
	case 发行日期:
		cout << "发行日期： " << plist->bscinfo.isudate;
		break;
	case 修改日期:
		cout << "修改日期： " << plist->bscinfo.cordate;
		break;
	default:
		break;
	}

}



//七、
//LAST
//输出所有存入链表的cnum
void CMy1120210020Doc::printlist(hed* head)
{
	cout << "存入的所有海图如下：\n";
	CChart* temp = head->hNext;
	CString temps;

	while (temp != nullptr)
	{
		temps = temp->bscinfo.cnum;
		AfxMessageBox(temps);
		temp = temp->pNext;
	}
}
