"""
你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/fruit-into-baskets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/10/17
class Solution:
    mark = {}
    ans = 0
    def update(self):
        tmp = 0
        for k in self.mark:
            tmp += self.mark[k]
        self.ans = max(self.ans, tmp)

    def totalFruit(self, fruits: List[int]) -> int:
        self.mark.clear()
        self.ans = 0
        n = len(fruits)
        i = 0
        j = 0
        while j<n:
            if fruits[j] not in self.mark:
                if len(self.mark)==2:  
                    self.update()  
                    while len(self.mark)==2:       
                        self.mark[fruits[i]] -= 1
                        if self.mark[fruits[i]]==0:
                            self.mark.pop(fruits[i])
                        i += 1
                self.mark[fruits[j]] = 1
            else:
                self.mark[fruits[j]] += 1
            j += 1 

        self.update()
        return self.ans



if __name__ == '__main__':

    # inputs
    fruits = [3,3,3,1,2,1,1,2,3,3,4]

    # solution
    ans = Solution().totalFruit(fruits)

    # outputs
    print(ans)

