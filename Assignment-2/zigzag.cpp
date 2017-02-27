#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cin.tie(0)
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

const int N = 100009;

int a[N], dp[2][N];//0 - dec

int main()
{
	sws;
	// clock_t clk;
	// clk = clock();
	//io_file;
	// srand (time(NULL));

	//Code here
	int n, i, ans, j;
	cin >> n;
	for(i = 1; i <= n; i++)
		cin >> a[i];
	for(i = 1; i <= n; i++)
	{
		dp[0][i] = 0;
		for(j = 1; j < i; j++)
		{
			if(a[j] > a[i])
				dp[0][i] = max(dp[0][i], dp[1][j]);
		}
		dp[1][i] = 0;
		for(j = 1; j < i; j++)
		{
			if(a[j] < a[i])
				dp[1][i] = max(dp[1][i], dp[0][j]);
		}
		dp[0][i]++;
		dp[1][i]++;
	}
	ans = 0;
	for(i = 1; i <= n; i++)
		ans = max(ans, max(dp[0][i], dp[1][i]));
	cout << ans << '\n';
	//Code ends here

	// clk = clock() - clk;
	// cout << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
	return 0;
}
/*
Sample Input :
10
1 17 5 10 13 15 10 5 16 8

Sample Output :
7
*/
