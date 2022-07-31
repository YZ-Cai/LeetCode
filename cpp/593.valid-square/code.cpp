#include "../Utils/io.cpp"

/* 
给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。

点的坐标 pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。

一个 有效的正方形 有四条等边和四个等角(90度角)。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/07/29
#include<algorithm>
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int distances[6];
        distances[0] = distance(p1, p2);
        distances[1] = distance(p1, p3);
        distances[2] = distance(p1, p4);
        distances[3] = distance(p2, p3);
        distances[4] = distance(p2, p4);
        distances[5] = distance(p3, p4);
        sort(distances, distances+6);

        if (distances[0]>0 &&
            distances[0]==distances[1] && 
            distances[1]==distances[2] &&
            distances[2]==distances[3] &&
            distances[4]==distances[5] &&
            distances[4]==2*distances[3])
            return true;
        return false;
    }

private:
    int distance(vector<int>& a, vector<int>& b) {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
};



int main() {

    // inputs
    vector<int> p1 = {0,1};
    vector<int> p2 = {0,0};
    vector<int> p3 = {1,1};
    vector<int> p4 = {1,0}; 

    // solve problem
    bool ans = Solution().validSquare(p1, p2, p3, p4);

    // outputs
    cout<<ans<<endl;

    return 0;
}



