class Solution {
    public int maxSubArray(int[] nums) {
        int ans=Integer.MIN_VALUE;
        int curr_sum=0;
        
        for(int i=0;i<nums.length;i++){
            curr_sum+=nums[i];
            ans= Math.max(curr_sum,ans);
            if(curr_sum<0) curr_sum=0;
        }
        return ans;
    }
}
