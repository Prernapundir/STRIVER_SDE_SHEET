/*
alrorithm:
1. Firstly from the right find the index where , index1=arr[i]<arr[i+1]
2. Second, from the right find the index where , index2=arr[i]>arr[index1]
3. Now , swap(arr[index1],arr[index2]) 
4. finally , reverse(arr.begin()+index1+1,arr.end())
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index1=-1,index2=-1;
        
        // index1=arr[i]>arr[i+1]
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index1=i;
                break;
            }
        }
        
        // if index1==-1 , just reverse the array and return 
        if(index1<0) return reverse(nums.begin(),nums.end());
        
        // index2=arr[i]>arr[index1]
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[index1]){
                index2=i;
                break;
            }
        }
        
        swap(nums[index1],nums[index2]);
        
        reverse(nums.begin()+index1+1,nums.end());
        
        return;
        
    }
};
