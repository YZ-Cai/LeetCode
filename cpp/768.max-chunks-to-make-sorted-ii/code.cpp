#include "../Utils/io.cpp"

/* 
这个问题和“最多能完成排序的块”相似，但给定数组中的元素可以重复，输入数组最大长度为2000，其中的元素最大为10**8。

arr是一个可能包含重复元素的整数数组，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。

我们最多能将数组分成多少块？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/max-chunks-to-make-sorted-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/13
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int s=0, i, j, ans=0;
        unordered_map<int, int> mark;
        while (s<n) {
            i = s-1;
            j = s;
            
            do {
                i++;
                if (mark.find(arr[i])==mark.end() || mark[arr[i]]==0) {
                    while (arr[i]!=sortedArr[j]) {
                        if (mark.find(sortedArr[j])==mark.end())
                            mark[sortedArr[j]] = 1;
                        else
                            mark[sortedArr[j]]++;
                        j++;
                    }
                    j++;
                } else
                    mark[arr[i]]--;
            } while (i+1<j);

            ans++;
            s = j;
        }

        return ans;
    }
};



int main() {

    // inputs
    string input = "[4,4,4,5,2,3,4,5,5,6]";
    vector<int> arr = readVectorOfInt(input);

    // solve problem
    int ans = Solution().maxChunksToSorted(arr);

    // outputs
    cout<<ans<<endl;

    return 0;
}



