#include <bits/stdc++.h>
using namespace std;

#define io_file freopen("D:/Coding Problems/Contest/input_file.in", "r", stdin);freopen("D:/Coding Problems/Contest/output_file.out", "w", stdout)

void merge(int *a, int *l, int *r, int n, int mid)
{
	int i, j, k;
	i = j = k = 0;
	while(i < mid && j < n-mid)
	{
		if(l[i] <= r[j])
		{
			a[k] = l[i];
			i++;
		}
		else
		{
			a[k] = r[j];
			j++;
		}
		k++;
	}
	while(i < mid)
	{
		a[k] = l[i];
		i++;
		k++;
	}
	while(j < n-mid)
	{
		a[k] = r[j];
		j++;
		k++;
	}
	return;
}

void mergesort(int *a, int n)
{
	if(n == 1)
		return;
	int mid = n>>1, i;
	int l[mid], r[n-mid];
	for(i = 0; i < mid; i++)
		l[i] = a[i];
	for(i = mid; i < n; i++)
		r[i-mid] = a[i];
	mergesort(l, mid);
	mergesort(r, n-mid);
	merge(a, l, r, n, mid);
	return;
}

int main()
{
	//io_file;//see macro at line 4
	int n, i;
	cin >> n;
	int a[n];
	for(i = 0; i < n; i++)
		cin >> a[i];//taking array input
	mergesort(a, n);
	for(i = 0; i < n; i++)
		cout << a[i] << " ";//non-decreasing order
	return 0;
}
