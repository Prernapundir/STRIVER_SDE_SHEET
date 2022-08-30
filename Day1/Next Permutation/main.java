class Solution {
    public void nextPermutation(int[] nums) {
       
        int n=nums.length;
        int index1=-1,index2=-1;
        
        // index1=arr[i]>arr[i+1]
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index1=i;
                break;
            }
        }
        
        // if index1==-1 , just reverse the array and return 
        if(index1<0) {
            reverse(nums,0);
            return;
        }
        
        // index2=arr[i]>arr[index1]
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[index1]){
                index2=i;
                break;
            }
        }
        
        swap(nums,index1,index2);
        
        reverse(nums,index1+1);
        
        return;
    }
    
    private void reverse(int[] nums,int start){
        int i=start;
        int j=nums.length-1;
        
        while(i<j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }
    
    // In Java , we have to make our sap and reverse function
    private void swap(int[] nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}
