#include <iostream>
#include <cstring>
using namespace std;
/*
#define MAXN 20

int memo[MAXN];
int get_catalan(int );
int catalan(int );

int get_catalan(int i)
{
    return memo[i] ? memo[i] : catalan(i);
}

int catalan(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += get_catalan(i) * get_catalan(n - 1 - i);
    }
    memo[n] = sum;
    return sum;
}
*/

int catalan(int n)
{
    if (!n) return 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += catalan(i) * catalan(n - 1 - i);
    }
    return sum;
}

int main()
{
    /*
    memset(memo, 0, MAXN * sizeof(int));
    memo[0] = 1;
    */
    int n;
    cin >> n;
    cout << catalan(n) << endl;
    return 0; 
}

/**
 * 总结栈的可能序列
 * 理解：考虑 1 在合法序列中的位置，在第 k 个位，前面 k-1 个数又合法性不会大于 k+1，后面有 n-1-k 个数
 * 递推公式： f(n) = \sum^{n-1}_{i=0} f(i)f(n-1-i)
 * 本质上是卡特兰数
 * 使用递归采取记忆化搜索提高效率：根据评测结果：n = 18 差不多是不用记忆化不超时的极限，993ms，用记忆化 2ms
 */