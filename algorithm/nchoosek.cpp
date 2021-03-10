#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
vector<int> b;
void fun(int a)
{
	cout << a << " ";
}
void show(vector<int> a)
{
	for_each(a.begin(),a.end(),fun);
	cout << endl;
}

//这个函数的功能是求从数组a的n个数中选出k个数放到数组b之中
void nchoosek(int n,int k)
{
	int i;
	if(k==0)
	{
		show(b);
	}
	else
	{   
		//这个地方i是下标
		for(i=k-1;i<=n-1;i++)
		{
			//确定倒数第一个数
			b[k-1]=a[i];
			//大问题转化为小问题
			//这个地方的i是小问题n的规模
			//二者的意义是不一样的，切记
			nchoosek(i,k-1);
		}
	}
}

void nchoosek_wrap(int n,int k)
{
	sort(a.begin(),a.end());
	nchoosek(n,k);
}

int main()
{
	int n,k;
	cin >> n >> k;
    a.resize(n);
    b.resize(k);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	nchoosek_wrap(n,k);
    system("pause");
	return 0;
}

