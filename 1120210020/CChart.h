#pragma once
#include"CChartFace.h"
#include"CChartLine.h"
#include"CChartPoint.h"
class CChart
{
public:
	CChart();
	~CChart();			//类内数据的改变需要函数来操作？ 好麻烦？

	struct eChart
	{
		// 数据对象集, 初始化？
		char cnum[20] = { -1 };	    //海图图号；
		char llat[20] = { -1 };     //左上角经度；
		char llong[20] = { -1 };    //左上角纬度；
		char rlat[20] = { -1 };     //右下角经度；
		char rlong[20] = { -1 };    //右下角纬度；
		char scale[20] = { -1 };    //海图比例尺；
		char cname[20] = { -1 };    //图名；
		char isudate[20] = { -1 };  //发行日期；
		char cordate[20] = { -1 };  //修改日期；
		//一共9个数据
	}bscinfo;						//声明并定义了结构 bscinfo

	class CChartPoint* point;		//点链表类,为什么分开定义就不行？想不明白
	//必须使用指针？
	class CChartLine* line;			//声明在内部，定义在外部
	class CChartFace* face;			//注意作用域和访问权限

	//创建并申请空间？，好像不需要，都是模板；都是躯壳!
	//+一个指针
	CChart* pNext;		//类指针

	//海图类的操作集
	//修改属性，9个函数,多此一举的嫌疑
	void corcnum(const char* ch, int len)			//参数前+const关键字，否则报错
	{
		memcpy(this->bscinfo.cnum, ch, len);		//没截断数组
	}
	void corllat(const char* ch, int len)		//参数前+const关键字，否则报错
	{
		memcpy(this->bscinfo.llat, ch, len);
	}
	void corllong(const char* ch, int len)		//参数前+const关键字，否则报错
	{
		memcpy(this->bscinfo.llong, ch, len);
	}
	void corrlat(const char* ch, int len)		//参数前+const关键字，否则报错
	{
		memcpy(this->bscinfo.rlat, ch, len);
	}
	void corrlong(const char* ch, int len)		//参数前+const关键字，否则报错
	{
		memcpy(this->bscinfo.rlong, ch, len);
	}
	void corscale(const char* ch, int len)		//参数前+const关键字，否则报错
	{
		memcpy(this->bscinfo.scale, ch, len);
	}
	void corcname(const char* ch, int len)		//参数前+const关键字，否则报错
	{
		//std::cout <<"corcname" << sizeof(ch) << "  ";
		memcpy(this->bscinfo.cname, ch, len);
	}
	void corisudate(const char* ch, int len)		//参数前+const关键字，否则报错
	{
		memcpy(this->bscinfo.isudate, ch, len);
	}
	void corcordate(const char* ch, int len)		//参数前+const关键字，否则报错
	{
		memcpy(this->bscinfo.cordate, ch, len);
	}
	CChart(const CChart& Chart)
	{
		//*this = Chart; //把地址也copy了
		memcpy(point->color, Chart.point->color, sizeof(point->color));
		memcpy(point->intr, Chart.point->intr, sizeof(point->intr));
		memcpy(point->lat, Chart.point->lat, sizeof(point->lat));
		memcpy(point->lon, Chart.point->lon, sizeof(point->lon));
		memcpy(point->pNext, Chart.point->pNext, sizeof(point->pNext));
		point->type = Chart.point->type;
		for (int i = 0; i < 2; i++)
		{
			line->point->p[i] = line->point->p[i];
		}
		for (int j = 0; j < 2; j++)
		{
			face->point->p[j] = face->point->p[j];
		}
		pNext = Chart.pNext;
	}
private:		//类内访问	
//定义私有属性？，涉及到类的继承，拷贝构造吗

};



