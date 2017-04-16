#include <bits/stdc++.h>
using namespace std;

#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

const int N = 10009;

struct Point
{
	int x, y;
}hull[N], point[N];

void print_point(Point p)
{
	cout << "(" << p.x << ", " << p.y << ")\n";
}

int calc_area(Point p, Point q, Point r)
{
	return abs( p.x*(q.y-r.y) + q.x*(r.y-p.y) + r.x*(p.y-q.y) );
}

int calc_dis(Point p, Point q, Point r)
{
	int num,den;
	num = calc_area(p, q, r);
	return num;
}

int h = 0;

int get_sign(Point A, Point B, Point X)
{
	int sign = (A.y-B.y)*X.x + (B.x-A.x)*X.y + (B.y*A.x-A.y*B.x);
	if(sign>0)
		return 1;
	if(sign<0)
		return -1;
	return 0;
}

void convex_hull(Point *point, int n, Point A, Point B)
{
	if(n <= 0)
		return;
	int ind = 0, max_dis, temp_dis;
	for(int i=0;i<n;i++)
	{
		temp_dis = calc_dis(A, B, point[i]);
		if(i==0)
			max_dis=temp_dis;
		else if(temp_dis > max_dis)
		{
			max_dis = temp_dis;
			ind = i;
		}
	}
	hull[h++]=point[ind];
	Point C = point[ind];
	Point G;
	G.x = (A.x + B.x + C.x)/3;
	G.y = (A.y + B.y + C.y)/3;
	int sign = get_sign(A, C, G);
	Point *point_pos = new Point[n];
	Point *point_neg = new Point[n];
	int p=0, q=0;
	for(int i=0;i<n;i++)
	{
		if(sign*get_sign(A,C,point[i]) < 0)
			point_pos[p++]=point[i];
	}
	sign = get_sign(B, C, G);
	for(int i=0;i<n;i++)
	{
		if(sign*get_sign(B,C,point[i]) < 0)
			point_neg[q++]=point[i];
	}
	convex_hull(point_pos, p, A, C);
	convex_hull(point_neg, q, C, B);	
}

int main()
{
	// clock_t clk;
    // clk = clock();
    // io_file;
    // srand (time(NULL));

	int n;
	cin >> n;
	int x_min=0, x_max=0;
	for(int i=0;i<n;i++)
	{
		cin >> point[i].x >> point[i].y;
		if(point[i].x < point[x_min].x)
			x_min=i;
		if(point[i].x > point[x_max].x)
			x_max=i;
	}
	Point *point_pos = new Point[n];
	Point *point_neg = new Point[n];
	int A,B,C;
	A = point[x_min].y - point[x_max].y;
	B = -point[x_min].x + point[x_max].x;
	C = point[x_max].y*point[x_min].x - point[x_min].y*point[x_max].x;
	int p=0, q=0, val;
	for(int i=0;i<n;i++)
	{
		if(i!=x_min && i!=x_max)
		{
			val = A*point[i].x + B*point[i].y + C;
			if(val>0)
				point_pos[p++]=point[i];
			if(val<0)
				point_neg[q++]=point[i];
		}
	}
	
	hull[h++] = point[x_min];
	hull[h++] = point[x_max];
	convex_hull(point_pos, p, point[x_min], point[x_max]);
	convex_hull(point_neg, q, point[x_min], point[x_max]);
	for(int i=0;i<h;i++)
		print_point(hull[i]);

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
(-5, 5)
(5, 5)
(3, -1)
(0, 1)

*/
