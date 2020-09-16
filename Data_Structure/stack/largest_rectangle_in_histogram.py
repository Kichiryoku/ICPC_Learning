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
            maxArea = max(maxArea, heights[i] * (y - x - 1))
        return maxArea


H = [2, 1, 5, 6, 2, 3]
solution = Solution()
print(solution.largestRectangleArea(heights=H))
