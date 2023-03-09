#pragma once
class CChartFace
{
public:
	CChartFace();
	~CChartFace();
	struct face
	{
		double p[2] = { 0,0 }; 		//面上的点  //数组数据全是0;	
		face* next = nullptr;		//定义时就初始化了
	}*point;
	CChartFace* pNext;
	CChartFace(const CChartFace& Face)
	{
		for (int i = 0; i < 2; i++)
		{
			point->p[i] = Face.point->p[i];
		}
		pNext = Face.pNext;
	}
private:

};

