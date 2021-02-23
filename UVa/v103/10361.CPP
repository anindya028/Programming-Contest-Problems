#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char l1[150],l2[150],ans1[150],ans2[150],s2[150],s3[150],s4[150],s5[150];
	int n,i,j,k;
	gets(l1);
	sscanf(l1,"%d",&n);
	for(i=0;i<n;i++)
	{
		gets(l1);
		gets(l2);
		for(j=k=0;l1[j];j++,k++)
		{
			if(l1[j]=='<')
			{
				j++;
				break;
			}
			ans1[k]=l1[j];
		}
		ans1[k]='\0';
		for(k=0;l1[j];j++,k++)
		{
			if(l1[j]=='>')
			{
				j++;
				break;
			}
			else s2[k]=l1[j];
		}
		s2[k]='\0';
                strcat(ans1,s2);
		for(k=0;l1[j];j++,k++)
		{
			if(l1[j]=='<')
			{
				j++;
				break;
			}
			else s3[k]=l1[j];
		}
		s3[k]='\0';
                strcat(ans1,s3);
		for(k=0;l1[j];j++,k++)
		{
			if(l1[j]=='>')
			{
				j++;
				break;
			}
			else s4[k]=l1[j];
		}
		s4[k]='\0';
		strcat(ans1,s4);
		for(k=0;l1[j];j++,k++)
		{
			s5[k]=l1[j];
		}
		s5[k]='\0';
                strcat(ans1,s5);
		for(j=0;;j++)
		{
			if(l2[j]=='.' && l2[j]==l2[j+1] && l2[j+1]==l2[j+2])break;
			ans2[j]=l2[j];
		}
		ans2[j]='\0';
		strcat(ans2,s4);
		strcat(ans2,s3);
		strcat(ans2,s2);
		strcat(ans2,s5);
		printf("%s\n%s\n",ans1,ans2);
	}
	return 0;
}













