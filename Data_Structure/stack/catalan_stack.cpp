#include <iostream>
#include <cstring>
using namespace std;
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


int main()
{
    memset(memo, 0, MAXN * sizeof(int));
    memo[0] = 1;
    int n;
    cin >> n;
    cout << catalan(n) << endl;
    return 0; 
}