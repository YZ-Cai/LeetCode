#include "../Utils/io.cpp"

/* 
给你一个整数数组 nums 和一个 正 整数 k 。你可以选择数组的任一 子序列 并且对其全部元素求和。

数组的 第 k 大和 定义为：可以获得的第 k 个 最大 子序列和（子序列和允许出现重复）

返回数组的 第 k 大和 。

子序列是一个可以由其他数组删除某些或不删除元素排生而来的数组，且派生过程不改变剩余元素的顺序。

注意：空子序列的和视作 0 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-k-sum-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/21
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long pSum = 0;
        for (int& num : nums) 
            if (num<0) 
                num = -num;
            else
                pSum += num;

        sort(nums.begin(), nums.end());
        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, -1});

        for (int i=0; i<k-1; ++i) {
            pii cur = pq.top();
            long long& val = cur.first;
            int& idx = cur.second;
            pq.pop();
            
            if (idx+1<nums.size()) {
                pq.push({val+nums[idx+1], idx+1});
                if (idx>=0)
                    pq.push({val+nums[idx+1]-nums[idx], idx+1});
            }
        }

        long long val = pq.top().first;
        return pSum-val;
    }
};



int main() {

    // input
    vector<int> nums = readVectorOfInt("[2,4,-2]");
    int k = 5;

    // solution
    long long ans = Solution().kSum(nums, k);

    // output
    cout<<ans<<endl;

    return 0;
}



