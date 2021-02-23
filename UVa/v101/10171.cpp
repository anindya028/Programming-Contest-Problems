#include<stdio.h>

#define inf 1<<29
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,a)
#define Min(a,b) (((a)<(b))?(a):(b))

int main()
{
	int maty[30][30],mato[30][30],i,j,k,n,mn;
	char a[4],b[4],c[4],d[4];
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,28)
		{
			Foro(j,28)
				maty[i][j]=mato[i][j]=inf;
			maty[i][i]=mato[i][i]=0;
		}
		Foro(i,n)
		{
			scanf("%s%s%s%s%d",a,b,c,d,&k);
			if(a[0]=='Y')
			{
				if(b[0]=='U')
					maty[c[0]-'A'][d[0]-'A']=Min(maty[c[0]-'A'][d[0]-'A'],k);
				else
					maty[c[0]-'A'][d[0]-'A']=maty[d[0]-'A'][c[0]-'A']=Min(maty[c[0]-'A'][d[0]-'A'],k);
			}
			else
			{
				if(b[0]=='U')
					mato[c[0]-'A'][d[0]-'A']=Min(mato[c[0]-'A'][d[0]-'A'],k);
				else
					mato[c[0]-'A'][d[0]-'A']=mato[d[0]-'A'][c[0]-'A']=Min(mato[c[0]-'A'][d[0]-'A'],k);
			}
		}
		scanf("%s%s",a,b);
		Foro(k,26)
			Foro(i,26)
				Foro(j,26)
					maty[i][j]=Min(maty[i][j],maty[i][k]+maty[k][j]),mato[i][j]=Min(mato[i][j],mato[i][k]+mato[k][j]);
		mn=inf;
		Foro(i,26)
			mn=Min(mn,maty[a[0]-'A'][i]+mato[b[0]-'A'][i]);
		if(mn==inf)
			printf("You will never meet.\n");
		else
		{
			printf("%d",mn);
			Foro(i,26)
				if(mn==(maty[a[0]-'A'][i]+mato[b[0]-'A'][i]))
					printf(" %c",i+'A');
			printf("\n");
		}
	}
	return 0;
}