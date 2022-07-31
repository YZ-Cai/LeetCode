#include "../Utils/io.cpp"

/* 
给你一个整数数组 nums ，该数组具有以下属性：

nums.length == 2 * n.
nums 包含 n + 1 个 不同的 元素
nums 中恰有一个元素重复 n 次
找出并返回重复了 n 次的那个元素。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/n-repeated-element-in-size-2n-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/05/21
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i=0; i<nums.size()/3; i++) {
            int& a = nums[3*i];
            int& b = nums[3*i+1];
            int& c = nums[3*i+2];
            if (a==b)
                return a;
            if (a==c)
                return a;
            if (b==c)
                return b;
        }
        return nums[nums.size()-1];
    }
};



int main() {

    // inputs
    string input = "[5,1,5,2,5,3,5,4]";
    vector<int> nums = readVectorOfInt(input);

    // solve problem
    int ans = Solution().repeatedNTimes(nums);

    // outputs
    cout<<ans<<endl;

    return 0;
}



