#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int min(int m,int n)
{
	return m<n?m:n;
}
int queen(int m,int n)
{
	if(m==1 || n==1)return 1;
	else if(m==2 && n==2)return 1;
	else if(m==2 || n==2)return 2;
	else if(m==3 && n==3)return 2;
	else return min(m,n);
}
int king(int m,int n)
{
	return (int)((m+1)/2)*(int)((n+1)/2);
}
int knight(int m,int n)
{
	int temp;
	if(m==1 &&n==1)return 1;
	else if(m==1 || n==1)return  n+m-1;
	else if(m==2 || n==2)
	{
		temp=m!=2?m:n;
		if((temp%4)>=2)return ((temp/4)*4+4);
		else if(temp%4==1)return ((temp/4)*4+2);
		else return ((int)(temp/4)*4);
        }
	else if((m*n)%2)return (m*n+1)/2;
	else return ((m*n)/2);
}
int main()
{
	int n,i,r,k;
        char c,s[20];
	scanf("%d",&n);
	gets(s);
	for(i=0;i<n;i++)
	{
		gets(s);
		sscanf(s,"%c%d%d",&c,&r,&k);
		if(c=='r')printf("%d\n",min(r,k));
		else if(c=='K')printf("%d\n",king(r,k));
		else if(c=='k')printf("%d\n",knight(r,k));
		else if(c=='Q')printf("%d\n",queen(r,k));
    }
	return 0;
}













