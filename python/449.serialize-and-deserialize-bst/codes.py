"""
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
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
    root = convertStringToTreeNode(input)

    # solution
    ser = Codec()
    deser = Codec()
    tree = ser.serialize(root)
    ans = deser.deserialize(tree)

    # outputs
    output = convertTreeNodeToString(ans)
    print(output)

