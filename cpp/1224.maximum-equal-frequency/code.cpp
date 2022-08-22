#include "../Utils/io.cpp"

/* 
给你一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回该前缀的长度：

从前缀中 恰好删除一个 元素后，剩下每个数字的出现次数都相同。
如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-equal-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/18
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freqTOCnt, valToFreq;
        int ans = 0;

        for (int i=0; i<nums.size(); ++i) {
            int& val = nums[i];

            if (valToFreq.find(val)==valToFreq.end()) {
                valToFreq[val] = 1;
                if (freqTOCnt.find(1)==freqTOCnt.end())
                    freqTOCnt[1] = 1;
                else
                    ++freqTOCnt[1];

            } else {
                int& freq = valToFreq[val];
                if (freqTOCnt[freq]==1)
                    freqTOCnt.erase(freqTOCnt.find(freq));
                else
                    --freqTOCnt[freq];

                ++freq;
                if (freqTOCnt.find(freq)==freqTOCnt.end())
                    freqTOCnt[freq] = 1;
                else
                    ++freqTOCnt[freq];
            }

            if (freqTOCnt.size()==2) {
                auto iter = freqTOCnt.cbegin();
                int a, aCnt, b, bCnt;
                a = iter->first;
                aCnt = iter->second;
                ++iter;
                b = iter->first;
                bCnt = iter->second;
                if ( ( a==b+1 && aCnt==1 ) || 
                     ( b==a+1 && bCnt==1 ) ||
                     ( a==1 && aCnt==1) ||
                     ( b==1 && bCnt==1) )
                    ans = i+1;
            }
            if (freqTOCnt.size()==1 && (freqTOCnt.begin()->second==1 || freqTOCnt.begin()->first==1))
                ans = i+1;
        }

        return ans;
    }
};



int main() {

    // inputs
    string input = "[2,2,1,1,5,3,3,5]";
    vector<int> nums = readVectorOfInt(input);

    // solve problem
    int ans = Solution().maxEqualFreq(nums);

    // outputs
    cout<<ans<<endl;

    return 0;
}



