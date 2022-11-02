//����swap�Ŀ���,�����ֱ���:Ҫ���������,��˵�,�Ҷ˵�
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int nums[N];
void Quick_Sort(int nums[], int l, int r)
{
	if (l >= r)return;									//�ݹ��
	int i = l - 1, j = r + 1;
	int x = nums[i + j >> 1];							//���
	while (i < j)										//Ҫô�غ�ʱֹͣ,Ҫôj iʱ��ֹͣ
	{													//��Ϊ����,��ônums[j]����:nums[j+1]>x
		do i++; while (nums[i] < x);
		do j--; while (x < nums[j]);
		if (i < j)swap(nums[i], nums[j]);
	}													//ÿһ�ֽ���֮��,���ǰ���С�ڵ���,������ڵ���
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
