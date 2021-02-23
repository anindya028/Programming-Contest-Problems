
#include<stdio.h>

#define MAX 30

#define _max(x,y) ((x>y)?(x):(y))

int tn[MAX],sn[MAX],time[MAX],graph[MAX][MAX];

void reset()
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		time[i] = tn[i] = sn[i] = 0;
		for(j=0;j<MAX;j++)
			graph[i][j] = 0;
	}
}

void color(int k, int runtime)
{
	int i;
	runtime+=tn[k];
	if (runtime < time[k]) return;
	time[k] = runtime;
	for(i=0;i<26;i++)
	{
		if(i!=k && graph[k][i])
			color(i,time[k]);
	}
}

int main()
{
	int N,ks,n,i,max;
	char bef[MAX+1],c[30],s[100];
	gets(s);
	sscanf(s,"%d",&N);
	gets(s);
	for(ks=0;ks<N;ks++)
	{
		s[0]=0;
		reset();
		while(gets(s) && s[0])
		{
			if(sscanf(s,"%s%d%s",c,&n,bef)==2)
				sn[ c[0]-'A' ] = 1;
			else
			{
				sn[ c[0]-'A' ] = 0;
				for(i=0;bef[i];i++)
					graph[ bef[i]-'A' ][ c[0]-'A' ] = 1;
			}
			tn[ c[0]-'A' ] = n;
		}
		for(i=0;i<MAX;i++)
		{
			if(!sn[i])
				continue;
			time[i] = tn[i];
			color(i,0);
		}
		max=time[0];
		for (i=1; i<26; i++)
		{
			if (time[i]>max)
				max=time[i];
		}
		if(ks) printf("\n");
		printf("%d\n",max);
	}
	return 0;
}
