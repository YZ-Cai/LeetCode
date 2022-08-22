"""
如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。

给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。
"""
from typing import List


# 2022/08/14
class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        if n<10:
            return n
        ans = 0
        
        for i in range(1, len(str(n))):
            cnt = 9
            for j in range(9, 10-i, -1):
                cnt *= j
            ans += cnt
        ans += self.search(set(), n, True)
        return ans 
        
    
    def search(self, used, val, isBegin=False):
        
        if val<10:
            cnt = 0
            for i in range(1 if isBegin else 0, val+1):
                if i not in used:
                    cnt += 1
            return cnt
        
        cur = int(str(val)[0])
        leftLen = len(str(val)) - 1
        ans = len([i for i in range(1 if isBegin else 0, cur) if i not in used])
        for i in range(9-len(used), 9-len(used)-leftLen, -1):
            ans *= i
        if cur in used:
            return ans
        used.add(cur)
        
        nextVal = int(str(val)[1:])
        if len(str(nextVal))<len(str(val))-2:
            return ans
        if len(str(nextVal))==len(str(val))-2:
            used.add(0)
        return ans + self.search(used, int(str(val)[1:]))
            



if __name__ == '__main__':

    # inputs
    n = 135

    # solution
    ans = Solution().countSpecialNumbers(n)

    # outputs
    print(ans)

