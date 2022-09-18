

/*Approach

we have to find : values[i]+values[j]+i-j so rearrange it = (values[i]+i) + (values[j]-j)

we can find values[i]+i for every node 


https://leetcode.com/problems/best-sightseeing-pair/
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int curr=0;
        int ans=0;
        int n=values.size();
        
        vector<int> left(n);
        left[0]=values[0];
        
        // precompute values[i]+i for every node
        for(int i=1;i<n;i++){
           left[i]=max(left[i-1],values[i]+i);
        }
        
        // now calculate simply pair(i,j) cost
        for(int i=1;i<n;i++){
           ans=max(ans,left[i-1]+values[i]-i) ;
        }
        
        return ans;
    }
};
