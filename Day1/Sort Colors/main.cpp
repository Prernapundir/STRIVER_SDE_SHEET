/*
Approach
Three pointer Approach :
1. Take three pointers ,mid=0,low=0 and high=nums.length()-1
2. if nums[mid]==0 , swap(nums[mid],nums[low]) -> increment low and mid both
3. if nums[mid]==2, swap(nums[mid,nums[high]]) -> decrement only high
4. if nums[mid]==1, increment only mid

Time Complexity : O(n)
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }else mid++;
        } 
        return;
    }
};
