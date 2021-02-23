#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 105

typedef struct
{
    char sin[50];
    char plu[50];
}dic;

dic str[SIZE];
int ir;

int comp(const void *a,const void *b)
{
    dic *x=(dic *)a, *y=(dic *)b;
    return strcmp(x->sin,y->sin);
}

int find(char *s)
{
    int i,t;
    for(i=0;i<ir;i++)
	{
        t=strcmp(str[i].sin,s);
        if(!t) return i;
        if(t>0) return -1;
    }

    return -1;
}

int iscons(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return 0;
    return 1;
}
int main()
{
    int n,l,i,t;
    char s1[100];
   
    while(scanf("%d%d",&ir,&n)!=EOF)
	{
        for(i=0;i<ir;i++)
            scanf("%s%s",str[i].sin,str[i].plu);
        qsort(str,ir,sizeof(dic),comp);

        for(i=0;i<n;i++)
		{
            scanf("%s",s1);
            l=strlen(s1);
            if((t=find(s1))!=-1)
			{
                puts(str[t].plu);
            }
            else if(l>1 && s1[l-1]=='y' && iscons(s1[l-2]))
			{
                s1[l-1]=0;
                printf("%sies\n",s1);
            }
            else if(s1[l-1]=='o' || s1[l-1]=='s' || s1[l-1]=='x')
			{
                printf("%ses\n",s1);
            }
            else if(l>1 && s1[l-1]=='h' && (s1[l-2]=='c' ||s1[l-2]=='s'))
			{
                printf("%ses\n",s1);
            }
            else printf("%ss\n",s1);
        }
    }

    return 0;
}
