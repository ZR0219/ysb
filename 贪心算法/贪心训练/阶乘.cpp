#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 15;
char a[MAX];
bool cmp(int x, int y)
{
	return x>y;
}
int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i<n; i++)
 		cin >> a[i];
	int s, j = 0;
	char b[1000];
	for (int i = 0; i < n; i++)
	{
		switch (a[i])
		{
			case '2':b[j++] = '2'; break;
			case '3':b[j++] = '3'; break;
			case '4':b[j++] = '3'; b[j++] = '2'; b[j++] ='2'; break;
			case '5':b[j++] = '5'; break;
			case '6':b[j++] = '5'; b[j++] = '3'; break;
			case '7':b[j++] = '7'; break;
			case '8':b[j++] = '7'; b[j++] = '2'; b[j++] = '2'; b[j++] = '2'; break;
			case '9':b[j++] = '7'; b[j++] = '3'; b[j++] = '3'; b[j++] = '2'; break;
		}
	}
	for (s = 0; s<j; s++)
		sort(b, b + j, cmp);
	for (s = 0; s<j; s++)
		cout << b[s];
	cout << endl;
	return 0;
}

