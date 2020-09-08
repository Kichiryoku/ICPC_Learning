#include <iostream>
#include <stack>

#include <cstdio>
using namespace std;

class Storage
{
    public:
        stack<int> ware; 
        stack<int> ware_for_req; // ware_for_req 存储当前入栈后的栈内最大值，模拟不可取
        inline void put_in_storage(int w)
        {
            if (ware_for_req.empty() || w > ware_for_req.top())
                ware_for_req.push(w);
            ware_for_req.push(w);
        }
        inline bool out_from_storage()
        {
            if (!ware.empty())
            {
                ware.pop();
                return false;
            } 
            return true;
        }
        // 这是会超时的做法，用辅助栈先存所有的货物求最大值
        inline int query_max_in_storage()
        {
            
            if (ware.empty())
                return 0;
            else
            {
                int max_weight = 0;
                while (!ware.empty())
                {
                    max_weight = ware.top() > max_weight ? ware.top() : max_weight;
                    ware_for_req.push(ware.top());
                    ware.pop();
                }
                while (!ware_for_req.empty())
                {
                    ware.push(ware_for_req.top());
                    ware_for_req.pop();
                }
                return max_weight;
            }
            
        }
};

int main()
{
    freopen("ICPC_Learning/Data_Structure/stack/log_analysis_stack_in.in", "r", stdin);
    Storage solution;
    int n, op, weight;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 0)
        {
            cin >> weight;
            solution.put_in_storage(weight);
        }
        else if (op == 1)
        {
            if (solution.out_from_storage())
                cout << 0 << endl;
        }
        else if (op == 2)
            cout << solution.query_max_in_storage() << endl;
    }
    return 0;
}
