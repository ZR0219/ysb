#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100000
char coin[MAX];
void swap(char *p, int len)
{
	int i, o;
	char t;
	bool juge = false;
	for (i = 0; i<len; i++)
	{
		if ((int(p[i] % 2) == 0) && (p[i]<p[len - 1]))
		{
			t = p[i];
			p[i] = p[len - 1];
			p[len - 1] =t;
			cout << p;
			return;
		}
		else if (p[i] % 2 == 0)
		{
			juge = true;
			o = i;
		}
		if (i == len - 1)
		{

			if (!juge)
			{
				cout << -1;
				return;
			}
			t = p[o];
			p[o] = p[len - 1];
			p[len - 1] = t;
			cout << p;
		}
	}

}
int main()
{
	int len;
	cin >> coin;
	len = strlen(coin);
	swap(coin, len);
	return 0;
}
