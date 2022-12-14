"""
给定一组 n 人（编号为 1, 2, ..., n）， 我们想把每个人分进任意大小的两组。每个人都可能不喜欢其他人，那么他们不应该属于同一组。

给定整数 n 和数组 dislikes ，其中 dislikes[i] = [ai, bi] ，表示不允许将编号为 ai 和  bi的人归入同一组。当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/possible-bipartition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/10/16
import queue
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        ans = [0]*n
        adj = [[] for i in range(n)]
        for a, b in dislikes:
            adj[a-1].append(b-1)
            adj[b-1].append(a-1)

        q = queue.Queue()
        for i in range(n):
            if ans[i]==0:
                q.put(i)
                ans[i] = 1
                while not q.empty():
                    cur = q.get()
                    for nxt in adj[cur]:
                        if ans[nxt]==0:
                            ans[nxt] = ans[cur]+1
                            q.put(nxt)
                        else:
                            if ans[nxt]%2==ans[cur]%2:
                                return False
        return True



if __name__ == '__main__':

    # inputs
    n = 4
    dislikes =  [[1,2],[1,3],[2,4]]

    # solution
    ans = Solution().possibleBipartition(n, dislikes)

    # outputs
    print(ans)

