/*Approach
1. Purchase at day 1
2. Iterate the array if found at any place less value than the current , update it 
3. Else if greater , sell the stock at that day

Time Complexity : O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int maxi=prices[0];
        
        for(int i=1;i<prices.size();i++){
            // If prices of any stock is less , purchase that day
            if(prices[i]<maxi){
                maxi=prices[i];
            }else{
                // else if greater , sell this day
                max_profit=max(max_profit,prices[i]-maxi);
            }
        }
        
        return max_profit;
    }
};
