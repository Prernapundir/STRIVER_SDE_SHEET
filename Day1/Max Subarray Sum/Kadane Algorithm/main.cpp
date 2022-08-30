/*
Approach:
1. Maintain the current sum so far an keep updating the max_sum
2. If at any point curr_sum becomes zero , update currSum=0

Time Complexity: O(n)
Space Complxity: O(1)
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=INT_MIN;
        int curr_sum=0;
        
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            max_sum=max(curr_sum,max_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return max_sum;
    }
};
