
/*
Approach :

Binary Search Approach 
--------------------------

1. Treat the matrix like 1-D array and apply binary search
2. For finding the value at particular cell do , matrix[mid/n][mid%n];


Time Complexity :O(log(m*n))

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size(),m=matrix.size();
        int low=0, high=m*n-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int val=matrix[mid/n][mid%n];
            
            if(val>target){
                high--;
            }else if(val<target){
                low++;
            }else{
                return true;
            }
        }
        return false;
    }
};
