/* Learning 

Use merge sort technique 

Similar like Inversion count

*/

class Solution {
public:
    
    
    int merge(vector<int>&nums,int low,int mid,int high){
        int i=low,j=mid+1;
        vector<int> temp;
        
        int rev_pairs=0;
        while(i<=mid and j<=high){
            if(nums[i]>2LL*nums[j]){
                rev_pairs+=mid-i+1;
                j++;
            } else i++;
        }
        
        i=low,j=mid+1;
        while(i<=mid and j<=high){
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            }else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        
        return rev_pairs;
    }
    
    int mergeSort(vector<int>&nums,int low,int high){
        if(low>=high){
            return 0;
        }
        
        int mid=low+(high-low)/2;
        
        int rev_pairs=0;
        rev_pairs+=mergeSort(nums,low,mid);
        rev_pairs+=mergeSort(nums,mid+1,high);
        rev_pairs+=merge(nums,low,mid,high);
        
        return rev_pairs;
    }
    
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
