"""
在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和 达到或超过  100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家 不能 重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定两个整数 maxChoosableInteger （整数池中可选择的最大数）和 desiredTotal（累计和），若先出手的玩家是否能稳赢则返回 true ，否则返回 false 。假设两位玩家游戏时都表现 最佳 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/can-i-win
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# 2022/05/22
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if (1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal:
            return False

        self.n = maxChoosableInteger
        self.bound = desiredTotal
        self.mark = {}
        return self.search(0, 0, True)

    def search(self, val, used, isMe):
        if val>=self.bound:
            return isMe
        if used in self.mark:
            return self.mark[used]
        for i in range(self.n-1, -1, -1):
            if (used>>i)&1 == 0:
                newUsed = used | (1<<i)
                newVal = val+i+1
                if newVal>=self.bound:
                    return isMe
                next = self.search(newVal, newUsed, not isMe)
                if isMe==next:
                    self.mark[used] = next
                    return next
        return not isMe



if __name__ == '__main__':

    # inputs
    maxChoosableInteger = 20
    desiredTotal = 152

    # solution
    ans = Solution().canIWin(maxChoosableInteger, desiredTotal)

    # outputs
    print(ans)

