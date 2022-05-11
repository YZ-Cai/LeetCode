"""
基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。

给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-genetic-mutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/05/07
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        bank = list( set( bank + [start] ) )
        neighbors = {}
        for each in bank:
            neighbors[each] = []

        for i in range(len(bank)-1):
            for j in range(i+1, len(bank)):
                if self.differenceIsOne(bank[i], bank[j]):
                    neighbors[bank[i]].append( bank[j] )
                    neighbors[bank[j]].append( bank[i] )
        
        frontier = [start]
        visited = set([start])
        for k in range(1,len(bank)):
            nextFrontier = []
            for cur in frontier:
                for neighbor in neighbors[cur]:
                    if neighbor==end:
                        return k
                    if neighbor not in visited:
                        visited.add(neighbor)
                        nextFrontier.append(neighbor)
            frontier = nextFrontier
        return -1


    def differenceIsOne(self, a, b):
        if len(a)==len(b):
            cnt = 0
            for i in range(len(a)):
                if a[i]!=b[i]:
                    cnt += 1
            return cnt==1
        return False



if __name__ == '__main__':

    # inputs
    start = "AACCGGTT"
    end = "AACCGGTA"
    bank = ["AACCGGTA"]

    # solution
    ans = Solution().minMutation(start, end, bank)

    # outputs
    print(ans)

