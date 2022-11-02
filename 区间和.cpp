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

int find(int x)                         //find(),为了保证接口,常常返回大于x的最小,log(alls)的复杂度
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)r = mid;      //有序的,如果mid的值>=x,那么mid可能是边界,不能舍去
        else l = mid + 1;               //mid一定不是边界,可以舍去
    }
    return r + 1;
}                                       //函数不讨论所有元素全部不比x大的情况,由数据决定不用讨论.r+1为了偏移量

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)            //用一个向量存储所有增加
    {
        int x, c;
        cin >> x >> c;
        add.push_back({ x,c });
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)            //用一个向量存储所有查询
    {
        int l, r;
        cin >> l >> r;
        query.push_back({ l,r });
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());      //用到的,全部离散化
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