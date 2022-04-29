#include "headfiles.h"



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
    while (i<s.size()) {
        if (s[i]>='0' && s[i]<='9') {
            int j=1;
            while (s[i+j]>='0' && s[i+j]<='9')
                j++;
            string numStr = s.substr(i,j);
            result.push_back(stoi(numStr));
            i += j;
            continue;
        } 
        i++;
    }

    return result;
}



void printVectorOfInt(vector<int>& vec) {
    if (vec.size()==0)
        cout<<"[]"<<endl;
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