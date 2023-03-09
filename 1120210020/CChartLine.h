#pragma once
class CChartLine
{

public:
	CChartLine();
	~CChartLine();
	//折线？坐标对，那就需要创建很多类吧，对，然后链表穿起来
	//一个类1条线
	//链表类内包含一个链表
	struct line
	{
		double p[2] = { 0,0 }; 	//线上的点  //数组数据全是0;	
		//double p2[2] = { 0,0 };	//终点
		line* next = nullptr;
	}*point;							//声明为指针的话，层数太多，不利于拷贝构造

	//拷贝构造，当类内有指针申请空间的变量时，拷贝构造需要深拷贝
	//注意，需要拷贝所有变量，不管是否是指针指向的；因为原来的拷贝构造函数没有了
	CChartLine(const CChartLine& Line)
	{
		point->p[0] = Line.point->p[0];
		point->p[1] = Line.point->p[1];
		pNext = Line.pNext;
		//point->next = *Line.point.next;

	}
	//操作集？
	CChartLine* pNext;
private:

};

