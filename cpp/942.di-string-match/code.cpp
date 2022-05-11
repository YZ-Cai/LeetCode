#include "../Utils/io.cpp"

/* 
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/di-string-match
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。。
*/


// 2022/05/09
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> ans(n+1);

        int cur = 0;
        int i = 0;
        while (i<n) {
            while (s[i]=='I') {
                ans[i] = cur;
                cur++;
                i++;
            }
            ans[i] = -1;
            i++;
        }
        
        ans[n] = cur;
        cur++;
        i = n-1;
        while (i>=0) {
            if (ans[i]==-1) {
                ans[i] = cur;
                cur++;
            }
            i--;
        }

        return ans;
    }
};



int main() {

    // inputs
    string s = "IID";

    // solve problem
    vector<int> ans = Solution().diStringMatch(s);

    // outputs
    printVectorOfInt(ans);

    return 0;
}



