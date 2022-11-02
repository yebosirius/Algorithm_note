#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> PII;
vector<PII> P;

vector<PII> merge(vector<PII>& pairs)
{
    vector<PII> res;
    sort(pairs.begin(), pairs.end());
    int st = -2e9, ed = -2e9;
    for (auto item : pairs)
    {
        if (ed < item.first)
        {
            if (st != -2e9)res.push_back({ st,ed });
            st = item.first; ed = item.second;
        }
        else ed = max(ed, item.second);
    }
    if (st != -2e9)res.push_back({ st,ed });
    return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		P.push_back({ l,r });
	}
	printf("%d", merge(P).size());
}