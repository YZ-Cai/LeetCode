#include "../Utils/io.cpp"

/* 
有 n 个 (id, value) 对，其中 id 是 1 到 n 之间的一个整数，value 是一个字符串。不存在 id 相同的两个 (id, value) 对。

设计一个流，以 任意 顺序获取 n 个 (id, value) 对，并在多次调用时 按 id 递增的顺序 返回一些值。

实现 OrderedStream 类：

OrderedStream(int n) 构造一个能接收 n 个值的流，并将当前指针 ptr 设为 1 。
String[] insert(int id, String value) 向流中存储新的 (id, value) 对。存储后：
如果流存储有 id = ptr 的 (id, value) 对，则找出从 id = ptr 开始的 最长 id 连续递增序列 ，并 按顺序 返回与这些 id 关联的值的列表。然后，将 ptr 更新为最后那个  id + 1 。
否则，返回一个空列表。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-an-ordered-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/16
struct node
{
    int id;
    string value;
    node() = default;
    node(int a, string b): id(a), value(b) {}
    const bool operator< (const node& x) {
        return id<x.id;
    }
};

class OrderedStream {
public:
    OrderedStream(int n) {
        data = new node[n];
    }
    
    vector<string> insert(int idKey, string value) {
        data[end++] = node(idKey, value);
        vector<string> res;
        if (idKey==ptr) {
            sort(data+start, data+end);
            int cur = start+1;
            while (cur<end && data[cur].id==data[cur-1].id+1)
                cur++;
            for (int i=start; i<cur; i++)
                res.push_back(data[i].value);
            ptr = data[cur-1].id + 1;
            start = cur;
            return res;
        }
        return res;
    }
private:
    node *data;
    int ptr=1, start=0, end=0;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */


int main() {

    OrderedStream os= OrderedStream(5);
    printVectorOfString(os.insert(3, "ccccc"));     // 插入 (3, "ccccc")，返回 []
    printVectorOfString(os.insert(1, "aaaaa"));     // 插入 (1, "aaaaa")，返回 ["aaaaa"]
    printVectorOfString(os.insert(2, "bbbbb"));     // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
    printVectorOfString(os.insert(5, "eeeee"));     // 插入 (5, "eeeee")，返回 []
    printVectorOfString(os.insert(4, "ddddd"));     // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]

    return 0;
}



