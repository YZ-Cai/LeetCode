#include "../Utils/io.cpp"

/* 
给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。

区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。

返回一个由每个区间 i 的 右侧区间 的最小起始位置组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-right-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/05/19
struct node {
    int id, val;
};

bool cmp(node& a, node& b) {
    return a.val < b.val;
}

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<node> data(n);
        for (int i=0; i<n; i++)
            data[i] = {i, intervals[i][0]};
        sort(data.begin(), data.end(), cmp);

        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            int& id = data[i].id;            
            int& target = intervals[id][1];

            int left = i;
            int right = n-1;
            while (left<=right) {
                int mid = (left+right) / 2;
                if (data[mid].val==target) {
                    left = mid;
                    right = left-1;
                } else {
                    if (data[mid].val<target)
                        left = mid+1;
                    else
                        right = mid-1;
                }
            }
            if (left<n)
                ans[id] = data[left].id;
            else
                ans[id] = -1;
        }

        return ans;
    }
};



int main() {

    // inputs
    string input = "[[3,4],[2,3],[1,2]]";
    vector<vector<int>> intervals = readMatrixOfInt(input);

    // solve problem
    vector<int> ans = Solution().findRightInterval(intervals);

    // outputs
    printVectorOfInt(ans);

    return 0;
}



