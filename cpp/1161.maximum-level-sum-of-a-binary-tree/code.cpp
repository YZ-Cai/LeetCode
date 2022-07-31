#include "../Utils/io.cpp"

/* 
给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。

请返回层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/07/31
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*>* frontier = new vector<TreeNode*>;
        vector<TreeNode*>* nextFrontier = new vector<TreeNode*>;
        int k = 1, ans = 1;
        int maxSum = root->val;

        frontier->push_back(root);
        while (frontier->empty()==false) {
            nextFrontier->clear();
            int sum = 0;
            k++;

            for (TreeNode* u : *frontier) {
                if (u->left) {
                    nextFrontier->push_back(u->left);
                    sum += u->left->val;
                }
                if (u->right) {
                    nextFrontier->push_back(u->right);
                    sum += u->right->val;
                }
            }

            if (sum>maxSum && nextFrontier->empty()==false) {
                maxSum = sum;
                ans = k;
            }
            
            vector<TreeNode*>* tmp = frontier;
            frontier = nextFrontier;
            nextFrontier = tmp;
        }

        return ans;
    }
};



int main() {

    // inputs
    string input = "[1,0,0,7,8,null,null]";
    TreeNode* root = convertStringToBinaryTree(input);

    // solve problem
    int ans = Solution().maxLevelSum(root);

    // outputs
    cout<<ans<<endl;

    return 0;
}



