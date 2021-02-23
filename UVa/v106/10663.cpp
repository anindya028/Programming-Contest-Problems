#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

bool power[1000006];
vector<int> seq[1005];

bool make(int pos,int now,int k)
{
	if(pos==seq[k].size())
		return !power[now];
	return (make(pos+1,now+seq[k][pos],k) && make(pos+1,now,k));
}

int up[101]={0,971,448,704,0,398,409,369,0,0,650,713,530,402,480,779,0,387,734,384,984,435,442,
476,657,0,405,0,329,161,966,741,0,284,720,543,0,513,328,601,686,923,962,557,605,659,491,283,617,0,
439,195,440,259,185,432,274,986,514,736,610,685,274,558,0,740,425,827,667,768,760,827,258,864,
736,736,891,140,798,577,300,0,200,939,288,198,189,884,340,424,332,237,546,359,165,390,199,501,250,905,0
};

int main()
{
	int i,j,a,b,last[1005]={0};
	for(i=2;i<=1000;i++)
	{
		j=i*i;
		while(j<=1000000)
			power[j]=true,j*=i;
	}
	// 1000-> 40, 14000->145

	for(i=1;i<=1000;i++)
	{
		if(power[i])
			continue;
		seq[i].push_back(i);
		for(j=i+1;j<=1000;j++)
		{
			if(i<=100 && j>up[i])
				break;
			if(power[j])
				continue;
			if(make(0,j,i))
				seq[i].push_back(j),last[i]=j;
		}
	}

	while(scanf("%d%d",&a,&b)==2)
	{
		for(i=a;i<=b && power[i];i++);

		printf("%d",seq[i][0]);
		for(j=1;j<seq[i].size() && seq[i][j]<=b;j++)
			printf(" %d",seq[i][j]);
		printf("\n");
	}
	return 0;
}