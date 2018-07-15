#include<iostream>
using namespace std;
#define MAX 2000
int y[MAX];
int swap(int n,int k)
{
	int i,sum,count=0;
	for(i=0;i<n;i++)
	{
		if((y[i]+k)<=5)
		{
			count++;
		}
	}
	sum=count/3;
	return sum;
}
int main()
{
	int n,k,i;
	cin>>n;
	cin>>k;
	for(i=0;i<n;i++)
		cin>>y[i];
	int s=swap(n,k);
	cout<<s<<endl;
	return 0;	
} 
