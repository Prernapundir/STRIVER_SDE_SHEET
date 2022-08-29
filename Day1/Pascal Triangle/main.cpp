/*
Approach :

1. Simple implementation problem
2. Keep interating till n(given input) and calculate the 
current row value on the basis of last row two values summation

Time Complexity : O(n^2)
Space Complexity :O(n^2)

*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=0;i<numRows;i++){
            // by default keeping all values to be 1 , as first and last vaue will be 1 only
            vector<int> temp(i+1,1);
            
            for(int j=1;j<i;j++){
                // Take last row two values sum and update 
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};
