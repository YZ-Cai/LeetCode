#include "../Utils/io.cpp"

/* 
给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。

请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。

请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reformat-the-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/11
class Solution {
public:
    string reformat(string s) {
        vector<char> cs, vs;
        for (char& c : s)
            if (c>='a' && c<='z')
                cs.push_back(c);
            else 
                vs.push_back(c);
        
        if (vs.size()==cs.size()+1) {
            char ans[s.size()+1];
            for (int i=0; i<cs.size(); i++) {
                ans[2*i] = vs[i];
                ans[2*i+1] = cs[i];
            }
            ans[s.size()-1] = vs[cs.size()];
            ans[s.size()] = '\0';
            return ans;
        }
        if (cs.size()==vs.size()+1) {
            char ans[s.size()+1];
            for (int i=0; i<vs.size(); i++) {
                ans[2*i] = cs[i];
                ans[2*i+1] = vs[i];
            }
            ans[s.size()-1] = cs[vs.size()];
            ans[s.size()] = '\0';
            return ans;
        }
        if (cs.size()==vs.size()) {
            char ans[s.size()+1];
            for (int i=0; i<vs.size(); i++) {
                ans[2*i] = cs[i];
                ans[2*i+1] = vs[i];
            }
            ans[s.size()] = '\0';
            return ans;
        }
        return "";
    }
};



int main() {

    // inputs
    string s = "0a1b2c";

    // solve problem
    string ans = Solution().reformat(s);

    // outputs
    cout<<ans<<endl;

    return 0;
}



