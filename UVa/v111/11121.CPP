#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
int mod(int num)
{
	if(num>0)return num%2;
	else  return (abs(num))%2;
}
int main()
{
	int num,n,i,j;
	int two[32];
	two[0]=1;
	for(i=1;i<31;i++)
		two[i]=two[i-1]*(-2);
	char s[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		if(!num)
		{
			printf("Case #%d: 0\n",i+1);
			continue;
		}
		for(j=0;num;j++)
		{
			s[j]=mod(num/abs(two[j]))+'0';
			num-=(two[j]*(s[j]-'0'));
		}
		s[j]=NULL;
		rev(s);
		printf("Case #%d: %s\n",i+1,s);
	}
	return 0;
}













