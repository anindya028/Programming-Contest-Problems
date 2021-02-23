//Nasty Addtion
#include<stdio.h>
#include<string.h>

#define SIZE 1000

char str1[SIZE],str2[SIZE],res[SIZE],temp[SIZE],bigstr[SIZE];

void mystrrev(char *s)
{
	int i,j;
	char tempc;

	j=strlen(s)-1;

	for(i=0;i<j;i++,j--)
	{
		tempc= s[i];
		s[i]=s[j];
		s[j]=tempc;
	}
}

void big(int i)
{
	int carry=0,j;
	char tempc;

	for(j=0;res[i] && str1[j];i++,j++)
	{
		tempc = res[i]+str1[j]+carry-'0';
		
		if(tempc <= '1')
		{
			res[i]=tempc;
			carry=0;
		}
		else
		{
			res[i]=tempc-2;
			carry = 1;
		}
	}

	while(res[i])
	{
		tempc = res[i]+carry;
		
		if(tempc <= '1')
		{
			res[i]=tempc;
			carry=0;
		}
		else
		{
			res[i]=tempc-2;
			carry = 1;
		}
		i++;	
	}
	while(str1[j])
	{
		tempc = str1[j]+carry;
		
		if(tempc <= '1')
		{
			res[i]=tempc;
			carry=0;
		}
		else
		{
			res[i]=tempc-2;
			carry = 1;
		}
		i++;
		j++;
	}

	if(carry)
		res[i++]='1';
	res[i]=0;
}

void big0(int pos,int l2)
{
	int l1,i,j;


	l1= strlen(res);
	if(pos+l2>l1)
	{	
		for(j=l1,i=0;i<pos+l2-l1;i++,j++)
		{
			res[j]='0';
		}
		res[j]=0;
	}

}

void multiply()
{
	int j,l1;

	l1=strlen(str1);
	mystrrev(str2);
	
	for(j=0;str2[j];j++)
	{
		if(str2[j]=='1')
			big(j);
		else
			big0(j,l1);
	}
}



void printsp(int n)
{
	int i;
	for(i=0;i<n;i++)
		putchar(' ');
}

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

void print()
{
	int l1,l2,l3,i,j,templen;

	mystrrev(str1);
	mystrrev(str2);
	l1=strlen(str1);
	l2=strlen(str2);
	l3=strlen(res);

	printsp(l3-l1);
	printf("%s\n",str1);
	printsp(l3-l2);
	printf("%s\n",str2);

	templen=max(l1,l2);
	printsp(l3-templen);
	for(i=0;i<templen;i++)
		putchar('-');
	puts("");

	for(i=l2-1;i>=0;i--){
		j=l2-i-1;
		printsp(l3-l1-j);

		if(str2[i]=='1'){			
			printf("%s\n",str1);
		}
		else{
			for(j=0;j<l1;j++)
				putchar('0');
			puts("");
		}
	}
	for(j=0;j<l3;j++)
		putchar('-');
	puts("");

	mystrrev(res);
	printf("%s\n",res);
	puts("");

}

int main()
{
	int i;
	int l1,l2;

	while(scanf("%s%s",str1,str2)==2)
	{

		l1 = strlen(str1);
		l2 = strlen(str2);

		if(l1 ==1 && l2 == 1  && str1[0]=='0' && str2[0]=='0')
			break;

		mystrrev(str1);
		res[0]=0;
		for(i=0;i<l1;i++)			
			bigstr[i]='0';
		bigstr[i]=0;

		multiply();
		print();

	}
	
	return 0;
}