# LeetCode Solutions with Local Running & Debuging

<br/>

Provide input & output interfaces for running & debuging solutions locally by simply

1. Paste input string from LeetCode
2. Use interfaces to decode input string
3. Use interfaces to output answer

Currently support `C++` and `Python`, including my solutions for some problems. Keep updating!

<br/>

## Example

In [623. Add One Row to Tree](https://leetcode.cn/problems/add-one-row-to-tree/), given the root of a binary tree and two integers val and depth, we need to add a row of nodes with value val at the given depth.

C++ codes for running or debuging simply is:

```c++
// template provided by LeetCode
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // your codes here
    }
};

int main() {
    string tree = "[4,2,6,3,1,5]";				// Input string copied from LeetCode
    TreeNode* root = convertStringToBinaryTree(tree);		// Use interface to decode input string
    int val = 1, depth = 2;					// Other inputs
    TreeNode* ans = Solution().addOneRow(root, val, depth);	// invoke your solution
    cout<<convertBinaryTreeToString(ans)<<endl;			// Use interface to output answer
    return 0;
}
```

Python codes for running or debuging simply is:

```python
# template provided by LeetCode
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
	# your codes here

tree = "[4,2,6,3,1,5]"					# Input string copied from LeetCode
root = convertStringToBinaryTree(tree)			# Use interface to decode input string
val = 1							# Other inputs
depth = 2		
ans = Solution().addOneRow(root, val, depth)		# invoke your solution
print(convertBinaryTreeToString(ans))			# Use interface to output answer
```

<br/>

## C++ Interfaces

### Inputs

| Function Name                 | Input Example                        | Output Type                                          |
| ----------------------------- | ------------------------------------ | ---------------------------------------------------- |
| `readVectorOfInt`           | `"[2,1,2,0,1,0,1,2,0,1]"`          | `vector<int>`                                      |
| `readMatrixOfInt`           | `"[[3,7,8],[9,11,13],[15,16,17]]"` | `vector<vector <int>>`                             |
| `convertStringToBinaryTree` | `"[4,2,6,3,1,5]"`                  | `TreeNode*` (following the definition of LeetCode) |

### Outputs

| Function Name                 | Input Type                                           | Output Example                       |
| ----------------------------- | ---------------------------------------------------- | ------------------------------------ |
| `printVectorOfInt`          | `vector<int>`                                      | `"[2,1,2,0,1,0,1,2,0,1]"`          |
| `printMatrixOfInt`          | `vector<vector<int>>`                              | `"[[3,7,8],[9,11,13],[15,16,17]]"` |
| `printVectorOfString`       | `vector<string>`                                   | `"["aa","ab","ac"]"`               |
| `printMatrixOfString`       | `vector<vector<int>>`                              | `"[["aa","ab"],["ac","bb"]]"`      |
| `convertBinaryTreeToString` | `TreeNode*` (following the definition of LeetCode) | `"[4,2,6,3,1,5]"`                  |
| `printTreeNodeValue`        | `TreeNode*` (following the definition of LeetCode) | `4`                                |

<br/>

## Python Interfaces

### Inputs

| Function Name                 | Input Example       | Output Type                                         |
| ----------------------------- | ------------------- | --------------------------------------------------- |
| `convertStringToBinaryTree` | `"[4,2,6,3,1,5]"` | `TreeNode` (following the definition of LeetCode) |

### Outputs

| Function Name                 | Input Type                                          | Output Example      |
| ----------------------------- | --------------------------------------------------- | ------------------- |
| `convertBinaryTreeToString` | `TreeNode` (following the definition of LeetCode) | `"[4,2,6,3,1,5]"` |
