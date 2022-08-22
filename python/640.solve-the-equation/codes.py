"""
求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。

如果方程没有解，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。

题目保证，如果方程中只有一个解，则 'x' 的值是一个整数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/solve-the-equation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List


# 2022/08/10
class Solution:
    def solveEquation(self, equation: str) -> str:
        left, right = equation.split('=')
        leftX, leftC = self.getVals(left)
        rightX, rightC = self.getVals(right)
        X = leftX-rightX
        C = rightC-leftC
        if X==0 and C==0:
            return "Infinite solutions"
        if X==0:
            return "No solution"
        return "x="+str(C//X)

    def getVals(self, eq):
        ops = ['+']
        for c in eq:
            if c=='+' or c=='-':
                ops.append(c)

        eq = eq.split('+')
        vals = []
        for subeq in eq:
            vals += subeq.split('-')
        
        xCnt = 0
        const = 0
        for i in range(len(vals)):
            if ops[i]=='+':
                if 'x' in vals[i]:
                    xCnt += 1 if vals[i]=='x' else int(vals[i][:-1]);
                elif vals[i]!='':
                    const += int(vals[i])
            else:
                if 'x' in vals[i]:
                    xCnt -= 1 if vals[i]=='x' else int(vals[i][:-1]);
                elif vals[i]!='':
                    const -= int(vals[i])
        return xCnt, const



if __name__ == '__main__':

    # inputs
    equation = "x+5-3+x=6+x-2"

    # solution
    ans = Solution().solveEquation(equation)

    # outputs
    print(ans)

