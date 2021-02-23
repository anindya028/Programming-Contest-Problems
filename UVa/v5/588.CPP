#include <stdio.h>

#define MAX 1001

int x[MAX],y[MAX];
int n,top,left,bottom,right;

int main()
{
	int i,j,caseno=1;
	while(scanf("%d",&n)==1 && n)
    {
		for (i=0; i<n; i++)
			scanf("%d%d",&x[i],&y[i]);
		left=right=x[0];
		top=bottom=y[0];
		for (i=1; i<n; i++)
        {
			if (x[i]<left) left=x[i];
			if (x[i]>right) right=x[i];
			if (y[i]>top) top=y[i];
			if (y[i]<bottom) bottom=y[i];
		}
		for (i=0; i<n; i++)
        {
			j=(i+n-1)%n;
			if (y[j]==y[i])
            {
				if (x[j]<x[i]&&y[i]<top) top=y[i];
				else if (x[j]>x[i]&&y[i]>bottom) bottom=y[i];
				if (top<bottom) break;
			}
			else if (x[j]==x[i])
            {
				if (y[j]<y[i]&&x[i]>left) left=x[i];
				else if (y[j]>y[i]&&x[i]<right) right=x[i];
				if (right<left) break;
			}
		}
		printf("Floor #%d\n",caseno);
		caseno++;
		if (left<=right&&top>=bottom)
			printf("Surveillance is possible.\n");
		else printf("Surveillance is impossible.\n");
		printf("\n");
	}
	return 0;
}
