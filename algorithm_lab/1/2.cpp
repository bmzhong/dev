#include <iostream>
using namespace std;
class priority_queue
{
private:
	int cnt = 0;
	int a[1000];

public:
	int maxinum();
	bool empty();
	void down(int k);
	void up(int k);
	int extract_max();
	void increase_key(int k, int new_value);
	void insert(int value);
};
bool priority_queue::empty()
{
	return cnt == 0;
}
int priority_queue::maxinum()
{
	if (empty())
		exit(1);
	return a[1];
}
void priority_queue::down(int k)
{
	int l = 2 * k;
	int r = 2 * k + 1;
	int max = k;
	if (l <= cnt && a[l] > a[k])
		max = l;
	if (r <= cnt && a[r] > a[max])
		max = r;
	if (max != k)
	{
		int temp = a[k];
		a[k] = a[max];
		a[max] = temp;
		down(max);
	}
}
void priority_queue::up(int k)
{
	int parent = k / 2;
	while (k > 1 && a[parent] < a[k])
	{
		int temp = a[k];
		a[k] = a[parent];
		a[parent] = temp;
		k = parent;
	}
}
int priority_queue::extract_max()
{
	if (cnt < 1)
		exit(1);
	int max = a[1];
	a[1] = a[cnt];
	--cnt;
	down(1);
	return max;
}
void priority_queue::increase_key(int k, int new_value)
{
	if (new_value < a[k])
		exit(1);
	a[k] = new_value;
	up(k);
}
void priority_queue::insert(int value)
{
	++cnt;
	a[cnt] = -2147483648;
	increase_key(cnt, value);
}
int n, s[100];
int main()
{
	priority_queue pq;
	cout << "input: " << endl;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		pq.insert(s[i]);
	}
	cout << "output: " << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << pq.extract_max() << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
/*
case 1
6
4 6 5 2 1 3
*/