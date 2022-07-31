#include "../Utils/io.cpp"

/* 
给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，每个节点 至多 有一条出边。

有向图用大小为 n 下标从 0 开始的数组 edges 表示，表示节点 i 有一条有向边指向 edges[i] 。如果节点 i 没有出边，那么 edges[i] == -1 。

同时给你两个节点 node1 和 node2 。

请你返回一个从 node1 和 node2 都能到达节点的编号，使节点 node1 和节点 node2 到这个节点的距离 较大值最小化。如果有多个答案，请返回 最小 的节点编号。如果答案不存在，返回 -1 。

注意 edges 可能包含环。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-closest-node-to-given-two-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/07/31
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int* dist1 = new int[n]();
        int* dist2 = new int[n]();
        vector<int>* frontier = new vector<int>;
        vector<int>* nextF = new vector<int>;
        vector<int>* tmp;
        int k = 1;
        
        frontier->push_back(node1);
        dist1[node1] = 1;
        while (frontier->empty()==false) {
            k++;
            nextF->clear();
            
            for (int& cur : *frontier) {
                int& neighbor = edges[cur];
                if (neighbor>-1 && dist1[neighbor]==0) {
                    dist1[neighbor] = k;
                    nextF->push_back(neighbor);
                }
            }
            
            tmp = frontier;
            frontier = nextF;
            nextF = tmp;
        }
        
        frontier->clear();
        frontier->push_back(node2);
        dist2[node2] = 1;
        k = 1;
        while (frontier->empty()==false) {
            k++;
            nextF->clear();
            
            for (int& cur : *frontier) {
                int& neighbor = edges[cur];
                if (neighbor>-1 && dist2[neighbor]==0) {
                    dist2[neighbor] = k;
                    nextF->push_back(neighbor);
                }
            }
            
            tmp = frontier;
            frontier = nextF;
            nextF = tmp;
        }
        
        int minD = 2*n;
        int ans = -1;
        for (int id=0; id<n; id++)
            if (dist1[id]>0 && dist2[id]>0) {
                int dist = dist1[id]>dist2[id]?dist1[id]:dist2[id];
                if (dist<minD) {
                    minD = dist;
                    ans = id;
                }
            }
        return ans;       
    }
};
                    



int main() {

    // inputs
    string input = "[2,2,3,-1]";
    vector<int> edges = readVectorOfInt(input);
    int node1 = 0;
    int node2 = 1;

    // solve problem
    int ans = Solution().closestMeetingNode(edges, node1, node2);

    // outputs
    cout<<ans<<endl;

    return 0;
}



