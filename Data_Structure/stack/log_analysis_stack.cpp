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
            else
                ware_for_req.push(ware_for_req.top());   // 每次入栈时存储当前栈内最大值，出栈时同时出
            ware.push(w);
        }
        inline bool out_from_storage()
        {
            if (!ware.empty())
            {
                ware.pop();
                ware_for_req.pop();
                return false;
            } 
            return true;
        }
        inline int query_max_in_storage()
        {
            
            if (ware.empty())
                return 0;
            else
                return ware_for_req.top();
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
