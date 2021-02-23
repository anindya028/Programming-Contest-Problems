//this is my code-rte,rte,tle
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char find[15][30000],replace[15][30000],temp[30000],s[30000];
int check(int i)
{
	int j,k,pos,flag,len=strlen(find[i]);
	for(j=0;s[j];j++)
	{
		if(s[j]==find[i][0])
		{
			pos=j;
			flag=1;
			for(k=j+1;s[k] && (k-pos)<len;k++)
			{
				if(find[i][k-pos]!=s[k])
				{
					flag=0;
					break;
				}
			}
			if(flag)return pos;
		}
	}
	return -1;
}
void place(int pos,int i)
{
	int j,k,lenr=strlen(replace[i]),lenf=strlen(find[i]);
	for(j=0;j<pos;j++)
		temp[j]=s[j];
	for(k=j;(k-j)<lenr;k++)
		temp[k]=replace[i][k-pos];
	for(j+=lenf;s[j];j++,k++)
		temp[k]=s[j];
	temp[k]='\0';
	strcpy(s,temp);
	return;
}
int  main()
{
	int n,i,pos;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		gets(s);
		for(i=0;i<n;i++)
		{
			gets(find[i]);
			gets(replace[i]);
		}
		gets(s);
		for(i=0;i<n;i++)
		{
			pos=check(i);
			while(pos>=0)
			{
				place(pos,i);
				pos=check(i);
			}
		}
		printf("%s\n",s);
	}
	return 0;
}*/
//this is code of thinker_bd-ac
#include<iostream> 
#include<string> 
#include<stdio.h> 
#define MAX_F_R 1000 
#define MAX_A 3600 


using namespace std; 


char find[MAX_F_R][MAX_F_R]; 
char replace[MAX_F_R][MAX_F_R]; 
char array[MAX_A]; 

int main() 
{ 
   int no_of_replace; 
   //freopen("10115.in","r",stdin); 
   while(1) 
   { 
      scanf("%d",&no_of_replace); 
      if(no_of_replace==0) 
      break; 
        
      memset(find,0,sizeof(find)); 
      memset(replace,0,sizeof(replace)); 
      memset(array,0,sizeof(array)); 
        
          
      getchar(); 
      int i=0; 
      int num=no_of_replace; 
        
      while(no_of_replace--) 
      { 
         gets(find[i]);    
         gets(replace[i]); 
         i++;        
      } 
        
      gets(array);        
      string s=array; 
        
      i=0; 
      while(num--) 
      { 
         string f=find[i]; 
         string r=replace[i]; 
          
         int pos=s.find(f); 
    
         /*while(pos!=string::npos) 
         { 
            s.replace(pos,f.length(),r); 
            pos=s.find(f,pos+1); 
         }*/
		 while(pos!=-1) 
		{ 
			s.replace(pos,f.length(),r); 
			pos=s.find(f); 
		}
      i++;        
      } 
      cout<<s<<endl; 
   } 
   return 0; 
 }












