
#include "OJ.h"

struct P
{
	int tim, value;
	double valuepertime;
	P(int t, int v):tim(t),value(v)
	{
		valuepertime = (double)value / (double)tim;
	}
	friend bool operator<(const P&, const P&);
	// bool operator<(const P& p)
	// {
	// 	return valuepertime > p.valuepertime;
	// }
};
bool operator<(const P& p1, const P& p2)
{
	return p1.valuepertime > p2.valuepertime;
}

int GetMaxValue(int nPapers, int nRemain, int paper[][2], double* pMaxValue)
{
	if(NULL == paper || NULL == pMaxValue) return 0;
	set<P> sp;
	for(int i=0; i<nPapers; ++i)
		sp.insert(P(paper[i][0],paper[i][1]));
	*pMaxValue = 0;
	for(set<P>::iterator i=sp.begin(); i!=sp.end(); ++i)
		if(nRemain > 0)
			if(nRemain >= i->tim)
			{
				nRemain -= i->tim;
				*pMaxValue += i->value;
			}
			else
			{
				*pMaxValue += nRemain * i->valuepertime;
				nRemain = 0;
			}
		else
			break;
	return 1;
}
