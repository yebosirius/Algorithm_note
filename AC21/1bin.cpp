#include <iostream>

using namespace std;

int lowbit(int x)
{
    return x & -x;
}
/*
int main()
{
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int x; scanf("%d", &x);
        int i;
        for (i = 0; x; x = x - (x & -x))i++;
        printf("%d ", i);
    }
}*/