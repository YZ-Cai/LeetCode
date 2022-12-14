#include "../Utils/io.cpp"

/* 
给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。

请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shuffle-the-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/29
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        for (int i=0; i<n; i++) {
            ans[2*i] = nums[i];
            ans[2*i+1] = nums[i+n];
        }
        return ans;
    }
};



int main() {

    // input
    vector<int> nums = readVectorOfInt("[2,5,1,3,4,7]");
    int n = 3;

    // solution
    vector<int> ans = Solution().shuffle(nums, n);

    // output
    printVectorOfInt(ans);

    return 0;
}