#include "../Utils/io.cpp"

/* 
给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。

「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-score-after-splitting-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



// 2022/08/14
class Solution {
public:
    int maxScore(string s) {
        int n0 = 0;
        for (char &c : s)
            if (c=='0')
                n0++;
        int n1 = s.size() - n0;

        int cur1 = 0;
        int ans = 0;
        const int n = s.size();
        for (int i=0; i<n-1; i++) {
            if (s[i]=='1')
                cur1++;
            int score = (i+1-cur1) + (n1-cur1);
            ans = ans>score?ans:score;
        }
        return ans;
    }
};



int main() {

    // inputs
    string s = "011101";

    // solve problem
    int ans = Solution().maxScore(s);

    // outputs
    cout<<ans<<endl;

    return 0;
}



