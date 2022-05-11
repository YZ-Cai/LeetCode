from queue import Queue


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None



def convertTreeNodeToString(root: TreeNode) -> str:
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
    return "[" + ','.join(ans[0:finish+1]) + "]"


 
def convertStringToTreeNode(data: str) -> TreeNode:
    """Decodes your encoded data to tree.
    """
    if len(data)==2:
        return None
    data = data[1:-1].split(',')
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
