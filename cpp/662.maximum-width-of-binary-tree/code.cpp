#include "../Utils/io.cpp"

/* 
给你一棵二叉树的根节点 root ，返回树的 最大宽度 。

树的 最大宽度 是所有层中最大的 宽度 。

每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 null 节点，这些 null 节点也计入长度。

题目数据保证答案将会在  32 位 带符号整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-width-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/27
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        travel(root, 0, 0);
        return ans;
    }
private:
    vector<unsigned long long> leftMost;
    int ans = 1;
    void travel(TreeNode* cur, int depth, unsigned long long pos) {
        if (leftMost.size()<=depth)
            leftMost.emplace_back(pos);
        else
            ans = ans>(pos-leftMost[depth]+1)?ans:(pos-leftMost[depth]+1);
        if (cur->left)
            travel(cur->left, depth+1, pos*2);
        if (cur->right)
            travel(cur->right, depth+1, pos*2+1); 
    }
};



int main() {

    // input
    TreeNode* root = convertStringToBinaryTree("[1,3,2,5,null,null,9,6,null,7]");

    // solution
    int ans = Solution().widthOfBinaryTree(root);

    // output
    cout<<ans<<endl;

    return 0;
}