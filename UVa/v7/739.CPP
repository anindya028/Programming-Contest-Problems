/*this is my code which got 2 PE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int code[]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
	int *freq,i,j;
	char s[50],ans[50];
	printf("         NAME                     SOUNDEX CODE\n");
	while(gets(s))
	{
		if(s[0]==EOF)break;
		freq=(int *)calloc(7,sizeof(int));
		ans[0]=s[0];
		freq[code[s[0]-'A']]++;
		for(i=1,j=1;s[i];i++)
		{
			if(code[s[i]-'A'])
			{
				if(!freq[code[s[i]-'A']])
				{
					ans[j]=code[s[i]-'A']+'0';
					j++;
                                        if(j==4)break;
					free(freq);
					freq=(int *)calloc(7,sizeof(int));
					freq[code[s[i]-'A']]++;
				}
				
			}
			else
			{
				free(freq);
				freq=(int *)calloc(7,sizeof(int));
			}
		}
		free(freq);
		for(;j<4;j++)ans[j]='0';
		ans[j]='\0';
		printf("	 %s",s);
		i=strlen(s);
		for(j=0;j<(25-i);j++)printf(" ");
		printf("%s\n",ans);
	}
	printf("		   END OF OUTPUT");//	 |         |              |\n	 |         |              |__ Column 35\n	 |         |__ Column 20\n	 |__ Column 10\n");
	return 0;
}*/
//this is code from board ac
#include <stdio.h> 

char res; 

bool Code(char c) 
{ 
   res='a'; 
   if (c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='H'||c=='W'||c=='Y') return false; 
   if (c=='B'||c=='F'||c=='P'||c=='V') {res='1'; return true;} 
   if (c=='C'||c=='G'||c=='J'||c=='K'||c=='Q'||c=='S'||c=='X'||c=='Z') {res='2'; return true;} 
   if (c=='D'||c=='T') {res='3'; return true;} 
   if (c=='L') {res='4'; return true;} 
   if (c=='M'||c=='N') {res='5'; return true;} 
   if (c=='R') {res='6'; return true;} 
   res=' '; 
   return false; 
} 

int main() 
{ 
#ifndef ONLINE_JUDGE 
   freopen("in.txt","r",stdin); 
   freopen("out.txt","w",stdout); 
#endif 
   int size,length; 
   char in[80],out[6],*t1,*t2,last; 
   puts("         NAME                     SOUNDEX CODE"); 
   while (scanf("%s",in)!=EOF) 
   { 
      printf("         %s",in); 
      t1=in; 
      t2=out; 
      size=0; 
      *t2=*t1; 
      length=1; 
      Code(*t1); 
      last=res; 
      t1++; 
      t2++; 
      for (;(*t1!='\0')&&(length<4);t1++,size++) 
      { 
         if (Code(*t1)&&(last!=res)) 
         { 
            *t2=res; 
            t2++; 
            length++; 
         } 
         if (res!=' ')last=res; 
      } 
      for (;length<4;t2++,length++) 
         *t2='0'; 
      *t2='\0'; 
      for (;*t1!='\0';t1++,size++) ; 
      for (;size<24;size++) putchar(' '); 
      puts(out); 
   } 
   puts("                   END OF OUTPUT"); 
   return 0; 
}












