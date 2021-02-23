#include<stdio.h>
#include<string.h>

char s[10005],temp[10005];

int main()
{
	int n,x,m,i,j;
	while(scanf("%d%d%d",&x,&n,&m)==3 && x)
	{
		
		sprintf(s,"%d",x);
		n--;
		while(n)
		{
			int len=0;
			temp[0]=0;
			for(i=0;s[i];)
			{
				j=i+1;
				while(s[j] && s[j]==s[i])
					j++;
				char ss[100];
				sprintf(ss,"%d%c",j-i,s[i]);
	//			printf("%s\n",ss);
				strcat(temp,ss);
				len+=strlen(ss);
				if(len>m+50)
					break;
				i=j;
			}
			n--;
	//		printf("%d\n",strlen(temp));
			strcpy(s,temp);
		}
		printf("%c\n",s[m-1]);
	}
	return 0;
}