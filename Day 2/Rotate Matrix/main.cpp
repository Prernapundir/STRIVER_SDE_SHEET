/*Approach 

What is transponse of a matrix ?

Transpose = Row becomes columna nd column becomes row

 [                       [
 [1,2,3]                 [1,4,7]
 [4,5,6]   Transpose =>  [2,5,8]
 [7,8,9]                 [3,6,9]
 ]                       ]

Steps to rotate image by 90 degree :
1. Take the transpose of matrix 
2. Then reverse each row 

Another way of doing , also we can do ,
1. Reverse the matrix first
 [                       [
 [1,2,3]                 [7,8,9]
 [4,5,6]   Reverse =>    [4,5,6]
 [7,8,9]                 [1,2,3]
 ]                       ]

2. Take the transpose now

Time Complexity : O(n) -> as we are iterating half matrix only while swapping and reversing 

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        reverse(matrix.begin(),matrix.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
    }
};
