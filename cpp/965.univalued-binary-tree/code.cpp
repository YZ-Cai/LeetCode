#include "../Utils/io.cpp"

/* 
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。
*/


// 2022/05/25
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);
        int val = root->val;

        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            while (cur->left) {
                TreeNode* tmp = cur;
                cur = cur->left;
                tmp->left = nullptr;
                stk.push(cur);
            }

            if (cur->val != val)
                return false;
            stk.pop();
            if (cur->right)
                stk.push(cur->right);
        }

        return true;
    }
};



int main() {

    // inputs
    string tree = "[1,1,1,1,1,null,1]";
    TreeNode* root = convertStringToBinaryTree(tree);

    // solve problem
    bool ans = Solution().isUnivalTree(root);

    // outputs
    cout<<ans<<endl;

    return 0;
}



