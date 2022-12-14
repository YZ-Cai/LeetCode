#include "../Utils/io.cpp"

/* 
给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/validate-stack-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/31
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size(), p=0;
        for (int i=0; i<n; ++i) {
            if (stk.empty())
                stk.push(pushed[p++]);
            while (stk.top()!=popped[i] && p<n) 
                stk.push(pushed[p++]);
            if (stk.top()==popped[i])
                stk.pop();
            else
                return false;
        }
        return true;
    }
};



int main() {

    // input
    vector<int> pushed = readVectorOfInt("[1,2,3,4,5]");
    vector<int> popped = readVectorOfInt("[4,5,3,2,1]");

    // solution
    bool ans = Solution().validateStackSequences(pushed, popped);

    // output
    cout<<ans<<endl;

    return 0;
}