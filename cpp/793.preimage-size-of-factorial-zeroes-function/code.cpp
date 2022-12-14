#include "../Utils/io.cpp"

/* 
 f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。

例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/28
class Solution {
public:
    int preimageSizeFZF(int k) {
        return lowerBound(k+1) - lowerBound(k);
    }
private:
    int k;
    int count(long long val) {
        int cnt=0;
        while (val) {
            val /= 5;
            cnt += val;
        }
        return cnt;
    }
    int lowerBound(int k) {
        long long lo=0, hi=5LL*k;
        while (lo<hi) {
            long long mid = lo + (hi-lo)/2;
            if (count(mid)<k) 
                lo = mid+1;
            else 
                hi = mid;
        }
        return lo;
    }
};



int main() {

    // input
    int k = 1000000000;

    // solution
    int ans = Solution().preimageSizeFZF(k);

    // output
    cout<<ans<<endl;

    return 0;
}