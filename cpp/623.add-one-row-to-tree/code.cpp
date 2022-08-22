#include "../Utils/io.cpp"

/* 
给定一个二叉树的根 root 和两个整数 val 和 depth ，在给定的深度 depth 处添加一个值为 val 的节点行。

注意，根节点 root 位于深度 1 。

加法规则如下:

给定整数 depth，对于深度为 depth - 1 的每个非空树节点 cur ，创建两个值为 val 的树节点作为 cur 的左子树根和右子树根。
cur 原来的左子树应该是新的左子树根的左子树。
cur 原来的右子树应该是新的右子树根的右子树。
如果 depth == 1 意味着 depth - 1 根本没有深度，那么创建一个树节点，值 val 作为整个原始树的新根，而原始树就是新根的左子树。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-one-row-to-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/05
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1) {
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        while (q.empty()==false) {
            pair<TreeNode*, int> curPair = q.front();
            q.pop();

            TreeNode* cur = curPair.first;
            int k = curPair.second;
            if (k<depth-1) {
                if (cur->left)
                    q.push(make_pair(cur->left, k+1));
                if (cur->right)
                    q.push(make_pair(cur->right, k+1));
            } else if (k==depth-1) {
                cur->left = new TreeNode(val, cur->left, nullptr);
                cur->right = new TreeNode(val, nullptr, cur->right);
            } else 
                break;
        }
        return root;
    }
};



int main() {

    // inputs
    string tree = "[4,2,6,3,1,5]";
    TreeNode* root = convertStringToBinaryTree(tree);
    int val = 1;
    int depth = 2;

    // solve problem
    TreeNode* ans = Solution().addOneRow(root, val, depth);

    // outputs
    cout<<convertBinaryTreeToString(ans)<<endl;

    return 0;
}



