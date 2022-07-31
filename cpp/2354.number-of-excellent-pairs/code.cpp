#include "../Utils/io.cpp"

/* 
给你一个下标从 0 开始的正整数数组 nums 和一个正整数 k 。

如果满足下述条件，则数对 (num1, num2) 是 优质数对 ：

num1 和 num2 都 在数组 nums 中存在。
num1 OR num2 和 num1 AND num2 的二进制表示中值为 1 的位数之和大于等于 k ，其中 OR 是按位 或 操作，而 AND 是按位 与 操作。
返回 不同 优质数对的数目。

如果 a != c 或者 b != d ，则认为 (a, b) 和 (c, d) 是不同的两个数对。例如，(1, 2) 和 (2, 1) 不同。

注意：如果 num1 在数组中至少出现 一次 ，则满足 num1 == num2 的数对 (num1, num2) 也可以是优质数对。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-excellent-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/07/30
#include <unordered_set>
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> data;
        for (int& val : nums)
            data.insert(val);

        int* cnts = new int[33]();
        for (int val : data) {
            int cnt = 0;
            while (val) {
                cnt += val&1;
                val >>= 1;
            }
            cnts[cnt]++;
        }

        long long ans = 0;
        for (int i=0; i<33; i++) {
            long long x = cnts[i];
            for (int j=(k-i)>0?(k-i):0; j<33; j++) 
                ans += x * cnts[j];
        }
        return ans;
    }
};



int main() {

    // inputs
    string input = "[1,2,3,1]";
    int k = 3;
    vector<int> nums = readVectorOfInt(input);

    long long ans = Solution().countExcellentPairs(nums, k);
    cout<<ans<<endl;

    return 0;
}



