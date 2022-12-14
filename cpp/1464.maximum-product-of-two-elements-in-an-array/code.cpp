#include "../Utils/io.cpp"

/* 
给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。

请你计算并返回该式的最大值。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/26
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a, b;
        if (nums[0]>nums[1]) {
            a = nums[0];
            b = nums[1];
        } else {
            a = nums[1];
            b = nums[0];
        }
        
        for (int i=2; i<nums.size(); i++) {
            int& val = nums[i];
            if (val>a) {
                b = a;
                a = val;
            } else if (val>b)
                b = val;
        }
        return (a-1)*(b-1);
    }
};



int main() {

    // input
    vector<int> nums = readVectorOfInt("[1,2,3,4,5]");

    // solution
    int ans = Solution().maxProduct(nums);

    // output
    cout<<ans<<endl;

    return 0;
}