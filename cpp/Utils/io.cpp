#include "io.h"



vector<vector<int>> readMatrixOfInt(string s) {
    /* 
    input example: "[[3,7,8],[9,11,13],[15,16,17]]"
    */
   
    vector<vector<int>> result;
    result.push_back({});
    if (s=="[[]]") 
        return result;

    int row = 0;
    int i=2;
    while (i<s.size()-2) {
        if (s[i]>='0' && s[i]<='9') {
            int j=1;
            while (s[i+j]>='0' && s[i+j]<='9')
                j++;
            string numStr = s.substr(i,j);
            result[row].push_back(stoi(numStr));
            i += j;
            continue;
        } 
        if (s[i]=='[') {
            result.push_back({});
            row++;
        } 
        i++;
    }

    return result;
}



vector<int> readVectorOfInt(string s) {
    /* 
    input example: "[2,1,2,0,1,0,1,2,0,1]"
    */
   
    vector<int> result;
    int i=0;
    bool positive = true;
    while (i<s.size()) {
        if ((s[i]>='0' && s[i]<='9') || s[i]=='-') {
            if (s[i]=='-') {
                positive = false;
                i++;
            } else
                positive = true;
            int j=1;
            while (s[i+j]>='0' && s[i+j]<='9')
                j++;
            string numStr = s.substr(i,j);
            if (positive)
                result.push_back(stoi(numStr));
            else
                result.push_back(-stoi(numStr));
            i += j;
            continue;
        } 
        i++;
    }

    return result;
}



void printVectorOfInt(vector<int>& vec) {
    if (vec.size()==0) {
        cout<<"[]"<<endl;
        return;
    }
    cout<<"["<<vec[0];
    for (int i=1; i<vec.size(); i++)
        cout<<","<<vec[i];
    cout<<"] (size="<<vec.size()<<")"<<endl;    
}



void printMatrixOfInt(vector<vector<int>>& matrix) {
    if (matrix.size()==0) {
        cout<<"[[]]"<<endl;
        return;
    }
    
    cout<<"[";
    for (auto& row : matrix) {
        cout<<"["<<row[0];
        for (int i=1; i<row.size(); i++)
            cout<<", "<<row[i];
        cout<<"]"<<endl;
    }
    cout<<"] (size="<<matrix.size()<<"*"<<matrix[0].size()<<")"<<endl;    
}



// Encodes a tree to a single string.
string convertBinaryTreeToString(TreeNode* root) {
    vector<string> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur==NULL)
            ans.push_back("null");
        else {
            ans.push_back(to_string(cur->val));
            q.push(cur->left);
            q.push(cur->right);
        }
    }
        
    int finish = ans.size()-1;
    while (finish>=0 and ans[finish]=="null")
        finish -= 1;
    if (finish==0)
        return "[]";
    string str = "["+ans[0];
    for (int i=1; i<finish+1; i++)
        str += ","+ans[i];
    return str+"]";
}
   


// Decodes string to tree.
TreeNode* convertStringToBinaryTree(string s) {
    if (s.length()==2)
        return NULL;
    vector<string> data;
    int i=0;
    while (i<s.size()) {
        if (s[i]>='0' && s[i]<='9') {
            int j=1;
            while (s[i+j]>='0' && s[i+j]<='9')
                j++;
            string numStr = s.substr(i,j);
            data.push_back(numStr);
            i += j;
            continue;
        }
        if (s[i]=='n') {
            data.push_back("null");
            i += 4;
            continue;
        }
        i++;
    }

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(data[0]));
    q.push(root);

    i = 1;
    while (i<data.size()) {
        TreeNode* parent = q.front();
        q.pop();
        if (data[i]=="null")
            parent->left = NULL;
        else {
            parent->left = new TreeNode(stoi(data[i]));
            q.push(parent->left);
        }
        if (i+1==data.size() || data[i+1]=="null")
            parent->right = NULL;
        else {
            parent->right = new TreeNode(stoi(data[i+1]));
            q.push(parent->right);
        }
        i += 2;
    }
        
    return root;
}   



// print tree node value
void printTreeNodeValue(TreeNode* node) {
    if (node==NULL)
        cout<<"null"<<endl;
    else
        cout<<(node->val)<<endl;
}