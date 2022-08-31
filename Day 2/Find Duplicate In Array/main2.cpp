/*
Approach 
Negative Marking Apprach :
----------------------------

1. As only one element is duplicate and its elements are bound between (1,n)
2. So we will iterate the array and will mark the index element with -1
3. If while marking the index element negative , if we found that already negative, mean its already marked negative before and 
its the duplicate number

Time Complexity : O(n)

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
       for(int i=0;i<nums.size();i++){
           int val=nums[abs(nums[i])-1];
           if(val<0){
               ans=abs(nums[i]);
           }
           nums[abs(nums[i])-1]*=-1;
       }
        return ans;
    }
};
