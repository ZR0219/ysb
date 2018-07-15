#include<iostream>
using namespace std;
int max(int x,int y)
{
	if(x>y)
	return x;
	else 
	return y;
}
int main()
{
	int a1,a2,a3,a4,a5,a6;
	
	while(scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6)&&a1+a2+a3+a4+a5+a6)
	{
		int sum=0;
		sum+=a6;
		sum+=a5;
		a1=max(0,a1-a5*11);
		sum+=a4;
		if(a2/5<a4)
			a1=max(0,a1-(a4*5-a2));
		a2=max(0,a2-a4*5);
		sum+=(a3+3)/4;
		a3=a3%4;
		if(a3==3)
		{
			if(a2<1)
			a1=max(0,a1-(9-4*a2));
			else
			a1=max(0,a1-5);
			a2=max(0,a2-1);
		}
		else if(a3==2)
		{
			if(a2<3) 
			a1 = max(0, a1-(18-4*a2));
            else     
			a1 = max(0, a1-6);
            a2 = max(0, a2-3);
		}
		else if(a3==1)
		{
			if(a2<5) 
			a1 = max(0, a1-(27-4*a2));
            else     
			a1 = max(0, a1-7);
            a2 = max(0, a2-5);
		}
		sum+=(a2+8)/9;
		a2=a2%9;
		if(a2) 
		a1 = max(0, a1-(36-4*a2)); 
		sum+=(a1+35)/36;
		printf("%d\n",sum);
	}
	
	return 0;			
}
