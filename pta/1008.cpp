#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v;
	int a;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		v.push_back(a);
	}
	vector<int> k(n);
	copy(v.begin(), v.end() - m, k.begin());
	for (int i = 1; i <= m; ++i)
	{
		k.insert(k.begin(), v[n - i]);
	}
	for (int i = 0; i < n; ++i)
	{
		if (i != n - 1)
		{
			cout << k[i] << " ";
		}
		else
		{
			cout << k[i] << endl;
		}
	}
	system("pause");
	return 0;
}
