#include "../Utils/io.cpp"

/* 
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/20
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for (int& num : nums) {
            TreeNode* x = new TreeNode(num);
            while (stk.empty()==false && num>(stk.top()->val)) {
                x->left = stk.top();
                stk.pop();
            }
            if (stk.empty()==false && num<(stk.top()->val))
                stk.top()->right = x;
            stk.push(x);
        }
        
        TreeNode* ans;
        while (stk.empty()==false) {
            ans = stk.top();
            stk.pop();
        }
        return ans;
    }
};



int main() {

    // inputs
    string input = "[3,2,1,6,0,5]";
    vector<int> nums = readVectorOfInt(input);

    // solve problem
    TreeNode* ans = Solution().constructMaximumBinaryTree(nums);

    // outputs
    cout<<convertBinaryTreeToString(ans)<<endl;

    return 0;
}



