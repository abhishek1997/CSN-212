#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false);cin.tie(0)
#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

const int N = 109;

long long dp[N][N];
bool bl[N][N][2];// 0 - verically

int main()
{
	sws;
	// clock_t clk;
	// clk = clock();
	//io_file;
	// srand (time(NULL));

	//Code here
	int x, y, n, i, j, a, b, p, q;
	cin >> x >> y;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> a >> b >> p >> q;
		if(a == p)
			bl[a][min(b,p)][0] = 1;
		else if(b == q)
			bl[min(a,p)][b][1] = 1;
	}
	dp[0][0] = 1;
	for(i = 0; i <= x; i++)
	{
		for(j = 0; j <= y; j++)
		{
			if(!bl[i][j][0])
				dp[i][j+1] += dp[i][j];
			if(!bl[i][j][1])
				dp[i+1][j] += dp[i][j];
		}
	}
	cout << dp[x][y] << '\n';
	//Code ends here

	// clk = clock() - clk;
	// cout << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
	return 0;
}
/*
Sample Input :
6 6
2
0 0 0 1
6 6 5 6

Sample Output :
252
*/
