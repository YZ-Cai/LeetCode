#include "../Utils/io.cpp"

/* 
给你一个整数数组 nums，和一个整数 k 。

在一个操作中，您可以选择 0 <= i < nums.length 的任何索引 i 。将 nums[i] 改为 nums[i] + x ，其中 x 是一个范围为 [-k, k] 的整数。对于每个索引 i ，最多 只能 应用 一次 此操作。

nums 的 分数 是 nums 中最大和最小元素的差值。 

在对  nums 中的每个索引最多应用一次上述操作后，返回 nums 的最低 分数 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-range-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/04/30
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minVal=nums[0], maxVal=nums[0];
        for (int i=1; i<nums.size(); i++) {
            minVal = nums[i]<minVal?nums[i]:minVal;
            maxVal = nums[i]>maxVal?nums[i]:maxVal;
        }
        if (minVal+k<maxVal-k)
            return maxVal-minVal-2*k;
        return 0;
    }
};



int main() {

    // inputs
    int k = 2;
    vector<int> vec = readVectorOfInt("[1,1,1]");

    // solve problem
    int ans = Solution().smallestRangeI(vec, k);

    // outputs
    cout<<ans<<endl;

    return 0;
}



