/*
Approach:
1. Sort the intervals on the basis of start time , use sort() func
2. Take first interval in temp array
3. Iterate over the arry from first index , and compare the endTime of temp array with current interval start Time
4. If startTime of current interval is less , merge the intervals
*/

class Solution {
public:
 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        
        // Take first interval
        vector<int> temp=intervals[0];
        
        for(int i=1;i<intervals.size();i++){
            // if startTime of current interval <=temp end time => merge the intervals
            if(intervals[i][0]<=temp[1]){
                temp[1]=max(intervals[i][1],temp[1]);     
            }else{
                // else add temp to ans , and update with current interval
                ans.push_back(temp);
                temp=intervals[i];
            }
        }
        
        ans.push_back(temp);
        
        return ans;
    }
};
