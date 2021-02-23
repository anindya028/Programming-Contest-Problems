//this is my code->rte,wa,wa,wa,wa,ce 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
//#define Long __int64
//#define Long long long
struct dna
{
	char s[60];
	int unsort;
}*data;
char temp[60];
int n;
void bubble(int i)
{
	int j,k;
        char a;
	for(j=0;j<n-1;j++)
	{
		for(k=j+1;k<n;k++)
		{
			if(temp[j]>temp[k])
			{
				data[i].unsort++;
				a=temp[j];
				temp[j]=temp[k];
				temp[k]=a;
			}
		}
	}
	return;
}
bool operator<(dna a,dna b)
{
	return a.unsort<b.unsort;
}
int main()
{
	int m,i,j,t;
	scanf("%d\n",&t);
        for(j=0;j<t;j++)
	{
			if(j)printf("\n");
		scanf("%d %d\n",&n,&m);
		data=(dna *)calloc(m,sizeof(dna));
                for(i=0;i<m;i++)
		{
			scanf("%[^\n]\n",data[i].s);
			strcpy(temp,data[i].s);
			bubble(i);
		}
		sort(data,data+m);
		for(i=0;i<m;i++)printf("%s\n",data[i].s);
		free(data);
    }
	return 0;
}
/*this is felix halim's code->ac
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 60
#define MAXN 120

typedef struct {
  char chain[MAXLEN];
  int unsortedness;
} DNA;

DNA dna[MAXN];

int unsortedness(const void *a, const void *b){
  DNA *dna1 = (DNA*) a;
  DNA *dna2 = (DNA*) b;
  return dna1->unsortedness - dna2->unsortedness;
}

int countUnsortedness(char *s){
  int i,j,unsortedness=0;

  for (i=0; s[i]; i++)
    for (j=i+1; s[j]; j++)
      if (s[i] > s[j]) unsortedness++;

  return unsortedness;
}

int main(){
  int nTC, n,m,i;

  scanf("%d\n",&nTC);
  while (nTC--){
    scanf("%d %d\n", &n, &m);

    for (i=0; i<m; i++){
      gets(dna[i].chain); // same as scanf("%[^\n]\n", dna[i].chain);
      dna[i].unsortedness = countUnsortedness(dna[i].chain);
    }

    qsort(dna, m, sizeof(DNA), unsortedness);

    for (i=0; i<m; i++)
      puts(dna[i].chain);

    if (nTC!=0) puts("");
  }

  return 0;
}*/













