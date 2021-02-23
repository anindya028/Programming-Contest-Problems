#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,i,j,countx,counto,k,flag,win,winx,wino;
	char s[3][5],winc;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			flag=1;
			for(j=0;j<3;j++)
				scanf("%s",s[j]);
			for(j=countx=counto=0;j<3;j++)
				for(k=0;k<3;k++)
				{
					if(s[j][k]=='X')countx++;
					else if(s[j][k]=='O')counto++;
				}
			if((countx-counto) && (countx-counto)!=1)flag=0;
			for(j=win=winx=wino=0;j<3;j++)
			{
				if(s[j][0]==s[j][1] && s[j][2]==s[j][1] && s[j][0]!='.')
				{
					win++;
					winc=s[j][0];
					if(winc=='X')winx++;
					else wino++;
				}
				if(s[0][j]==s[1][j] && s[2][j]==s[1][j] && s[0][j]!='.')
				{
					win++;
					winc=s[0][j];
					if(winc=='X')winx++;
					else wino++;
				}
			}
			if(s[0][0]==s[1][1] && s[1][1]==s[2][2] && s[0][0]!='.')
			{
				win++;
				winc=s[1][1];
				if(winc=='X')winx++;
				else wino++;
			}
			if(s[2][0]==s[1][1] && s[1][1]==s[0][2] && s[1][1]!='.')
			{
				win++;
				winc=s[1][1];
				if(winc=='X')winx++;
				else wino++;
			}
			if(countx==5 && counto==4 && win==2 && winx==2)
			{
				printf("yes\n");
				winc='\0';
				continue;
			}
			if(win>1)flag=0;
			else if(winc=='X' && countx==counto)flag=0;
			else if(winc=='O' && countx!=counto)flag=0;
			if(flag)printf("yes\n");
			else printf("no\n");
			winc='\0';
		}
	}
	return 0;
}













