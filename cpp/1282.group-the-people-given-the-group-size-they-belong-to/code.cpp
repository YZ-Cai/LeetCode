#include "../Utils/io.cpp"

/* 
给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。

请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。

请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reformat-the-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/12
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> *groups = new vector<int>[n];
        for (int i=0; i<n; i++)
            groups[groupSizes[i]-1].push_back(i);

        vector<vector<int>> ans;
        for (int i=0; i<n; i++)
            for (int j=0; j<groups[i].size()/(i+1); j++) {
                vector<int> cur(i+1);
                for (int k=0; k<i+1; k++)
                    cur[k] = groups[i][j*(i+1)+k];
                ans.push_back(cur);
            }
        return ans;
    }
};



int main() {

    // inputs
    string input = "[3,3,3,3,3,1,3]";
    vector<int> groupSizes = readVectorOfInt(input);

    // solve problem
    vector<vector<int>> ans = Solution().groupThePeople(groupSizes);

    // outputs
    printMatrixOfInt(ans);

    return 0;
}



