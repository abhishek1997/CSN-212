#include <bits/stdc++.h>
using namespace std;
#define sws ios_base::sync_with_stdio(false); cin.tie(0)
#define io_file freopen("input_file.in", "r", stdin);freopen("output_file.out", "w", stdout)

struct node
{
	int low, high, max_val;
	node *left, *right;
	node()
	{
		low = high = max_val = -1;
		left = NULL;
		right = NULL;
	}
}*root, *pt;

void insert_interval(int l, int r)
{
	if(!(root))//If root is even not there
	{
		node *temp = new node;
		temp->low = l;
		temp->high = r;
		temp->max_val = r;
		root = temp;
		return;
	}
	pt = root;
	while(true)
	{
		pt->max_val = max(pt->max_val, r);//Updating the maximum value while traversing
		if((l < pt->low) || (l == pt->low && r <= pt->high))
		{
			if(pt->left)
				pt = pt->left;
			else
			{
				node *temp = new node;
				temp->low = l;
				temp->high = r;
				temp->max_val = r;
				pt->left = temp;
				return;
			}
		}
		else
		{
			if(pt->right)
				pt = pt->right;
			else
			{
				node *temp = new node;
				temp->low = l;
				temp->high = r;
				temp->max_val = r;
				pt->right = temp;
				return;
			}
		}
	}
}

void traverse_tree(node *vertex)//basic inorder traversal to see if tree formed is correct or not
{
	if(vertex)
	{
		traverse_tree(vertex->left);
		cout << vertex->low << " " << vertex->high << " : " << vertex->max_val << '\n';
		traverse_tree(vertex->right);
	}
	return;
}

bool search_interval(node *vertex, int l, int r)//searching the intersection of [l,r] with any of node
{
	if(!(vertex))//no interval
		return false;
	if((l >= vertex->low && l <= vertex->high) || (r >= vertex->low && r <= vertex->high))//intersection found
		return true;
	pt = vertex->left;
	if(pt)
	{
		if(pt->max_val >= l)//certainty of not selecting right child
			return search_interval(pt, l, r);
	}
	pt = vertex->right;
	return search_interval(pt, l, r);
}

node* min_value_interval(node * vertex)
{
	if(vertex->left)
		return min_value_interval(vertex->left);
	return vertex;
}

node* delete_interval(node *vertex, int l, int r)
{
	if(vertex == NULL)
		return vertex;
	if((l < vertex->low) || (l == vertex->low && r < vertex->high))//updating the left sub-tree
		vertex->left = delete_interval(vertex->left, l, r);
	else if((l > vertex->low) || (l == vertex->low && r > vertex->high))//updating the right sub-tree
		vertex->right = delete_interval(vertex->right, l, r);
	else//if the current node is to be deleted
	{
		if(vertex->left == NULL)//if at most 1 child
		{
			node *temp = vertex->right;
			free(vertex);
			return temp;
		}
		else if(vertex->right == NULL)//if atmost 1 child
		{
			node *temp = vertex->right;
			free(vertex);
			return temp;
		}
		node *temp = min_value_interval(vertex->right);//if 2 children
		vertex->low = temp->low;
		vertex->high = temp->high;
		vertex->max_val = temp->max_val;
		vertex->right = delete_interval(vertex->right, temp->low, temp->high);
	}
	vertex->max_val = vertex->high;//updating the max_val while traversing to the root
	if(vertex->left)
		vertex->max_val = max(vertex->max_val, (vertex->left)->max_val);
	if(vertex->right)
		vertex->max_val = max(vertex->max_val, (vertex->right)->max_val);
	return vertex;
}

int main()
{
	sws;
	io_file;
	int n, i, l, r;
	string s;
	cin >> n;
	root = NULL;
	for(i = 1; i <= n; i++)
	{
		cin >> s;
		if(s == "insert")//insert type query
		{
			cin >> l >> r;
			insert_interval(l, r);
		}
		else if(s == "delete")//delete type query
		{
			cin >> l >> r;
			root = delete_interval(root, l, r);
		}
		else if(s == "search")//search type query
		{
			cin >> l >> r;
			if(search_interval(root,l,r))
				cout << "intersection found\n";
			else
				cout << "intersection not found\n";
		}
		else
			cout << "not a valid option\n";
	}
	return 0;
}
