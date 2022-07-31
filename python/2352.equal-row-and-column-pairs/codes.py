"""
给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。

如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。
"""
from typing import List



# 2022/07/30
from collections import defaultdict
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        rowsDict = defaultdict(int)
        cols = [[] for i in range(n)]
        for row in grid:
            rowsDict[tuple(row)] += 1
            for i in range(n):
                cols[i].append(row[i])

        colsDict = defaultdict(int)
        for col in cols:
            colsDict[tuple(col)] += 1

        ans = 0
        for row in rowsDict:
            for col in colsDict:
                if row==col:
                    ans += rowsDict[row]*colsDict[col]
                    break
        return ans



if __name__ == '__main__':

    # inputs
    grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]

    # solution
    ans = Solution().equalPairs(grid)

    # outputs
    print(ans)

