#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000011
#define sws ios_base::sync_with_stdio(false); cin.tie(0)
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

const int N = 100009;

int dist[N];
pair < pair < int, int >, int > edge[N];

void init(int V)
{
	int i;
	for(i = 0; i <= V; i++)
		dist[i] = INF;
}

void bellman_ford(int S, int V, int E)
{
	int i, u, j, v, w;
	init(V);
	dist[S] = 0;
	for(i = 1; i <= V; i++)
	{
		for(j = 1; j <= E; j++)
		{
			u = edge[j].first.first;
			v = edge[j].first.second;
			w = edge[j].second;
			if(dist[u] < INF && dist[u]+w < dist[v])
				dist[v] = dist[u] + w;
		}
	}
	for(i = 1; i <= E; i++)
	{
		u = edge[j].first.first;
		v = edge[j].first.second;
		w = edge[j].second;
		if(dist[u]+w < dist[v])
		{
			cout << "Graph contains a negative weight cycle\n";
			return;
		}
	}
	for(i = 1; i <= V; i++)
		cout << i << " : " << dist[i] << '\n';
	return;
}

int main()
{
	// sws;
	clock_t clk;
	clk = clock();
	io_file;
	// srand (time(NULL));

	//Code here
	int V, E, i, u, v, w, S;
	cin >> V >> E >> S;
	for(i = 1; i <= E; i++)
	{
		cin >> u >> v >> w;
		edge[i] = make_pair(make_pair(u,v), w);
	}
	bellman_ford(S, V, E);
	//Code ends here

	clk = clock() - clk;
	cout << fixed << setprecision(6) << "Time: " << (((double)clk)/CLOCKS_PER_SEC)*1000.000000 << " ms\n";
	return 0;
}
