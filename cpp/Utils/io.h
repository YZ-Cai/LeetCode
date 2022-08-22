#include "libraries.h"


// vector of int
vector<int> readVectorOfInt(string s);
void printVectorOfInt(vector<int>& vec);


// matrix of int
vector<vector<int>> readMatrixOfInt(string s);
void printMatrixOfInt(vector<vector<int>>& matrix);


// vector of string
void printVectorOfString(vector<string>& ss);


// matrix of string
void printMatrixOfString(vector<vector<string>>& matrix);


// binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
string convertBinaryTreeToString(TreeNode* root);
TreeNode* convertStringToBinaryTree(string s);
void printTreeNodeValue(TreeNode* node);