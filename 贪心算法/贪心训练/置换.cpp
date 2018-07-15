#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100000;
int a[MAX];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n, k, i, t;
	cin>>n;
	cin>>k;
	int head = 1, tail = n;
	for (i = 0; i<n; i++)
	{
		if (i % 2 == 0)
			a[i] = head++;
		else
			a[i] = tail--;
	}
	if(k<n&&k>1)
	{
		if(k%2==1)
			sort(a+(k-1),a+n);
		else
			sort(a+(k-1),a+n,cmp);
		for (i = 0; i<n; i++)
			cout << a[i]<<" ";
	}	
	else if(k=1)
	{
		sort(a,a+n);
		for(i=0;i<n;i++)
			cout << a[i]<<" ";	
	}
	return 0;
}
