#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,m,i,j,cs=0,flag,*nfreq,*mfreq;
        char temp[5];
	char sn[105][200],sm[105][200];
	while(gets(temp))
	{
		if(temp[0]=='0'&&temp[1]=='\0')break;
                flag=1;
				nfreq=(int *)calloc(130,sizeof(int));
				mfreq=(int *)calloc(130,sizeof(int));
		sscanf(temp,"%d",&n);
		for(i=0;i<n;i++)
		{
			gets(sn[i]);
			strcat(sn[i],"\n");
			for(j=0;sn[i][j];j++)nfreq[sn[i][j]]++;
		}
		gets(temp);
		sscanf(temp,"%d",&m);
		for(i=0;i<m;i++)
		{
			gets(sm[i]);
			strcat(sm[i],"\n");
			for(j=0;sm[i][j];j++)mfreq[sm[i][j]]++;
		}
		for(i='0';i<='9';i++)
			if(nfreq[i]!=mfreq[i])flag=0;
		if(!flag)
		{
			printf("Run #%d: Wrong Answer\n",++cs);
			continue;
		}
		for(i=0;i<129;i++)
			if(nfreq[i]!=mfreq[i])flag=2;
		if(n!=m && flag==1)flag=2;
		for(i=0;i<n && n==m;i++)
			if(strcmp(sn[i],sm[i]))flag=2;
		if(flag==1)printf("Run #%d: Accepted\n",++cs);
		else printf("Run #%d: Presentation Error\n",++cs);
		free(nfreq);
		free(mfreq);
	}
	return 0;
}













