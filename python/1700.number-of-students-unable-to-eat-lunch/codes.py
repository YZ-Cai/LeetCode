"""
学校的自助午餐提供圆形和方形的三明治，分别用数字 0 和 1 表示。所有学生站在一个队列里，每个学生要么喜欢圆形的要么喜欢方形的。
餐厅里三明治的数量与学生的数量相同。所有三明治都放在一个 栈 里，每一轮：

如果队列最前面的学生 喜欢 栈顶的三明治，那么会 拿走它 并离开队列。
否则，这名学生会 放弃这个三明治 并回到队列的尾部。
这个过程会一直持续到队列里所有学生都不喜欢栈顶的三明治为止。

给你两个整数数组 students 和 sandwiches ，其中 sandwiches[i] 是栈里面第 i​​​​​​ 个三明治的类型（i = 0 是栈的顶部）， students[j] 是初始队列里第 j​​​​​​ 名学生对三明治的喜好（j = 0 是队列的最开始位置）。请你返回无法吃午餐的学生数量。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/10/19
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        n = len(students)

        if sum(students)>sum(sandwiches):
            cnt = 0
            i = n-1
            while i>=0 and cnt<sum(students)-sum(sandwiches):
                if sandwiches[i]==0:
                    cnt += 1
                i -= 1
            return n-1-i 

        if sum(students)<sum(sandwiches):
            cnt = 0
            i = n-1
            while i>=0 and cnt<sum(sandwiches)-sum(students):
                if sandwiches[i]==1:
                    cnt += 1
                i -= 1
            return n-1-i 

        return 0
        



if __name__ == '__main__':

    # inputs
    students = [0,0,0,1,1,1,1,1,0,0,1,1,1,0,0,1,0,0,0,1,0]
    sandwiches = [0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0]

    # solution
    ans = Solution().countStudents(students, sandwiches)

    # outputs
    print(ans)
