#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 10;

int n, m;
int a[N], b[N];

vector<int> alls;
typedef pair<int, int> PII;
vector<PII> add, query;

int find(int x)                         //find(),Ϊ�˱�֤�ӿ�,�������ش���x����С,log(alls)�ĸ��Ӷ�
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)r = mid;      //�����,���mid��ֵ>=x,��ômid�����Ǳ߽�,������ȥ
        else l = mid + 1;               //midһ�����Ǳ߽�,������ȥ
    }
    return r + 1;
}                                       //��������������Ԫ��ȫ������x������,�����ݾ�����������.r+1Ϊ��ƫ����

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)            //��һ�������洢��������
    {
        int x, c;
        cin >> x >> c;
        add.push_back({ x,c });
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)            //��һ�������洢���в�ѯ
    {
        int l, r;
        cin >> l >> r;
        query.push_back({ l,r });
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());      //�õ���,ȫ����ɢ��
    alls.erase(unique(alls.begin(), alls.end()), alls.end());


    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= alls.size(); i++)
    {
        b[i] = b[i - 1] + a[i];
    }

    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << b[r] - b[l - 1] << endl;
    }


}