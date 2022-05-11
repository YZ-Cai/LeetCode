"""
一只猫和一只老鼠在玩一个叫做猫和老鼠的游戏。

它们所处的环境设定是一个 rows x cols 的方格 grid ，其中每个格子可能是一堵墙、一块地板、一位玩家（猫或者老鼠）或者食物。

玩家由字符 'C' （代表猫）和 'M' （代表老鼠）表示。
地板由字符 '.' 表示，玩家可以通过这个格子。
墙用字符 '#' 表示，玩家不能通过这个格子。
食物用字符 'F' 表示，玩家可以通过这个格子。
字符 'C' ， 'M' 和 'F' 在 grid 中都只会出现一次。
猫和老鼠按照如下规则移动：

老鼠 先移动 ，然后两名玩家轮流移动。
每一次操作时，猫和老鼠可以跳到上下左右四个方向之一的格子，他们不能跳过墙也不能跳出 grid 。
catJump 和 mouseJump 是猫和老鼠分别跳一次能到达的最远距离，它们也可以跳小于最大距离的长度。
它们可以停留在原地。
老鼠可以跳跃过猫的位置。
游戏有 4 种方式会结束：

如果猫跟老鼠处在相同的位置，那么猫获胜。
如果猫先到达食物，那么猫获胜。
如果老鼠先到达食物，那么老鼠获胜。
如果老鼠不能在 1000 次操作以内到达食物，那么猫获胜。
给你 rows x cols 的矩阵 grid 和两个整数 catJump 和 mouseJump ，双方都采取最优策略，如果老鼠获胜，那么请你返回 true ，否则返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/cat-and-mouse-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from typing import List
from queue import Queue


# 2022/05/07
class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        self.grid = grid
        self.catJump = catJump
        self.mouseJump = mouseJump
        self.states = {}
        self.q = Queue()

        for a in range(len(grid)):
            for b in range(len(grid[0])):
                for c in range(len(grid)):
                    for d in range(len(grid[0])):
                        if grid[a][b]!='#' and grid[c][d]!='#':
                            if a==c and b==d:
                                self.initState('M', (a,b), (c,d), False, 0)
                                self.initState('C', (a,b), (c,d), False, 0)
                            else:
                                if grid[a][b]=='F':
                                    self.initState('M', (a,b), (c,d), False, 0)
                                    self.initState('C', (a,b), (c,d), False, 0)
                                if grid[c][d]=='F':
                                    self.initState('M', (a,b), (c,d), True, 0)
                                    self.initState('C', (a,b), (c,d), True, 0)
                if grid[a][b]=='C':
                    self.catInitPosition = (a,b)
                if grid[a][b]=='M':
                    self.mouseInitPosition = (a,b)

        while self.q.empty()==False and self.getAnswer()[0]==None:
            agent, a, b, c, d = self.q.get()
            status, _, step = self.states[(agent, a, b, c, d)]
            if agent=='M':
                for x, y in self.getNextPositions((a,b), self.catJump):
                    self.updateState(('C', x, y, c, d), status, step+1)
            else:
                for x, y in self.getNextPositions((c,d), self.mouseJump):
                    self.updateState(('M', a, b, x, y), status, step)
         
        ans = self.getAnswer()
        if ans[0]==None or (ans[0]==True and ans[2]>1000):
            return False       
        return ans[0]


    def initState(self, agent, catPosition, mousePosition, status, step):
        a, b = catPosition
        c, d = mousePosition 
        if status==None:
            if agent=='C':
                self.states[("C", a, b, c, d)] = [status, len(self.getNextPositions((a,b), self.catJump)), step]
            else:
                self.states[("M", a, b, c, d)] = [status, len(self.getNextPositions((c,d), self.mouseJump)), step]
        else:
            self.states[(agent, a, b, c, d)] = [status, None, step]
            self.q.put((agent, a, b, c, d))


    def getNextPositions(self, position, jump):
        x, y = position
        nextPositions = [position]
        i = x-1
        while x-i<=jump and i>=0 and self.grid[i][y]!='#':
            nextPositions.append((i,y))
            i -= 1
        i = x+1
        while i-x<=jump and i<len(self.grid) and self.grid[i][y]!='#':
            nextPositions.append((i,y))
            i += 1
        j = y-1
        while y-j<=jump and j>=0 and self.grid[x][j]!='#':
            nextPositions.append((x,j))
            j -= 1
        j = y+1
        while j-y<=jump and j<len(self.grid[0]) and self.grid[x][j]!='#':
            nextPositions.append((x,j))
            j += 1
        return nextPositions


    def getAnswer(self):
        a, b = self.catInitPosition
        c, d = self.mouseInitPosition
        if ("M", a, b, c, d) not in self.states:
            return [None, None, 10000]
        return self.states[("M", a, b, c, d)]


    def updateState(self, state, nextStatus, step):
        agent, a, b, c, d = state
        if state not in self.states:
            self.initState(agent, (a,b), (c,d), None, step)
        else:
            if self.states[state][0]!=None:
                return
        if agent=='C':
            if nextStatus==False:
                self.states[state] = [False, None, step]
                self.q.put(state)
            else:
                self.states[state][1] -= 1
                self.states[state][2] = max(step, self.states[state][2])
                if self.states[state][1]==0:
                    self.states[state] = (True, None, self.states[state][2])
                    self.q.put(state)
        if agent=='M':
            if nextStatus==True:
                self.states[state] = [True, None, step]
                self.q.put(state)
            else:
                self.states[state][1] -= 1
                self.states[state][2] = min(step, self.states[state][2])
                if self.states[state][1]==0:
                    self.states[state] = (False, None, self.states[state][2])
                    self.q.put(state)



if __name__ == '__main__':

    # inputs
    grid = ["..#C","...#","..M.","#F..","...."]
    catJump = 2
    mouseJump = 1

    # solution
    ans = Solution().canMouseWin(grid, catJump, mouseJump)

    # outputs
    print(ans)

