#include<stdio.h>
#define MAX 9
int a[MAX]={10000,5000,1000,500,200,100,50,20,10};
int num[MAX]={0};
int get_x(int n)
{
	int i;
	for( i=0;i<MAX;i++) //�ҵ���nС�������� 
		if(n>a[i])	break;
	while(n>0 && i<MAX)//������������������ 
	{
		if(n>=a[i])
		{
			n=n-a[i];
			num[i]++;
		}
		else if(n<10&&n>=5)//����0.5�֣�����ֵ 
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
	printf("����������Ǯ�Ľ�"); 
	scanf("%f",&x);
	get_x((int) 100*x);//��������Ǯ���� 
	printf("\n%.2fԪ��Ǯ����ɣ�\n",x);
	for(i=0;i<MAX;i++)//���������������������� 
	if(num[i]>0)
	printf("%.2f:%d��\n",(float)a[i]/100.0,num[i]);
	return 0;
}
//�ص㣺���ֲ��������ﵽȫ������ 
