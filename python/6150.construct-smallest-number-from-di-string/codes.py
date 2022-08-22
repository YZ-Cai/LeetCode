"""
给你下标从 0 开始、长度为 n 的字符串 pattern ，它包含两种字符，'I' 表示 上升 ，'D' 表示 下降 。

你需要构造一个下标从 0 开始长度为 n + 1 的字符串，且它要满足以下条件：

num 包含数字 '1' 到 '9' ，其中每个数字 至多 使用一次。
如果 pattern[i] == 'I' ，那么 num[i] < num[i + 1] 。
如果 pattern[i] == 'D' ，那么 num[i] > num[i + 1] 。
请你返回满足上述条件字典序 最小 的字符串 num。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/construct-smallest-number-from-di-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/08/14
class Solution:
    def smallestNumber(self, pattern: str) -> str:
        n = len(pattern)
        ans = [''] * (n+1)
        cur = 1
        i = 0
        while i<n:
            if pattern[i]=='I':
                ans[i] = str(cur)
                cur += 1
                i += 1
            else:
                j = i+1
                while j<n and pattern[j]=='D':
                    j += 1
                for k in range(j, i-1, -1):
                    ans[k] = str(cur)
                    cur += 1
                i = j+1
        if ans[-1]=='':
            ans[-1] = str(cur)
        return ''.join(ans)
            


if __name__ == '__main__':

    # inputs
    pattern = "IIIDIDDD"

    # solution
    ans = Solution().smallestNumber(pattern)

    # outputs
    print(ans)

