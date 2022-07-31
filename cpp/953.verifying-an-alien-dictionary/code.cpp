#include "../Utils/io.cpp"

/* 
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/verifying-an-alien-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/05/17
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char* mapping = new char[26];
        for (int i=0; i<26; i++)
            mapping[order[i]-'a'] = 'a' + i;
        for (string& word : words)
            for (int i=0; i<word.length(); i++)
                word[i] = mapping[word[i]-'a'];
        for (int i=0; i<words.size()-1; i++)
            if (words[i]>words[i+1])
                return false;
        return true;
    }
};



int main() {

    // inputs
    vector<string> words = {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";

    // solve problem
    bool ans = Solution().isAlienSorted(words, order);

    // outputs
    cout<<ans<<endl;

    return 0;
}



