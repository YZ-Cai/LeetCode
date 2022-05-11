"""
给你一个整数数组 nums，和一个整数 k 。

在一个操作中，您可以选择 0 <= i < nums.length 的任何索引 i 。将 nums[i] 改为 nums[i] + x ，其中 x 是一个范围为 [-k, k] 的整数。对于每个索引 i ，最多 只能 应用 一次 此操作。

nums 的 分数 是 nums 中最大和最小元素的差值。 

在对  nums 中的每个索引最多应用一次上述操作后，返回 nums 的最低 分数 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-range-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# 2022/05/02
class Solution:
    def isValid(self, code: str) -> bool:
        if len(code)==0 or code[0]!='<':
            return False

        tags = []
        isInCDATA = False
        i = 0

        while i<len(code):
            if isInCDATA:
                if i+3<=len(code) and code[i:i+3]=="]]>":
                    isInCDATA = False
                    i += 3
                else:
                    i += 1
            else:
                if code[i]=='<':
                    if len(tags)>0 and i+9<=len(code) and code[i:i+9]=="<![CDATA[":
                        isInCDATA = True
                        i += 9
                    elif i+1<len(code) and code[i+1]=='/':
                        i += 2
                        start = i
                        while i<len(code) and code[i]!='>':
                            i += 1
                        if i<len(code) and i-start>=1 and i-start<=9 and len(tags)>0 and code[start:i]==tags[-1]:
                            tags.pop()
                            i += 1
                            if len(tags)==0 and i<len(code):
                                return False
                        else:
                            return False
                    else:
                        i += 1
                        start = i
                        while i<len(code) and code[i]!='>':
                            i += 1
                        if i<len(code) and i-start>=1 and i-start<=9 and code[start:i].isalpha() and code[start:i].isupper():
                            tags.append(code[start:i])
                            i += 1
                        else:
                            return False
                else:
                    i += 1

        if len(tags)>0 or isInCDATA:
            return False
        return True



if __name__ == '__main__':

    # inputs
    input = "<A<></A<><B></B>"

    # solution
    ans = Solution().isValid(input)

    # outputs
    print(ans)

