#include "../Utils/io.cpp"

/* 
给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。

你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。

请你在确保累加和始终大于等于 1 的前提下，选出一个最小的 正数 作为 startValue 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/09
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = nums[0];
        int cur = nums[0];
        for (int i=1; i<nums.size(); i++) {
            cur += nums[i];
            if (cur<minVal)
                minVal = cur;
        }
        if (minVal>=1)
            return 1;
        return 1-minVal;
    }
};



int main() {

    // inputs
    string input = "[-3,2,-3,4,2]";
    vector<int> nums = readVectorOfInt(input);

    // solve problem
    int ans = Solution().minStartValue(nums);

    // outputs
    cout<<ans<<endl;

    return 0;
}



