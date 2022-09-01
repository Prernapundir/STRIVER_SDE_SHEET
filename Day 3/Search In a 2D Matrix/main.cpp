/*Approach

This approach is called Binary Serach Tree version

-------------------------------------------------

1. Here we have to take two pointers i and j
2. Either start from top-left corners or bottom-right corners
like i=0 and j=m-1,
if matrix[i][j]>target -> j--
else if marix[i][j]<target -> i++
else found the element


Time COmplexity : O(m+n)

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        int m=matrix.size() ;
        
        while(i<m and j>=0){ 
            
            int val=matrix[i][j];
            
            // decrement the column
            if(val>target){
                j--;
            }else if(val<target){
                //increment the row
                i++;
            }else{
                return true;
            }
        }
        
        return false;
    }
};
