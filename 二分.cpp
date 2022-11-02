//整数二分
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int nums[N];
int n, m;

void bin(int nums[], int l, int r,int x)
{
	while (l < r)
	{
		int mid = l + r >> 1;
		if (nums[mid] >= x)r = mid;
		else l = mid + 1;
	}
	if (nums[l] != x)cout << "-1 -1";
	else
	{
		cout << l << " ";
		l = 0; r = n - 1;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (nums[mid] <= x)l = mid;
			else r = mid - 1;
		}
		cout << l;
	}
	cout << endl;
}
//实数二分,求一个数的三次方根

double trip(double x)
{
	double l = -100.00, r = 100.00;
	{
		while (abs(l - r) > 1e-8)
		{
			double mid = (r + l) / 2;
			if (mid * mid * mid > x)r = mid;
			else l = mid;
		}
	}
	return l;
}