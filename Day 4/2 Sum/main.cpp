/*Approach

1. Use map to store{val,index}

Leetcode link :
https://leetcode.com/problems/two-sum/
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int val=target-nums[i];
            if(m.find(val)!=m.end()){
                ans.push_back(m[val]);
                ans.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};
