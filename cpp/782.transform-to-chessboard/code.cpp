#include "../Utils/io.cpp"

/* 
一个 n x n 的二维网络 board 仅由 0 和 1 组成 。每次移动，你能任意交换两列或是两行的位置。

返回 将这个矩阵变为  “棋盘”  所需的最小移动次数 。如果不存在可行的变换，输出 -1。

“棋盘” 是指任意一格的上下左右四个方向的值均与本身不同的矩阵。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/transform-to-chessboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/23
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();

        int row1 = rowRep(board, 0);
        int row2 = reverveBit(row1);
        for (int i=1; i<n; ++i) {
            int rep = rowRep(board, i);
            if (rep!=row1 && rep!=row2)
                return -1;
        }

        int col = colRep(board, 0);
        int rowBitCnt=countBit(row1), colBitCnt=countBit(col);
        if (abs(n-2*rowBitCnt)<=1 && abs(n-2*colBitCnt)<=1) {
            if (n%2) {
                int ans1 = (rowBitCnt==n-rowBitCnt+1)?countOdd(row1):countEven(row1);
                int ans2 = (colBitCnt==n-colBitCnt+1)?countOdd(col):countEven(col);
                return ans1+ans2;
            }

            int ans1 = countOdd(row1)<countEven(row1)?countOdd(row1):countEven(row1);
            int ans2 = countOdd(col)<countEven(col)?countOdd(col):countEven(col);
            return ans1+ans2;
        }
        return -1;
    }
private:
    int n;
    int rowRep(vector<vector<int>>& board, int i) {
        int res = 0;
        for (int j=0; j<n; ++j)
            res |= board[i][j]<<j;
        return res;
    }
    int colRep(vector<vector<int>>& board, int j) {
        int res = 0;
        for (int i=0; i<n; ++i)
            res |= board[i][j]<<i;
        return res;
    }
    int countBit(int val) {
        int res = 0;
        for (int i=0; i<n; ++i)
            if ( (1<<i)&val )
                ++res;
        return res;
    }
    int countEven(int& val) {
        return countBit(val&0x55555555);
    }
    int countOdd(int& val) {
        return countBit(val&0xaaaaaaaa);
    }
    int reverveBit(int& val) {
        return ((1<<n)-1)&(~val);        
    }
    int abs(int val) {
        return val<0?-val:val;
    }
};



int main() {

    // input
    string input = "[[1,1,0],[0,0,1],[0,0,1]]";
    vector<vector<int>> board = readMatrixOfInt(input);

    // solution
    int ans = Solution().movesToChessboard(board);

    // output
    cout<<ans<<endl;

    return 0;
}



