#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /* 需要使用的是单调递减栈，栈顶到栈底递减 */
        stack<int> monoStack;
        int maxArea = 0, l ,m ,r;
        for (r = 0; r < heights.size(); r++)
        {
            while (!monoStack.empty() && heights[r] <= heights[monoStack.top()])
            {
                /* 单调栈的作用体现在，新的元素更小，栈顶元素弹出，同时新的栈顶元素递减，得到求面积的左右边界 */
                m = monoStack.top();
                monoStack.pop();
                l = monoStack.empty() ? -1 : monoStack.top();
                maxArea = max(maxArea, (r - l - 1) * heights[m]);
            }
            monoStack.push(r);
        }
        r = heights.size();
        while (!monoStack.empty())
        {
            m = monoStack.top();
            monoStack.pop();
            l = monoStack.empty() ? -1 : monoStack.top();
            /* 此时 heights 遍历完了，剩下的栈是单调递减栈，直接弹出边界 */
            maxArea = max(maxArea, (r - l - 1) * heights[m]);
        }
        return maxArea;
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution solution;
    cout << solution.largestRectangleArea(heights) << endl;
    return 0;
}