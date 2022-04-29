#include "../Utils/utils.cpp"

/* 
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/02/15
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int* rowMin = new int[m];
        int* colMax = new int[n];

        for (int i=0; i<m; i++)
            rowMin[i] = matrix[i][0];
        for (int j=0; j<n; j++)
            colMax[j] = matrix[0][j];

        for (int i=0; i<m; i++) 
            for (int j=0; j<n; j++) {
                rowMin[i] = matrix[i][j]<rowMin[i]?matrix[i][j]:rowMin[i];
                colMax[j] = matrix[i][j]>colMax[j]?matrix[i][j]:colMax[j];
            }

        vector<int> ans;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (matrix[i][j]==rowMin[i] && matrix[i][j]==colMax[j])
                    ans.push_back(matrix[i][j]);
        return ans;
    }
};



int main() {

    // inputs
    string input = "[[3,7,8],[9,11,13],[15,16,17]]";
    vector<vector<int>> matrix = readMatrixOfInt(input);

    // solve problem
    vector<int> ans = Solution().luckyNumbers(matrix);

    // outputs
    printVectorOfInt(ans);

    return 0;
}



