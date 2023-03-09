#include "pch.h"
#include "CChartFace.h"
CChartFace::CChartFace()
{
	point = nullptr;
	pNext = nullptr;

}

CChartFace::~CChartFace()
{
	delete point;
	point = NULL;
}
