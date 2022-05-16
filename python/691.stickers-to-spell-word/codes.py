"""
我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。

您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们。如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。

返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。

注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的，并且 target 被选择为两个随机单词的连接。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/stickers-to-spell-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/05/07
from collections import defaultdict
class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        stickerChars = set()
        for each in stickers:
            for c in each:
                stickerChars.add(c)

        self.targetChars = {}
        id = 0
        curStr = []
        for c in target:
            if c not in stickerChars:
                return -1
            if c not in self.targetChars:
                self.targetChars[c] = id
                id += 1
                curStr.append(1)
            else:
                curStr[self.targetChars[c]] += 1

        self.stickers = []
        for each in stickers:
            cnts = defaultdict(int)
            for c in each:
                if c in self.targetChars:
                    cnts[c] += 1
            self.stickers.append(cnts)

        self.marks = {}
        return self.search(tuple(curStr))


    def search(self, curStr):
        sumOfCurStr = sum(curStr)
        if sumOfCurStr==0:
            return 0
        if curStr in self.marks:
            return self.marks[curStr]
        ans = 256
        for eachCnts in self.stickers:
            nextStr = list(curStr)
            for c in eachCnts:
                nextStr[self.targetChars[c]] = max(0, nextStr[self.targetChars[c]]-eachCnts[c])
            if sum(nextStr)<sumOfCurStr:
                ans = min(ans, self.search(tuple(nextStr))+1)
        self.marks[curStr] = ans
        return ans
            


if __name__ == '__main__':

    # inputs
    stickers = ["with","example","science"]
    target = "thehat"

    # solution
    ans = Solution().minStickers(stickers, target)

    # outputs
    print(ans)

