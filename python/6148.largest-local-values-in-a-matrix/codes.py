"""
给你一个大小为 n x n 的整数矩阵 grid 。

生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：

maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。

返回生成的矩阵。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-local-values-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/08/14
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = []
        for i in range(n-2):
            row = []
            for j in range(n-2):
                m = grid[i+1][j+1]
                for p in range(i, i+3):
                    for q in range(j, j+3):
                        m = max(m, grid[p][q])
                row.append(m)
            ans.append(row)
        return ans



if __name__ == '__main__':

    # inputs
    grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]

    # solution
    ans = Solution().largestLocal(grid)

    # outputs
    print(ans)

