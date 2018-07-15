#include<stdio.h>
#define MAX 64
int a[MAX+1][MAX+1]={0};
void gamcal(int k,int n)
{
	int i,j;
	if(n==2)
	{
		a[k][1]=k;
		a[k][2]=k+1;
		a[k+1][1]=k+1;
		a[k+1][2]=k;
	}
	else
	{
		gamcal(k,n/2);
		gamcal(k+n/2,n/2);
		for(i=k;i<k+n/2;i++)
		{
			for(j=n/2+1;j<=n;j++)
			{
				a[i][j]=a[i+n/2][j-n/2];
			}
		}
		for(i=k/2;i<k+n;i++)
		{
			for(j=n/2+1;j<n;j++)
			{
				a[i][j]=a[i-n/2][j-n/2];
			}
		}
	}
 } 
int main()
{
	int m,i,j;
	printf("输入参赛选手人数：");
	scanf("%d",&m);
	j=2;
	for(i=2;i<8;i++)
	{
		j=j*2;
		if(j==m)
			break; 
	}
	if(i>=8)
	{
		printf("参赛选手必须是2的整数次幂，且不超过64！");
		//getch();
		return 0;
	}
	gamcal(1,m);
	printf("\n编号");
	for(i=2;i<=m;i++)
		printf("%2d天",i-1);
	printf("\n");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
			printf("%4d",a[i][j]);
		printf("\n"); 
	}
//	getch();
	return 0; 
} 
