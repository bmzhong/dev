#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000;
int s[maxn], t[maxn], n, x;
void merge_sort(int l, int r);
void solve();
bool binary_search(int a);
int main()
{
	cout << "input: " << endl;
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	cout << "output: " << endl;
	solve();
	system("pause");
	return 0;
}

void solve()
{
	merge_sort(0, n - 1);
	int count = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		if (binary_search(x - s[i]))
		{
			count++;
			// cout << s[i] << "+" << x - s[i] << "=" << x << endl;
		}
	}
	cout << count << endl;
}

bool binary_search(int a)
{
	int l = 0, r = n - 1, m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (s[m] == a)
			return true;
		else if (s[m] < a)
			l = m + 1;
		else
			r = m - 1;
	}
	return false;
}
void merge_sort(int l, int r)
{
	if (r > l)
	{
		int m = (l + r) / 2;
		merge_sort(l, m);
		merge_sort(m + 1, r);
		int i = l, j = m + 1, k = l;
		while (i <= m && j <= r)
		{
			if (s[i] <= s[j])
				t[k++] = s[i++];
			else
				t[k++] = s[j++];
		}
		while (i <= m)
			t[k++] = s[i++];
		while (j <= r)
			t[k++] = s[j++];
		for (int k = l; k <= r; ++k)
		{
			s[k] = t[k];
		}
	}
}
/*
case 1
6 10
1 9 2 8 3 7
*/
