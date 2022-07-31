#include "../Utils/io.cpp"

/* 
给你一个非负整数数组 nums 。在一步操作中，你必须：

选出一个正整数 x ，x 需要小于或等于 nums 中 最小 的 非零 元素。
nums 中的每个正整数都减去 x。
返回使 nums 中所有元素都等于 0 需要的 最少 操作数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/07/31
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = 0;
        int ans = 0;
        
        for (int& val : nums) 
            if (val>cur) {
                ans++;
                cur = val;
            }
        return ans;
    }
};
                    



int main() {

    // inputs
    string input = "[1,5,0,3,5]";
    vector<int> nums = readVectorOfInt(input);
    
    // solve problem
    int ans = Solution().minimumOperations(nums);

    // outputs
    cout<<ans<<endl;

    return 0;
}



