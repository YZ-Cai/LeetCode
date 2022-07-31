"""
给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，其中每个节点 至多 有一条出边。

图用一个大小为 n 下标从 0 开始的数组 edges 表示，节点 i 到节点 edges[i] 之间有一条有向边。如果节点 i 没有出边，那么 edges[i] == -1 。

请你返回图中的 最长 环，如果没有任何环，请返回 -1 。

一个环指的是起点和终点是 同一个 节点的路径。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-cycle-in-a-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/07/31
class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        visited = set()
        mark = {}
        ans = 0
        
        for i in range(n):
            if i not in visited:
                mark.clear()
                visited.add(i)
                mark[i] = 0
                cur = i
                k = 0
                
                while cur!=-1:
                    k+=1
                    nxt = edges[cur]
                    if nxt!=-1:
                        if nxt in mark:
                            ans = max(ans, k-mark[nxt])
                            break
                        if nxt not in visited:
                            visited.add(nxt)
                            mark[nxt] = k
                            cur = nxt
                        else:
                            break
                    else:
                        break
        
        if ans==0:
            return -1
        return ans
                    


if __name__ == '__main__':

    # inputs
    edges = [3,3,4,2,3]

    # solution
    ans = Solution().longestCycle(edges)

    # outputs
    print(ans)

