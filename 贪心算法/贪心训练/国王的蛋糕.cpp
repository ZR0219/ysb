#include<iostream>
using namespace std;
int swap(int x, int y)
{
	int count = 0;
	while (x != y)
	{
		if (x > y)
		{
			count = count+ x / y;
			x = x%y;
		}
		else if (x < y)
		{
			count = count + y / x;
			y = y%x;
		}
		else
			break;
		if (x == 0 || y == 0)
			return count;
	}
	count = count + 1;
	return count;
}
int main()
{
	int T, i = 0;
	int m, n;
	int *a;
	cin >> T;
	a = new int[T * 2];
	while(cin>>n>>m)
	{
		T--;
		a[i++] = n;
		a[i++] = m;	
		if(T<1)
		break;
	}
	for (int s = 0; s<i / 2; s++)
	{
		cout << swap(a[2 * s], a[2 * s + 1]) << endl;
	}
	return 0;
}
