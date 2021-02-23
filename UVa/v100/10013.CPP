#include<stdio.h>
#include<string.h>
#define size 1000002
char a[size],b[size],temp,ans[size];
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
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
void main()
{
	long n,i,k,d1,d2,m,carry;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&m);
		for(k=0;k<m;k++)
		{
			scanf("%1s%1s",&a[k],&b[k]);
		}
                a[k]=b[k]='\0';
		rev(a);
		rev(b);
                carry=0;
		for(k=0;k<m;k++)
		{
			d1=a[k]-'0';
			d2=b[k]-'0';
			ans[k]=(d1+d2+carry)%10+'0';
			carry=(d1+d2+carry)/10;
		}
		if(carry)
		{
			ans[k]=carry+'0';
			ans[k+1]='\0';
		}
		else ans[k]='\0';
		rev(ans);
		printf("%s\n",ans);
		if(i<(n-1))printf("\n");
	}


}













