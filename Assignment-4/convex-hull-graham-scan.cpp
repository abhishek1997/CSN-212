#include <bits/stdc++.h>
using namespace std;

#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

const int N = 10009;

class Point
{
	public:
	    int x, y;

	    bool operator < (Point b)
	    {
	        if (y != b.y)
	            return y < b.y;
	        return x < b.x;
	    }
}coord[N];

Point pivot;

int helper(Point a, Point b, Point c)
{
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

int dist(Point a, Point b)  
{
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool polar_order(Point a, Point b)
{
    int order = helper(pivot, a, b);
    if (order == 0)
        return dist(pivot, a) < dist(pivot, b);
    return (order == -1);
}

stack<Point> hull;

int main()
{
	// clock_t clk;
    // clk = clock();
    // io_file;
    // srand (time(NULL));

    int N, i;
    cin >> N;
    for(i = 0; i < N; i++)
    	cin >> coord[i].x >> coord[i].y;

    if (N >= 3)
    {
	    int leastY = 0;
	    for (i = 1; i < N; i++)
	    {
	        if (coord[i] < coord[leastY])
	            leastY = i;
	    }

	    Point temp = coord[0];
	    coord[0] = coord[leastY];
	    coord[leastY] = temp;

	    pivot = coord[0];
	    sort(coord + 1, coord + N, polar_order);

	    hull.push(coord[0]);
	    hull.push(coord[1]);
	    hull.push(coord[2]);

	    for(i = 3; i < N; i++)
	    {
	        Point top = hull.top();
	        hull.pop();
	        while (helper(hull.top(), top, coord[i]) != -1)
	        {
	            top = hull.top();
	            hull.pop();
	        }
	        hull.push(top);
	        hull.push(coord[i]);
	    }
	}

    while(!hull.empty())
    {
        Point p = hull.top();
        hull.pop();

        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    // clk = clock() - clk;
    // cout << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}
/*

Sample Input :
6
5 5
1 1
0 1
-5 5
1 2
3 -1

Sample Output :
(0, 1)
(-5, 5)
(5, 5)
(3, -1)

*/
