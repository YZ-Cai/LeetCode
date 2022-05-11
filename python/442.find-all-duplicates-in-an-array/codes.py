"""
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/05/08
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:

        for i in range(len(nums)):
            while nums[nums[i]-1] != nums[i]:
                val = nums[i]
                nums[i] = nums[val-1]
                nums[val-1] = val

        ans = []
        for i in range(len(nums)):
            if nums[i]!=i+1:
                ans.append(nums[i])
        return ans
        
        

if __name__ == '__main__':

    # inputs
    nums = [4,3,2,7,8,2,3,1]

    # solution
    ans = Solution().findDuplicates(nums)

    # outputs
    print(ans)

