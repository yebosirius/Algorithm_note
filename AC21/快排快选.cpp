//基于swap的快排,参数分别是:要排序的向量,左端点,右端点
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int nums[N];
void Quick_Sort(int nums[], int l, int r)
{
	if (l >= r)return;									//递归基
	int i = l - 1, j = r + 1;
	int x = nums[i + j >> 1];							//轴点
	while (i < j)										//要么重合时停止,要么j i时候停止
	{													//若为后者,那么nums[j]满足:nums[j+1]>x
		do i++; while (nums[i] < x);
		do j--; while (x < nums[j]);
		if (i < j)swap(nums[i], nums[j]);
	}													//每一轮结束之后,轴点前面的小于等于,后面大于等于
	Quick_Sort(nums, l, j);								
	Quick_Sort(nums, j + 1, r);
}

int Quick_Search(int nums[], int l, int r, int k)
{
	if (l >= r)return nums[l];
	int i = l - 1, j = r + 1;
	int x = nums[i + j >> 1];
	while (i < j)
	{
		do i++; while (nums[i] < x);
		do j--; while (x < nums[j]);
		if (i < j)swap(nums[i], nums[j]);
	}
	int ll = j + 1 - l;
	if (k <= ll)return Quick_Search(nums, l, j, k);
	else return Quick_Search(nums, j + 1, r, k - ll);
}
