#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int NV = 102;			//·�������ֵ��N<=100��
const int NE = 20002;		//��·�����ֵ��M<=10000��
int n, m;					//����·�����͵�·��Ϊint��
struct Dijkstra				//�������㷨������װ�ڶ�����
{
	int n, size;
	int dis[NV], head[NV];		//dis[NV]��¼��㵽�������Ȩֵ��������ʱ�䣻head[NV]��¼����
	int mark[NV];				//��¼���Ƿ��߹�����ǣ�
	struct node
	{
		int v, dis;
		node() {}
		node(int V, int DIS) : v(V), dis(DIS) {}
		friend bool operator< (const node a, const node b)
		{
			return a.dis > b.dis;
		}
	};
	struct edge
	{
		int v, w, next;
		edge() {}
		edge(int V, int NEXT, int W = 0) : v(V), next(NEXT), w(W) {}
	}E[NE];
	inline void init(int x)			//��ʼ��nΪ���ڵ㣬����Ϊ0
	{
		n = x, size = 0;
		memset(head, -1, sizeof(int)* (x + 1));
	}
	inline void insert(int u, int v, int w)
	{
		E[size] = edge(v, head[u], w);
		head[u] = size++;
	}
	int dijkstra(int src, int des)
	{
		node first, next;
		priority_queue<node> Q;			//���ȶ��У�����Q����
		for (int i = 0; i <= n; i++)
		{
			dis[i] = INT_MAX;			//������·��Ȩֵ��ʼ��Ϊ���δ֪��
			mark[i] = false;			//������е��ʼ��Ϊδ�߹�
		}

		dis[src] = 0;					//�����Ȩֵ��0
		Q.push(node(src, 0));			//���

		while (!Q.empty())
		{
			first = Q.top();
			Q.pop();
			mark[first.v] = true;
			for (int i = head[first.v]; i != -1; i = E[i].next) {
				if (mark[E[i].v])
					continue;
				next = node(E[i].v, first.dis + E[i].w);
				if (next.dis < dis[next.v])
				{
					dis[next.v] = next.dis;
					Q.push(next);
				}
			}
		}
		return dis[des];
	}
}G;
int main()
{
	while (~scanf_s("%d%d", &n, &m), n || m) {
		G.init(n);			
		while (m--)
		{
			int u, v, w;
			scanf_s("%d%d %d", &u, &v, &w);
			G.insert(u - 1, v - 1, w);
			G.insert(v - 1, u - 1, w);
		}
		printf("%d\n", G.dijkstra(0, n - 1));
	}
	return 0;
}
