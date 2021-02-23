//Bigint 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 3000
char ans[1001][3000];
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
	char temp;
	while(i<j)
	{
		temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
void multi(char *b,int n)
{
	int n1=strlen(ans[n-1]);
	int n2=strlen(b);
	char temp[size];
        strcpy(temp,ans[n-1]);
        rev(temp),rev(b);
	int l=n1+n2,carry=0,sum,i,j,d1,d2;
	for(i=0;i<l-1;i++)
	{
		sum=0;
		for(j=(i<n2?0:(i-n2+1));j<=i;j++)
		{
			if(j>=n1)break;
			d1=temp[j]-'0';
                        d2=b[i-j]-'0';
			sum+=d1*d2;
		}
		ans[n][i]=(sum+carry)%10+'0';
		carry=(carry+sum)/10;
	}
	if(carry)
	{
		ans[n][i]=carry+'0';
		ans[n][i+1]=NULL;
	}
        else ans[n][i]=NULL;
	rev(ans[n]);
}
void main()
{
	int n,k;
        long sum;
	char b[size];
	ans[0][0]='1';
	ans[0][1]='\0';
	ans[1][0]='1';
	ans[1][1]='\0';
	for(k=2;k<=1000;k++)
	{
		sprintf(b,"%d",k);
		multi(b,k);
	}
	while(scanf("%d",&n)==1)
	{
        	sum=0;
		for(k=0;ans[n][k];k++)sum+=(ans[n][k]-'0');
		printf("%ld\n",sum);
	}
}