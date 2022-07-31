#include "../Utils/io.cpp"

/* 
给你一个正整数数组 grades ，表示大学中一些学生的成绩。你打算将 所有 学生分为一些 有序 的非空分组，其中分组间的顺序满足以下全部条件：

第 i 个分组中的学生总成绩 小于 第 (i + 1) 个分组中的学生总成绩，对所有组均成立（除了最后一组）。
第 i 个分组中的学生总数 小于 第 (i + 1) 个分组中的学生总数，对所有组均成立（除了最后一组）。
返回可以形成的 最大 组数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-number-of-groups-entering-a-competition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/07/31
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        int n = grades.size();
        sort(grades.begin(), grades.end());
        int ans = 0;
        long last = 0;
        int lastCnt = 0;
        
        int i = 0;
        int cur = 0;
        int curCnt = 0;
        while (i<n) {
            cur += grades[i];
            curCnt++;
            i++;
            if (curCnt>lastCnt && cur>last) {
                ans++;
                lastCnt = curCnt;
                last = cur;
                cur = 0;
                curCnt = 0;
            }
        }
        return ans;
    }
};



int main() {

    // inputs
    string input = "[10,6,12,7,3,5]";
    vector<int> grades = readVectorOfInt(input);

    // solve problem
    int ans = Solution().maximumGroups(grades);

    // outputs
    cout<<ans<<endl;

    return 0;
}



