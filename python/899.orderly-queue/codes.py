"""
给定一个字符串 s 和一个整数 k 。你可以从 s 的前 k 个字母中选择一个，并把它加到字符串的末尾。

返回 在应用上述步骤的任意数量的移动后，字典上最小的字符串 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/orderly-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List



# 2022/08/03
from collections import defaultdict
class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        ans = ""
        if k==1:
            ans = s
            for i in range(1, len(s)):
                tmp = s[i:]+s[0:i]
                if tmp<ans:
                    ans = tmp
        else:
            mark = defaultdict(int)
            for c in s:
                mark[c] += 1
            mark = list(mark.items())
            mark = sorted(mark, key=lambda x:x[0])
            for k, v in mark:
                ans += k*v
        return ans


if __name__ == '__main__':

    # inputs
    s = "baaca"
    k = 3

    # solution
    ans = Solution().orderlyQueue(s, k)

    # outputs
    print(ans)

