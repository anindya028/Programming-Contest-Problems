// Written in UVA submission window, AC without compiling :)

#include<stdio.h>
#include<string.h>

int main()
{
     int a, i, j;
     char s[1005],t[1005];
     while(scanf("%d%s",&a,s)==2)
     {
           if(!a && s[0]=='0' && s[1]==0)
                break;
           for(i=j=0;s[i];i++)
                if(s[i]!=(a+'0'))
                      t[j] = s[i], j++;
           t[j] = 0;
           for(j=0;t[j];j++)
                if(t[j]!='0')
                     break;
           if(!t[j])
                printf("0");
           else
                for(;t[j];j++)
                    printf("%c",t[j]);
           printf("\n"); 
     }

     return 0;
}