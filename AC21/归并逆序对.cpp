#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int nums[N], temp[N];

void Merge_Sort(int nums[], int l, int r)
{
	if (l >= r)return;
	int mid = l + r >> 1;
	Merge_Sort(nums, l, mid);
	Merge_Sort(nums, mid + 1, r);

	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r)
	{
		if (nums[i] <= nums[j])temp[k++] = nums[i++];
		else temp[k++] = nums[j++];
	}
	while (i <= mid)temp[k++] = nums[i++];
	while (j <= r)temp[k++] = nums[j++];

	i = l, j = 0;
	for (; i <= r; i++, j++)nums[i] = temp[j];
}

LL merge_sort(int nums[], int l, int r)						//ÄæÐò¶Ô
{
	if (l >= r)return 0;
	int mid = l + r >> 1;
	LL res = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);

	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r)
	{
		if (nums[i] <= nums[j])temp[k++] = nums[i++];
		else
		{
			temp[k++] = nums[j++];
			res = res + mid + 1 - i;
		}
	}
	while (i <= mid)temp[k++] = nums[i++];
	while (j <= r)temp[k++] = nums[j++];

	for (i = l, j = 0; i <= r; i++, j++)nums[i] = temp[j];
	return res;

}
/*
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)scanf("%d", &nums[i]);
	cout << merge_sort(nums, 0, n - 1);
	Merge_Sort(nums, 0, n - 1);
	for (int i = 0; i < n; i++)printf("%d ", nums[i]);
}*/