#include "../Utils/io.cpp"

/* 
给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩阵需要遵循以下规则：

树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
矩阵的列数 n 应该等于 2height+1 - 1 。
根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2height-r-1] ，右子节点放置在 res[r+1][c+2height-r-1] 。
继续这一过程，直到树中的所有节点都妥善放置。
任意空单元格都应该包含空字符串 "" 。
返回构造得到的矩阵 res 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/print-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/22
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {

        vector<pair<TreeNode*, int>> frontier, nxtFrontier;
        frontier.push_back({root,0});
        int h = 0;
        while (!frontier.empty()) {
            nxtFrontier.clear();
            for (auto& node : frontier) {
                if (node.first->left)
                    nxtFrontier.push_back({node.first->left,0});
                if (node.first->right)
                    nxtFrontier.push_back({node.first->right,0});
            }
            if (!nxtFrontier.empty()) 
                ++h;
            frontier.swap(nxtFrontier);
        }

        vector<vector<string>> ans;
        int n = pow(2, h+1) - 1;
        for (int i=0; i<h+1; ++i) 
            ans.emplace_back(n);

        int r=0;
        frontier.clear();
        frontier.push_back({root, (n-1)/2});
        while (!frontier.empty()) {
            nxtFrontier.clear();
            for (auto& node : frontier) {
                int& c = node.second;
                ans[r][c] = to_string(node.first->val);
                if (node.first->left)
                    nxtFrontier.push_back({node.first->left, c-pow(2,h-r-1)});
                if (node.first->right)
                    nxtFrontier.push_back({node.first->right, c+pow(2,h-r-1)});
            }
            nxtFrontier.swap(frontier);
            ++r;
        }
        return ans;
    }
};



int main() {

    // input
    string input = "[1,2,3,null,4]";
    TreeNode* root = convertStringToBinaryTree(input);

    // solution
    vector<vector<string>> ans = Solution().printTree(root);

    // output
    printMatrixOfString(ans);

    return 0;
}



