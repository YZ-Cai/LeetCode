#include "../Utils/io.cpp"

/* 
给定一个整数数组 asteroids，表示在同一行的行星。

对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。

找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/asteroid-collision
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/07/13
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int* lefts = new int[n];
        for (int i=0; i<n; i++)
            lefts[i] = i-1;

        int i=1;
        while (i<n) {
            int cur = asteroids[i];
            int left = lefts[i];
            if (cur<0 && left!=-1 && asteroids[left]>0) {
                if (-cur==asteroids[left]) {
                    if (i+1<n) 
                        lefts[i+1] = lefts[left];
                    asteroids[i] = asteroids[left] = 0;
                    i++;
                } else {
                    if (-cur>asteroids[left]) {
                        asteroids[left] = 0;
                        lefts[i] = lefts[left];
                    } else {
                        if (i+1<n) 
                            lefts[i+1] = left;
                        asteroids[i] = 0;
                        i++;
                    }
                }
            } else
                i++;
        }

        vector<int> ans;
        for (int i=0; i<n; i++)
            if (asteroids[i]!=0)
                ans.push_back(asteroids[i]);
        return ans;
    }
};



int main() {

    // inputs
    string arr = "[5,10,-5, -9, 5, 7, 1, 2, -6]";
    vector<int> vec = readVectorOfInt(arr);

    // solve problem
    vector<int> ans = Solution().asteroidCollision(vec);

    // outputs
    printVectorOfInt(ans);

    return 0;
}



