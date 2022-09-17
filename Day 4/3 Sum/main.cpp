/*

https://leetcode.com/problems/3sum/

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        
        int j,k;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int target=0-nums[i];
            j=i+1;
            k=nums.size()-1;
            
            while(j<k){
                int val=nums[j]+nums[k];
                if(val>target){
                    k--;
                }else if(val<target){
                    j++;
                }else{
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    while(j<k and nums[j]==nums[j+1]) j++;
                    while(j<k and nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};
