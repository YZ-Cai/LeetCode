#include "../Utils/io.cpp"

/* 
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-k-closest-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/25
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cur = lower_bound(arr.begin(), arr.end(), x);
        vector<int>::iterator left, right;

        left = right = cur;
        while (k>0 && right!=arr.end() && *right==x) {
            ++right;
            --k;
        }
        
        while (k>0) {
            if (left==arr.begin()) 
                ++right;
            else if (right==arr.end()) 
                --left;
            else {
                int& a = *(left-1);
                int& b = *right;
                if (x-a<=b-x)
                    --left;
                else
                    ++right;
            }
            --k;
        }

        vector<int> ans;
        copy(left, right, back_inserter(ans));
        return ans;
    }
};



int main() {

    // input
    vector<int> arr = readVectorOfInt("[1,2,3,4,5]");
    int k = 4;
    int x = 3;

    // solution
    vector<int> ans = Solution().findClosestElements(arr, k, x);

    // output
    printVectorOfInt(ans);

    return 0;
}