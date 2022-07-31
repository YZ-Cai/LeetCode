#include "../Utils/io.cpp"

/* 
给定一个由不同正整数的组成的非空数组 nums ，考虑下面的图：

有 nums.length 个节点，按从 nums[0] 到 nums[nums.length - 1] 标记；
只有当 nums[i] 和 nums[j] 共用一个大于 1 的公因数时，nums[i] 和 nums[j]之间才有一条边。
返回 图中最大连通组件的大小 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-component-size-by-common-factor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/07/30
#include <unordered_map>
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        for (int& val : nums) {
            if (parents.find(val)==parents.end()) 
                parents[val] = val;
            for (int i=2; i*i<=val; i++)
                if (val%i==0) {
                    mergeSet(val, i);
                    mergeSet(val, val/i);
                }                
        }
        
        unordered_map<int, int> counts;
        int ans = 1;
        for (int val : nums) {
            while (parents[val]!=val)
                val = parents[val];
            if (counts.find(val)==counts.end())
                counts[val] = 1;
            else {
                counts[val]++;
                ans = ans>counts[val]?ans:counts[val];
            }
        }

        for (pair<int,int> each : parents)
            cout<<each.first<<" "<<each.second<<endl;

        return ans;
    }

private:
    unordered_map<int, int> parents;
    void mergeSet(int a,  int b) {
        if (parents.find(b)==parents.end())
            parents[b] = b;
        while (parents[a]!=a)
            a = parents[a];
        while (parents[b]!=b)
            b = parents[b];
        if (a<b) 
            parents[b] = a;
        if (a>b)
            parents[a] = b;
    }
};



int main() {

    // inputs
    string input = "[6548,73417,17285,88729]";
    vector<int> nums = readVectorOfInt(input);

    // solve problem
    int ans = Solution().largestComponentSize(nums);

    // outputs
    cout<<ans<<endl;

    return 0;
}



