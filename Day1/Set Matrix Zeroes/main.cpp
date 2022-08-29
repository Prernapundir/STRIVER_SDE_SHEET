/*
Approach 1:
1. Take one row and col-size array, and set the values 0 on the basis of matrix[i][j]=0;
2. Later on the basis of theses arrays , make the values of matrix zeroe with corresponding values
3. This approach will take extra space
*/

/*
Approach 2:
1. Here we are going to store the values in first row and column of matrix for the reference rrathre than storing in different arrays
2. Either skip 1st row or first col , becoz first cell is common in both 
   lets suppose we have maked first cell of matrix zero on the basis of first column last cell value, then while setting the value to 0 
   we will mark the first values zeros becoz this first cell is zero {thst's wrong , that's y we have to take col flag}
2. Iterate from last row and col and fill the whole matrix , while skipping the row or col {as selected above}
3. Now first row or may be first col fill it on the basis of col flag
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        // This flag is we are using for first column,
        //later first column will be set zero only if this col-flag value will be true
        bool col=false;
        
        // Here checking if any value is zero in first column, if yes then make the col-flag true
        for(int i=0;i<m;i++) {
            if(matrix[i][0]==0) col=true;
        }
        
        // Skipping first col as , j=1
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
       
        //Skipping first col , as j>=1
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        // Now setting the first column on the basisi of col-flag
        if(col){
         for(int i=0;i<m;i++) {
            matrix[i][0]=0;
          }
        }
        
        return;
    }
};
