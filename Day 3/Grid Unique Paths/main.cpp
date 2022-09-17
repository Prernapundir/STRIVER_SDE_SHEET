/*Approach
Simple dp solution 


Lettcode link :
https://leetcode.com/problems/unique-paths/
https://leetcode.com/problems/unique-paths-ii/
https://leetcode.com/problems/unique-paths-iii/


*/


class Solution {
public:
    
    int recur(int x,int y,int m,int n,vector<vector<int>>&dp){
        if(x>=m or y>=n) return 0;
        
        if(x==m-1 and y==n-1) return 1;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        int right=recur(x,y+1,m,n,dp);
        int down=recur(x+1,y,m,n,dp);
        
        return dp[x][y]=right+down;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return recur(0,0,m,n,dp);
    }
};
