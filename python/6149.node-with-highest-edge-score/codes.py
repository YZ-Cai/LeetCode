"""
给你一个有向图，图中有 n 个节点，节点编号从 0 到 n - 1 ，其中每个节点都 恰有一条 出边。

图由一个下标从 0 开始、长度为 n 的整数数组 edges 表示，其中 edges[i] 表示存在一条从节点 i 到节点 edges[i] 的 有向 边。

节点 i 的 边积分 定义为：所有存在一条指向节点 i 的边的节点的 编号 总和。

返回 边积分 最高的节点。如果多个节点的 边积分 相同，返回编号 最小 的那个。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/node-with-highest-edge-score
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/08/14
class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        n = len(edges)
        scores = [0] * n
        
        for i in range(n):
            scores[edges[i]] += i
        m, ans = -1, -1
        for i in range(n):
            if scores[i]>m:
                m = scores[i]
                ans = i
        return ans
            



if __name__ == '__main__':

    # inputs
    edges = [1,0,0,0,0,7,7,5]

    # solution
    ans = Solution().edgeScore(edges)

    # outputs
    print(ans)

