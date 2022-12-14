"""
给定一个按 非递减顺序 排列的数字数组 digits 。你可以用任意次数 digits[i] 来写的数字。例如，如果 digits = ['1','3','5']，我们可以写数字，如 '13', '551', 和 '1351315'。

返回 可以生成的小于或等于给定整数 n 的正整数的个数 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/numbers-at-most-n-given-digit-set
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/10/18
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        cnt = 0
        k = len(str(n))
        for each in digits:
            if int(each)<=n:
                cnt += 1
        for i in range(2,k):
            cnt += len(digits)**i
        if k>1:
            cnt += self.cal(digits, n)
        return cnt

    def cal(self, digits, n):
        cnt = 0
        k = len(str(n))-1
        if k==0:
            for each in digits:
                if int(each)<=n:
                    cnt += 1
        else:
            for i in range(len(digits)):
                if int(digits[i])< n//(10**k):
                    cnt += len(digits)**k
                elif int(digits[i])==n//(10**k) and str(n)[1:]==str(int(str(n)[1:])):
                    cnt += self.cal(digits, int(str(n)[1:]))
        return cnt



if __name__ == '__main__':

    # inputs
    digits = ["1","3","5","7"]
    n = 100

    # solution
    ans = Solution().atMostNGivenDigitSet(digits, n)

    # outputs
    print(ans)

