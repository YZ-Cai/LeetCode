#include "../Utils/io.cpp"

/* 
给你一个 2 行 n 列的二进制数组：

矩阵是一个二进制矩阵，这意味着矩阵中的每个元素不是 0 就是 1。
第 0 行的元素之和为 upper。
第 1 行的元素之和为 lower。
第 i 列（从 0 开始编号）的元素之和为 colsum[i]，colsum 是一个长度为 n 的整数数组。
你需要利用 upper，lower 和 colsum 来重构这个矩阵，并以二维整数数组的形式返回它。

如果有多个不同的答案，那么任意一个都可以通过本题。

如果不存在符合要求的答案，就请返回一个空的二维数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-a-2-row-binary-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/04/29
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans;

        int col0=0, col2=0;
        for (int col:colsum) {
            if (col>2)
                return ans;
            if (col==2)
                col2++;
            if (col==0)
                col0++;
        }

        int n = colsum.size();
        if (upper-col2+lower-col2==n-col2-col0 && upper>=col2 && lower>=col2) {
            ans.push_back({});
            ans.push_back({});
            for (int i=0; i<n; i++) {
                ans[0].push_back(0);
                ans[1].push_back(0);
            }
            upper -= col2;
            lower -= col2;

            for (int i=0; i<n; i++) {
                if (colsum[i]==2)
                    ans[0][i] = ans[1][i] = 1;
                if (colsum[i]==1) {
                    if (upper>0) {
                        ans[0][i] = 1;
                        upper--;
                    } else {
                        ans[1][i] = 1;
                        lower--;
                    }
                }
            }
        } 
        
        return ans;         
    }
};



int main() {

    // inputs
    int upper = 2;
    int lower = 1;
    vector<int> vec = readVectorOfInt("[1,1,1]");

    // solve problem
    vector<vector<int>> ans = Solution().reconstructMatrix(upper, lower, vec);

    // outputs
    printMatrixOfInt(ans);

    return 0;
}



