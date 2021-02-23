//============================================================================
// Name        : fudanE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>

using namespace std;

double game[2];
double p[2];
double dp[15][15][2];
double pp[2][2][2];
double vv[2][2][2];

double calc_game(int pl1,int pl2,int turn)
{
	if(pl1>=4 && pl1-pl2>=2)
		return 1.0;
	if(pl2>=4 && pl2-pl1 >= 2)
		return 0.0;
	if(pl1 >= 4 && pl2 >= 4)
		return pp[pl1-4][pl2-4][turn];
	
	double ret = p[turn]*calc_game(pl1+1,pl2,turn) + (1 - p[turn])*calc_game(pl1,pl2+1,turn);
	return ret;
}

double calc_set(int pl1,int pl2,int turn)
{
	if(pl1>=6 && pl2>=6 && abs(pl1-pl2)<2)
		return vv[pl1-6][pl2-6][!turn];
	
	if(pl1>=6 && (pl1 - pl2) >= 2)
		return 1.0;
	
	if(pl2>=6 && (pl2 - pl1) >= 2)
		return 0.0;
	
	if(!(dp[pl1][pl2][turn] < 0))
		return dp[pl1][pl2][turn];
	double ret;
	ret = game[turn] * calc_set(pl1+1,pl2,!turn) + (1 - game[turn]) * calc_set(pl1,pl2+1,!turn);
	return dp[pl1][pl2][turn] = ret;
}

double calc_match(int pl1,int pl2,int turn)
{
	if(pl1>=3) return 1.0;
	if(pl2>=3) return 0.0;
	double v = calc_set(0,0,turn); 
	double ret = v*calc_match(pl1+1,pl2,!turn) + (1 - v) * calc_match(pl1,pl2+1,!turn);
	return ret;
}

double det(double a,double b,double c,double d)
{
	return (a*d - b*c);
}

void compute()
{
	double x1 = game[0], x2 = 1 - game[0];
	double y1 = game[1], y2 = 1 - game[1];
	
	double D,D1,D2,val1,val2;
	
	D = det(1 - x1*y2, -x2*y2, -y1*x1, 1 - x2*y1);
	D1 = det(y1, -x2*y2, 0, 1 - x2*y1);
	D2 = det(1 - x1*y2, y1, -y1*x1, 0);
	val1 = D1/D;
	val2 = D2/D;
	
	vv[0][0][0] = x1 * val1 + x2 * val2;
	vv[1][0][1] = val1;
	vv[0][1][1] = val2;
	
	swap(x1,y1);
	swap(x2,y2);
	
	D = det(1 - x1*y2, -x2*y2, -y1*x1, 1 - x2*y1);
	D1 = det(y1, -x2*y2, 0, 1 - x2*y1);
	D2 = det(1 - x1*y2, y1, -y1*x1, 0);
	val1 = D1/D;
	val2 = D2/D;
	
	vv[0][0][1] = x1 * val1 + x2 * val2;
	vv[1][0][0] = val1;
	vv[0][1][0] = val2;
}

void comp1(int turn)
{
	double x1 = p[turn], x2 = 1 - p[turn];
	double D,D1,D2,val1,val2;
	
	D = det(1 - x1*x2, - x2*x2, -x1*x1, 1 - x1*x2);
	D1 = det(x1,- x2*x2 , 0 , 1 - x1*x2);
	D2 = det(1 - x1*x2 , x1 , -x1*x1, 0);
	val1 = D1/D;
	val2 = D2/D;
	
	pp[0][0][turn] = x1*val1 + x2*val2;
	pp[1][0][turn] = val1;
	pp[0][1][turn] = val2;
}

int main() 
{
	int t,i,j,k,cs=0;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<=10;i++)
			for(j=0;j<=10;j++)
				for(k=0;k<2;k++)
					dp[i][j][k] = -2.0;
		
		scanf("%d%d",&i,&j);
		p[0] = i/100.0;
		p[1] = j/100.0;
		
		for(i=0;i<2;i++)
			comp1(i);
		
		for(i=0;i<2;i++)
			game[i] = calc_game(0,0,i);
		
		compute();
		
		printf("Case #%d: %.4lf%%\n",++cs,calc_match(0,0,0)*100.0);
	}
	return 0;
}