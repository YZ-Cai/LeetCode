#include "../Utils/io.cpp"

/* 
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用 单个空格 分隔的单词组成。请你检查检索词 searchWord 是否为句子 sentence 中任意单词的前缀。

如果 searchWord 是某一个单词的前缀，则返回句子 sentence 中该单词所对应的下标（下标从 1 开始）。如果 searchWord 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。如果 searchWord 不是任何单词的前缀，则返回 -1 。

字符串 s 的 前缀 是 s 的任何前导连续子字符串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/21
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0, idx = 0, n = sentence.length(), m = searchWord.length();

        do {
            ++idx;
            int j = 0;
            while (i<n && j<m && sentence[i]==searchWord[j]) {
                ++i;
                ++j;
            }
            if (j==m)
                return idx;    

            while (i<n && sentence[i]!=' ') 
                ++i;
            ++i;
            if (i>=n)
                return -1;
        } while (i<n);
        return -1;
    }
};



int main() {

    // inputs
    string sentence = "i love eating burger";
    string searchWord = "burg";

    // solve problem
    int ans = Solution().isPrefixOfWord(sentence, searchWord);

    // outputs
    cout<<ans<<endl;

    return 0;
}



