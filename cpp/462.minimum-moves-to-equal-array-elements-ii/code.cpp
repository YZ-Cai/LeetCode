#include "../Utils/io.cpp"

/* 
给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最少移动数。

在一步操作中，你可以使数组中的一个元素加 1 或者减 1 
*/


// 2022/05/19
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size()/2];
        
        int ans = 0;
        for (int& each : nums)
            ans += (each-mid)>0?(each-mid):(mid-each);
        return ans;
    }
};



int main() {

    // inputs
    string input = "[1,2,3]";
    vector<int> nums = readVectorOfInt(input);

    // solve problem
    int ans = Solution().minMoves2(nums);

    // outputs
    cout<<ans<<endl;

    return 0;
}



