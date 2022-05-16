#include "../Utils/io.cpp"

/* 
给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
*/


// 2022/05/15
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for (int i=0; i<n; i++) {
            int& a = points[i][0];
            int& b = points[i][1];
            for (int j=i+1; j<n; j++) {
                int c = points[j][0] - a;
                int d = points[j][1] - b;
                for (int k=j+1; k<n; k++) {
                    int e = points[k][0] - a;
                    int f = points[k][1] - b;
                    double s = c*f - d*e;
                    s = s>0?s:(-s);
                    ans = ans>s?ans:s;
                }
            }
        }
        return ans / 2;
    }
};



int main() {

    // inputs
    string input = "[[0,0],[0,1],[1,0],[0,2],[2,0]]";
    vector<vector<int>> points = readMatrixOfInt(input);

    // solve problem
    double ans = Solution().largestTriangleArea(points);

    // outputs
    cout<<ans<<endl;

    return 0;
}



