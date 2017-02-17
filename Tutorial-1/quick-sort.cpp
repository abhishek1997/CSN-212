#include <bits/stdc++.h>
using namespace std;

#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

int partition(int *a, int l, int r)
{
	int pivot = a[r];
	int i = l, j;
	for(j = l; j < r; j++)
	{
		if(a[j] <= pivot)
		{
			swap(a[j], a[i]);
			i++;
		}
	}
	swap(a[i], a[r]);
	return i;
}

void quicksort(int *a, int l, int r)
{
	if(r <= l)
		return;
	int p = partition(a, l, r);
	quicksort(a, l, p-1);
	quicksort(a, p+1, r);
	return;
}

int main()
{
	//io_file;//see macro at line 4
	int n, i;
	cin >> n;
	int a[n];
	for(i = 0; i < n; i++)
		cin >> a[i];//taking input
	quicksort(a, 0, n-1);
	for(i = 0; i < n; i++)
		cout << a[i] << " ";//non-decreasing order
	return 0;
}
