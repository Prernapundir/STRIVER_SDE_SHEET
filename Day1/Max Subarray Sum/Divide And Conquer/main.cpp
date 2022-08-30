/*
Divide and Conquer approach
Steps:
1. Find the left Sum
2. Find right sum
3. Find the cross sum
4. return max of all three

How to find cross sum ?

eg: -2 1 -1 4 -1 2 1 -5 4, midvalue =-1

    find leftSum from mid, leftSum = (left to mid) and right Sum from mid rightSum = (mid+1 to high) 
    
    leftSum = max (-1, -1+4, -1+4+(-1), -1+4+(-1)+1, -1+4+(-1)+(-2)) = 3
    rightSum = max (2, 2+1, 2+1+(-5), 2+1+(-5)+4) = 3
    so, crossSum = leftSum + rightSum = 3 + 3 = 6

*/

class Solution {
public:
    
    int CrossSum(vector<int>& nums,int left,int right,int mid){
        int leftSum=INT_MIN,sum=0,rightSum=INT_MIN;
        
        //firstly find the leftSum from mid towards the left end
        for(int i=mid;i>=left;i--){
            sum+=nums[i];
            leftSum=max(leftSum,sum);
        }
        
        sum=0;
        // find the right sum from mid+1 towards the right end
        for(int i=mid+1;i<=right;i++){
            sum+=nums[i];
            rightSum=max(rightSum,sum);
        }
        
        // return sum :crossSum
        return leftSum+rightSum;
    }
    
    int helper(vector<int>&nums,int left,int right){
        
        if(left>=right) return nums[left];
        
        int mid=left+(right-left)/2;
        
        int leftSum=helper(nums,left,mid);  // leftSum
        int rightSum=helper(nums,mid+1,right);  // rightSum
        int crossSum=CrossSum(nums,left,right,mid); //crossSum
        
        return max({leftSum,rightSum,crossSum});
    }
    
    int maxSubArray(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
     
};

