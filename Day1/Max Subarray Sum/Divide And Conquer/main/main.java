class Solution {
   
    public int CrossSum(int [] nums,int left,int right,int mid){
        int leftSum=Integer.MIN_VALUE,sum=0,rightSum=Integer.MIN_VALUE;
        
        //firstly find the leftSum from mid towards the left end
        for(int i=mid;i>=left;i--){
            sum+=nums[i];
            leftSum=Math.max(leftSum,sum);
        }
        
        sum=0;
        // find the right sum from mid+1 towards the right end
        for(int i=mid+1;i<=right;i++){
            sum+=nums[i];
            rightSum=Math.max(rightSum,sum);
        }
        
        // return sum :crossSum
        return leftSum+rightSum;
    }
    
    public int helper(int[] nums,int left,int right){
        
        if(left>=right) return nums[left];
        
        int mid=left+(right-left)/2;
        
        int leftSum=helper(nums,left,mid);  // leftSum
        int rightSum=helper(nums,mid+1,right);  // rightSum
        int crossSum=CrossSum(nums,left,right,mid); //crossSum
        
        return Math.max(Math.max(leftSum,rightSum),crossSum);
    }
    
    public int maxSubArray(int[] nums) {
        return helper(nums,0,nums.length-1);
    }
}
