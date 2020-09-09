#include <iostream>
#include <set>

#include <cstdio>
#define MAXN 300005
using namespace std;

int depth[MAXN];
set<int> s;
int main()
{
    freopen("ICPC_Learning/Data_Structure/binary_tree/sum_of_binary_search_tree_in.in", "r", stdin);
    int n, num, sum = 0;
    cin >> n;
    s.insert(0);
    s.insert(n + 1); // 是为了出现当前最大最小值时，有返回迭代器
    depth[0] = -1, depth[n + 1] = -1;    // 代表这个迭代器所在根节点，矛盾，从而用另一个节点子树
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        if (i == 1)
            depth[num] = 0;
        else
        {
            set<int>::iterator it = s.lower_bound(num);
            
            int dept = max(depth[*it], depth[*(it--)]) + 1;
            depth[num] = dept;
            sum += dept;
        }
        s.insert(num);
        cout << sum << endl;
    }
    return 0;
}