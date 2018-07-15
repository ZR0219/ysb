#include<stdio.h>
#define MAX 9
int a[MAX]={10000,5000,1000,500,200,100,50,20,10};
int num[MAX]={0};
int get_x(int n)
{
	int i;
	for( i=0;i<MAX;i++) //找到比n小的最大面额 
		if(n>a[i])	break;
	while(n>0 && i<MAX)//计算各个面额所需张数 
	{
		if(n>=a[i])
		{
			n=n-a[i];
			num[i]++;
		}
		else if(n<10&&n>=5)//计算0.5分，不差值 
		{
			num[MAX-1]++;
			break;
		}
		else i++;
	}
	return 0;
}
int main()
{
	int i;
	float x;
	printf("输入需找零钱的金额："); 
	scanf("%f",&x);
	get_x((int) 100*x);//调用找零钱函数 
	printf("\n%.2f元零钱的组成：\n",x);
	for(i=0;i<MAX;i++)//依次输出各个面额所需张数 
	if(num[i]>0)
	printf("%.2f:%d张\n",(float)a[i]/100.0,num[i]);
	return 0;
}
//特点：做局部最优来达到全局最优 
