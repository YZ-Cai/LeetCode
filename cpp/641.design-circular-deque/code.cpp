#include "../Utils/io.cpp"

/* 
设计实现双端队列。

实现 MyCircularDeque 类:

MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-circular-deque
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 2022/08/15
class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        size = k;
        data = new int[size];
    }
    
    bool insertFront(int value) {
        if (full)
            return false;
        start = (start+size-1) % size;
        data[start] = value;
        if (start==end)
            full = true;
        return true;
    }
    
    bool insertLast(int value) {
        if (full)
            return false;
        data[end] = value;
        end = (end+1) % size;
        if (start==end)
            full = true;
        return true;
    }
    
    bool deleteFront() {
        if (start==end && full==false)
            return false;
        if (full)
            full = false;
        start = (start+1) % size;
        return true;
    }
    
    bool deleteLast() {
        if (start==end && full==false)
            return false;
        if (full)
            full = false;
        end = (end+size-1) % size;
        return true;
    }
    
    int getFront() {
        if (start==end && full==false)
            return -1;
        return data[start];
    }
    
    int getRear() {
        if (start==end && full==false)
            return -1;
        return data[(end+size-1) % size];
    }
    
    bool isEmpty() {
        return (start==end && full==false);
    }
    
    bool isFull() {
        return full;
    }

private:
    int *data;
    int start=0, end=0, size;
    bool full=false;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */



int main() {

    MyCircularDeque circularDeque = MyCircularDeque(3);     // 设置容量大小为3
    cout<<circularDeque.insertLast(1)<<endl;			    // 返回 true
    cout<<circularDeque.insertLast(2)<<endl;			    // 返回 true
    cout<<circularDeque.insertFront(3)<<endl;			    // 返回 true
    cout<<circularDeque.insertFront(4)<<endl;			    // 已经满了，返回 false
    cout<<circularDeque.getRear()<<endl;  				    // 返回 2
    cout<<circularDeque.isFull()<<endl;				        // 返回 true
    cout<<circularDeque.deleteLast()<<endl;			        // 返回 true
    cout<<circularDeque.insertFront(4)<<endl;			    // 返回 true
    cout<<circularDeque.getFront()<<endl;				    // 返回 4

    return 0;
}



