#include "../Utils/io.cpp"

/* 
给你一个仅由数字（0 - 9）组成的字符串 num 。

请你找出能够使用 num 中数字形成的 最大回文 整数，并以字符串形式返回。该整数不含 前导零 。

注意：

你 无需 使用 num 中的所有数字，但你必须使用 至少 一个数字。
数字可以重新排序。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-palindromic-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/21
class Solution {
public:
    string largestPalindromic(string num) {
        int* cnts = new int[10]();
        for (char& c : num) 
            ++cnts[c-'0'];
        
        string lp = "";
        for (int i=9; i>=0; --i)
            if (cnts[i]>1) {
                for (int j=0; j<cnts[i]/2; ++j)
                    lp += to_string(i);
                cnts[i] %= 2;
            }
        if (lp.length()>0 && lp[0]=='0')
            lp = "";
        
        string cp = "";
        for (int i=9; i>=0; --i)
            if (cnts[i]>0) {
                cp = to_string(i);
                break;
            }
        
        string rp = lp;
        reverse(rp.begin(), rp.end());
        string ans = lp+cp+rp; 
        if (ans=="")
            return "0";
        return ans;
    }
};



int main() {

    // input
    string num = "444947137";

    // solution
    string ans = Solution().largestPalindromic(num);

    // output
    cout<<ans<<endl;

    return 0;
}



