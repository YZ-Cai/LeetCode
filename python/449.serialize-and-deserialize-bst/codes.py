"""
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/serialize-and-deserialize-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
import sys
sys.path.append("..")
from Utils.io import *


# 2022/05/05
from queue import Queue
class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        ans = []
        q = Queue()
        q.put(root)

        while q.empty()==False:
            cur = q.get()
            if cur==None:
                ans.append("null")
            else:
                ans.append(str(cur.val))
                q.put(cur.left)
                q.put(cur.right)

        finish = len(ans)-1
        while finish>=0 and ans[finish]=="null":
            finish -= 1
        return ','.join(ans[0:finish+1])       

        
    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        if len(data)==0:
            return None
        data = data.split(',')
        q = Queue()
        root = TreeNode(int(data[0]))
        q.put(root)

        i = 1
        while i<len(data):
            parent = q.get()
            if data[i]=="null":
                parent.left = None
            else:
                parent.left = TreeNode(int(data[i]))
                q.put(parent.left)
            if i+1==len(data) or data[i+1]=="null":
                parent.right = None
            else:
                parent.right = TreeNode(int(data[i+1]))
                q.put(parent.right)
            i += 2
        return root


if __name__ == '__main__':

    # inputs
    input = "[6,4,9,2,null,7,null,1,3,null,8]"
    root = convertStringToBinaryTree(input)

    # solution
    ser = Codec()
    deser = Codec()
    tree = ser.serialize(root)
    ans = deser.deserialize(tree)

    # outputs
    output = convertBinaryTreeToString(ans)
    print(output)

