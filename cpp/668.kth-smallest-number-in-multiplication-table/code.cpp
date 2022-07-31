#include "../Utils/io.cpp"

/* 
Nearly everyone has used the Multiplication Table. 
The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/05/18
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if (m>n) {
            int tmp = m;
            m = n;
            n = tmp;
        }
        int left = 1;
        int right = m*n;

        while (left < right) {
            int val = (right-left)/2 + left;
            int count = 0;

            int i=1;
            while (i<=val && i<=m) {
                int tmp = val / i;
                count += tmp<n?tmp:n;
                i += 1;
            }

            if (count>=k)
                right = val - 1;
            else
                left = val + 1;
        }
        return left;
    }
};



int main() {

    // inputs
    int m = 3;
    int n = 3;
    int k = 5;

    // solve problem
    int ans = Solution().findKthNumber(m, n, k);

    // outputs
    cout<<ans<<endl;

    return 0;
}



