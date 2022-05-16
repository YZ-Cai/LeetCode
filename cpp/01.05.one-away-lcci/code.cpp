#include "../Utils/io.cpp"

/* 
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
*/


// 2022/05/13
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = first.length();
        int n = second.length();
        if (n<m-1 || n>m+1)
            return false;
        
        if (n==m) {
            int cnt = 0;
            for (int i=0; i<m; i++)
                if (first[i]!=second[i]) {
                    cnt++;
                    if (cnt>1)
                        return false;
                }
            return true;
        }

        if (m<n)
            return canInsertOne(first, second);
        return canInsertOne(second, first);
    }

private:
    bool canInsertOne(string& shortString, string& longString) {
        int n = shortString.length();
        int i=0;
        while (i<n && shortString[i]==longString[i])
            i++;
        int j=n-1;
        while (j>=0 && shortString[j]==longString[j+1])
            j--;
        if (j-i<0)
            return true;
        return false;
    }
};



int main() {

    // inputs
    string first = "pale";
    string second = "ple";

    // solve problem
    bool ans = Solution().oneEditAway(first, second);

    // outputs
    cout<<ans<<endl;

    return 0;
}



