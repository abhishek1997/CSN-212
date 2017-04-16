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

int helper(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int next_pt[N];
void convexHull(Point array[], int n)
{
    if (n < 3)
        return;
 
    for (int i = 0; i < n; i++)
        next_pt[i] = -1;

    int l = 0;
    for (int i = 1; i < n; i++)
    {
        if (array[i].x < array[l].x)
            l = i;
    }

    int p = l, q;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (helper(array[p], array[i], array[q]) == 2)
                q = i;
        }
        next_pt[p] = q;
        p = q;
    } while (p != l);

    for (int i = 0; i < n; i++)
    {
        if (next_pt[i] != -1)
            cout << "(" << array[i].x << ", " << array[i].y << ")\n";
    }
}

int main()
{
    // clock_t clk;
    // clk = clock();
    // io_file;
    // srand (time(NULL));

    int n, i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> coord[i].x >> coord[i].y;
    convexHull(coord, n);
    
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
(5, 5)
(0, 1)
(-5, 5)
(3, -1)

*/
