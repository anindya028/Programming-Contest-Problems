#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 10000
char tem[size];
typedef unsigned long int myint;
void rev(char *p)
{
	int i=0,j=strlen(p)-1;
        char temp;
	while(i<j)
	{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
		i++;
		j--;
	}
	return;
}
void add(char *c,char *d)
{
	char a[size],b[size];
	strcpy(a,c);
        strcpy(b,d);
	int n1=strlen(a);
	int n2=strlen(b);
        int j,carry=0,d1,d2;
	rev(a);
	rev(b);
	if(n1<n2)
	{
		for(j=n1;j<n2;j++)
		{
			a[j]='0';
		}
                a[j]='\0';
	}
	else if(n1>n2)
	{
		for(j=n2;j<n1;j++)
		{
			b[j]='0';
		}
		b[j]='\0';
        }
	for(j=0;j<(n1>n2?n1:n2);j++)
	{
		d1=(a[j]-'0');
		d2=(b[j]-'0');
		tem[j]=(d1+d2+carry)%10+'0';
		carry=(d1+d2+carry)/10;
	}
	if(carry)
	{
		 tem[j]='1';
		 tem[j+1]='\0';                
	}
	else tem[j]='\0';
        return;
}
void main(int)
{
      int n,l,i,j,k;
      char p[2][size],tempp[size];
	  scanf("%d",&n);
      for(i=0;i<n;i++)
      {
		scanf("%s%s",p[0],p[1]);
		rev(p[0]);
                rev(p[1]);
		add(p[0],p[1]); 
		l=strlen(tem);
		for(j=0;tem[j]=='0';j++);
		for(k=0;j<l;j++)
		{
				tempp[k]=tem[j];
				k++;
		}
		tempp[k]='\0';
		printf("%s\n",tempp);
      }

}













