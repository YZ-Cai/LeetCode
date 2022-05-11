"""
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
"""
from typing import List


# 2022/05/05
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        ans = 0
        start = 0
        end = 0
        cur = 1

        while end<len(nums):
            cur *= nums[end]
            while cur>=k and start<=end:
                cur /= nums[start]
                start += 1
            ans += end - start +1
            end += 1

        return ans


if __name__ == '__main__':

    # inputs
    nums = [1,2,3]
    k = 0

    # solution
    ans = Solution().numSubarrayProductLessThanK(nums, k)

    # outputs
    print(ans)

