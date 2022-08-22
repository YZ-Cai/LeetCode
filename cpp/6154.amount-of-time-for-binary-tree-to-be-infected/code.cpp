#include "../Utils/io.cpp"

/* 
给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start 的节点开始爆发。

每分钟，如果节点满足以下全部条件，就会被感染：

节点此前还没有感染。
节点与一个已感染节点相邻。
返回感染整棵树需要的分钟数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/21
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        s = start;
        search(0, root);
        
        int otherDepth=0;
        for (auto& each : mark) {
            TreeNode* cur = each.first;
            int dist = each.second;
            if (cur->left && mark.find(cur->left)==mark.end()) {
                int d = dist + depth(cur->left);
                otherDepth = otherDepth>d?otherDepth:d;
            }
            if (cur->right && mark.find(cur->right)==mark.end()) {
                int d = dist + depth(cur->right);
                otherDepth = otherDepth>d?otherDepth:d;
            }
            otherDepth = otherDepth>dist?otherDepth:dist;
        }
        return subTreeDepth>otherDepth?subTreeDepth:otherDepth;
    }

private:

    unordered_map<TreeNode*, int> mark;
    int subTreeDepth, otherDepth;
    int s, sd=0;
    
    int search(int cd, TreeNode* cur) {
        int ret = -1;
        if (cur->val==s) {
            sd = cd;
            subTreeDepth = depth(cur)-1;
            mark[cur] = 0;
            return 0;
        } else {
            if (cur->left) {
                int res = search(cd+1, cur->left);
                if (res>=0) {
                    mark[cur] = res+1;
                    ret = res+1;
                }
            }
            if (cur->right) {
                int res = search(cd+1, cur->right);
                if (res>=0) {
                    mark[cur] = res+1;
                    ret = res+1;
                }
            }
        }
        return ret;
    }
    
    int depth(TreeNode* cur) {
        int d = 0;
        if (cur->left) {
            int ld = depth(cur->left);
            d = d>ld?d:ld;
        }
        if (cur->right) {
            int rd = depth(cur->right);
            d = d>rd?d:rd;
        }
        return d+1;
    }
};



int main() {

    // input
    TreeNode* root = convertStringToBinaryTree("[1,5,3,null,4,10,6,9,2]");
    int start = 3;

    // solution
    int ans = Solution().amountOfTime(root, start);

    // output
    cout<<ans<<endl;

    return 0;
}



