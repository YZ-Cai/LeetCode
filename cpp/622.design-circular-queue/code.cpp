#include "../Utils/io.cpp"

/* 
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-circular-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/02
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size = k;
        data = new int[size];
    }
    
    bool enQueue(int value) {
        if (full)
            return false;
        data[curEnd] = value;
        curEnd = (curEnd+1) % size;
        if (curEnd==curStart)
            full = true;
        return true;
    }
    
    bool deQueue() {
        if (curEnd==curStart && full==false)
            return false;
        full = false;
        curStart = (curStart+1) % size;
        return true;
    }
    
    int Front() {
        if (curEnd==curStart && full==false)
            return -1;
        return data[curStart];
    }
    
    int Rear() {
        if (curEnd==curStart && full==false)
            return -1;
        return data[(size+curEnd-1)%size];
    }
    
    bool isEmpty() {
        return (curEnd==curStart && full==false);
    }
    
    bool isFull() {
        return full;
    }

private:
    int* data;
    int curStart=0, curEnd=0, size;
    bool full = false;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */



int main() {

    MyCircularQueue circularQueue = MyCircularQueue(3);     // 设置长度为 3
    cout<<circularQueue.enQueue(1)<<endl;                   // 返回 true
    cout<<circularQueue.enQueue(2)<<endl;                   // 返回 true
    cout<<circularQueue.enQueue(3)<<endl;                   // 返回 true
    cout<<circularQueue.enQueue(4)<<endl;                   // 返回 false，队列已满
    cout<<circularQueue.Rear()<<endl;                       // 返回 3
    cout<<circularQueue.isFull()<<endl;                     // 返回 true
    cout<<circularQueue.deQueue()<<endl;                    // 返回 true
    cout<<circularQueue.enQueue(4)<<endl;                   // 返回 true
    cout<<circularQueue.Rear()<<endl;                       // 返回 4

    return 0;
}



