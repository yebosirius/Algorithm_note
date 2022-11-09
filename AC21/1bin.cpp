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
//真是让人害怕
//今天重新写这个的时候,for里面写了int i = x,k = 0,然后果不其然wa了
//我很疑惑,为什么会wa
//然后去问cjj,cjj说k重新定义了
//无语
