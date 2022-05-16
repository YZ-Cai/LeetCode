#include "../Utils/io.cpp"

/* 
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。
*/


// 2022/05/16
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root==NULL)
            return NULL;
        int target = p->val;
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            while (cur->left) {
                TreeNode* tmp = cur;
                cur = cur->left;
                tmp->left = NULL;
                stk.push(cur);
            }
            stk.pop();
            if (cur->right)
                stk.push(cur->right);
            if (cur->val == target) 
                break;
        }
        
        if (stk.empty())
            return NULL;
        TreeNode* cur = stk.top();
        while (cur->left)
            cur = cur->left;
        return cur;
    }
};



int main() {

    // inputs
    string tree = "[2,1,3]";
    int p = 1;
    TreeNode* root = convertStringToBinaryTree(tree);
    TreeNode* pNode = new TreeNode(p);

    // solve problem
    TreeNode* ans = Solution().inorderSuccessor(root, pNode);

    // outputs
    printTreeNodeValue(ans);

    return 0;
}



