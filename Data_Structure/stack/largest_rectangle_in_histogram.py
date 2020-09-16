from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea = 0
        for i in range(len(heights)):
            x, y = -1, len(heights)
            for j in range(i, -1, -1):
                if heights[j] < heights[i]:
                    x = j
                    break
            for k in range(i, len(heights)):
                if heights[k] < heights[i]:
                    y = k
                    break
            # 找到 height[i] 两侧第一个比自己矮的，下标为 x,y ，计算夹在中间的面积宽为 y - x- 1
            maxArea = max(maxArea, heights[i] * (y - x - 1))
        return maxArea


H = [2, 1, 5, 6, 2, 3]
solution = Solution()
print(solution.largestRectangleArea(heights=H))
