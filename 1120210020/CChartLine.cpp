#include "pch.h"
#include "CChartLine.h"

CChartLine::CChartLine()
{
	point = nullptr;
	pNext = nullptr;
}

CChartLine::~CChartLine()
{
	delete point;
}
