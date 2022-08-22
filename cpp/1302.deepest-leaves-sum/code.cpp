#include "../Utils/io.cpp"

/* 
给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。
*/


// 2022/08/17
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode*> *frontier = new vector<TreeNode*>;
        vector<TreeNode*> *nxtFrontier = new vector<TreeNode*>;

        frontier->push_back(root);
        while (frontier->empty()==false) {
            nxtFrontier->clear();

            for (TreeNode*& node : *frontier) {
                if (node->left)
                    nxtFrontier->push_back(node->left);
                if (node->right)
                    nxtFrontier->push_back(node->right);
            }

            if (nxtFrontier->empty()) {
                int ans = 0;
                for (TreeNode*& node : *frontier)
                    ans += node->val;
                return ans;
            } else {
                vector<TreeNode*>* tmp = nxtFrontier;
                nxtFrontier = frontier;
                frontier = tmp;
            }
        }
        return 0;
    }
};



int main() {

    // inputs
    string input = "[1,2,3,4,5,null,6,7,null,null,null,null,8]";
    TreeNode* root = convertStringToBinaryTree(input);

    // solve problem
    int ans = Solution().deepestLeavesSum(root);

    // outputs
    cout<<ans<<endl;

    return 0;
}



