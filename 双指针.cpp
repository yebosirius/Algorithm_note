#/*include <iostream>

using namespace std;

const int N = 1e+5 + 10;
int p[N], q[N];//p存储原数组,q作为一个位图

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)scanf("%d", &p[i]);
    int res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        q[p[i]]++;
        while (q[p[i]] > 1)
        {
            q[p[j]]--;
            j++;
        }
        res = max(res, i - j + 1);

    }
    cout << res;

}*/
/*
#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int A[N], B[N];

int n, m, x;

int main()
{
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++)scanf("%d", &A[i]);
    for (int i = 0; i < m; i++)scanf("%d", &B[i]);
    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (j >= 0 && A[i] + B[j] > x)j--;
        if (A[i] + B[j] == x)printf("%d %d", i, j);
    }
}

*/
/*
#include <iostream>
using namespace std;

const int N = 1e5+10;
int p[N],q[N];      //p为子列,q为原列

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)scanf("%d",&p[i]);
    for(int i = 0;i < m;i++)scanf("%d",&q[i]);
    
    for(int i = 0,j = 0;j < m;j++)
    {
        if(p[i] == q[j])i++;
        if(i == n)
        {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}*/