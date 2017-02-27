#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cin.tie(0)
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

const int N = 10009;

int a[N<<1], st[N<<3], dp[N];
pair < int, int > p[N];

void build(int node, int l, int r)
{
	if(l == r)
	{
		st[node] = 0;
		return;
	}
	int mid = (l+r)>>1;
	int left = node<<1;
	int right = left|1;
	build(left, l, mid);
	build(right, mid+1, r);
	st[node] = 0;
	return;
}

void update(int node, int l, int r, int ind, int val)
{
	if(l > r || ind < l || ind > r)
		return;
	if(l == r)
	{
		st[node] = val;
		return;
	}
	int mid = (l+r)>>1;
	int left = node<<1;
	int right = left|1;
	update(left, l, mid, ind, val);
	update(right, mid+1, r, ind, val);
	st[node] = max(st[left], st[right]);
	return;
}

int query(int node, int l, int r, int p, int q)
{
	if(l > r || l > q || p > r)
		return 0;
	if(l >= p && r <= q)
		return st[node];
	int mid = (l+r)>>1;
	int left = node<<1;
	int right = left|1;
	return max(query(left, l, mid, p, q), query(right, mid+1, r, p, q));
}

int func(int ind, int n)
{
	int i, ans = 0;
	for(i = ind; i < ind+n; i++)
		p[i-ind+1] = make_pair(a[i], -(i-ind+1));
	sort(p+1,p+n+1);
	build(1,1,n);
	for(i = 1; i <= n; i++)
	{
		dp[-p[i].second] = query(1,1,n,1,-p[i].second) + 1;
		update(1,1,n,-p[i].second,dp[-p[i].second]);
	}
	for(i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	return ans;
}

int main()
{
	sws;
	// clock_t clk;
	// clk = clock();
	//io_file;
	// srand (time(NULL));

	//Code here
	int n, i, ans = 0, t;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n;
		for(i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[n+i] = a[i];
		}
		for(i = 1; i <= n; i++)
			ans = max(ans, func(i, n));
		cout << ans << '\n';
	}
	//Code ends here

	// clk = clock() - clk;
	// cout << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
	return 0;
}
/*
Sample Input :
3
2
0 0
3
3 2 1
6
4 8 6 1 5 2

Sample Output :
1
2
4
*/
