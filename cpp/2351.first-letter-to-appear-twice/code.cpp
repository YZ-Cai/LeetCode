#include "../Utils/io.cpp"

/* 
给你一个由小写英文字母组成的字符串 s ，请你找出并返回第一个出现 两次 的字母。

注意：

如果 a 的 第二次 出现比 b 的 第二次 出现在字符串中的位置更靠前，则认为字母 a 在字母 b 之前出现两次。
s 包含至少一个出现两次的字母。
*/


// 2022/07/30
class Solution {
public:
    char repeatedCharacter(string s) {
        char* mark = new char[256]();
        for (char c : s)
            if (mark[c]==1)
                return c;
            else
                mark[c] = 1;
        return 'a';
    }
};



int main() {

    // inputs
    string s = "abccbaacz";

    // solve problem
    char ans = Solution().repeatedCharacter(s);

    // outputs
    cout<<ans<<endl;

    return 0;
}



