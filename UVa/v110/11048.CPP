#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

struct word
{
	int ind;
	char s[30];
}dict[10005];

bool operator<(word a,word b)
{
	return strcmp(a.s,b.s)<0;
}

int binsearch(char g[],int n)
{
	int low=0,high=n-1,mid,k;
	while(low<=high)
	{
		mid=(low+high)/2;
		k=strcmp(g,dict[mid].s);
		if(!k)return mid;
		else if(k>0)low=mid+1;
		else high=mid-1;
	}
	return -1;
}

int main()
{
	int n,i,j,q,flag,pos,d,k,len,cur,l;
	char given[100],temp[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&dict[i].s);
		dict[i].ind=i+1;
	}
	sort(dict,dict+n);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%s",given);
		if(binsearch(given,n)>=0)
		{
			printf("%s is correct\n",given);
			continue;
		}
		else 
		{
			pos=10000000;
			flag=0;
			len=strlen(given);
			//One letter is missing 
			for(j=0;j<=len;j++)
			{
				for(l=0;l<26;l++)
				{
					for(k=0;k<j;k++)
						temp[k]=given[k];
					temp[k]='a'+l;
					for(k++;given[k-1];k++)
						temp[k]=given[k-1];
					temp[k]='\0';
					d=binsearch(temp,n);
					if(d>=0 && dict[d].ind<pos)
					{
						flag=1;
						pos=dict[d].ind;
						cur=d;
					}
				}
			}
			//One letter is too much
			for(j=0;j<len;j++)
			{
				for(k=l=0;k<len;k++)
					if(k==j)
						continue;
					else
					{
						temp[l]=given[k];
						l++;
					}
				temp[l]='\0';
				d=binsearch(temp,n);
				if(d>=0 && dict[d].ind<pos)
				{
					flag=1;
					pos=dict[d].ind;
					cur=d;
				}
			}
			//One letter is wrong
			for(j=0;j<len;j++)
			{
				for(l=0;l<26;l++)
				{
					for(k=0;k<len;k++)
						if(k==j)
							temp[k]='a'+l;
						else
							temp[k]=given[k];
					temp[k]='\0';
					d=binsearch(temp,n);
					if(d>=0 && dict[d].ind<pos)
					{
						flag=1;
						pos=dict[d].ind;
						cur=d;
					}
				}
			}
			//The order of two adjacent letters is wrong
			for(j=0;j<len-1;j++)
			{
				for(k=0;k<len;k++)
					if(k==j)
					{
						temp[k]=given[j+1];
						temp[k+1]=given[j];
						k++;
					}
					else
						temp[k]=given[k];
				temp[k]='\0';
				d=binsearch(temp,n);
				if(d>=0 && dict[d].ind<pos)
				{
					flag=1;
					pos=dict[d].ind;
					cur=d;
				}
			}
			if(flag)
				printf("%s is a misspelling of %s\n",given,dict[cur].s);
			else
				printf("%s is unknown\n",given);
		}
	}			
	return 0;
}
