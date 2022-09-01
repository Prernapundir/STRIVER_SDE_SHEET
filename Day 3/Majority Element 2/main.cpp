/*

Approach :

Extended Moore's Voting algorithm 
-------------------------------------

1. Here take 4 elements , count1 ,count2, candidate1 and candidate2
2. Go with same approach as in <Majority Element 1> 
3. Iterate over the array , see this diagram

              current element                           / YES  : candidate1=current element, count1++
                   |                       count1==0  -- 
                   |          None       /              \ NO
                 equal to  ------------ /
                 /      \               \               / YES :  : candidate2=current element, count2++
                /        \               \ count2==0  --
           candidate1    candidate2                     \ NO
               |             |
               |             |
              coun1++       count2++

4. Now we have candidate1 nad candidate2 , we need to verify is we got correct result ot=r not
5. Iterae overy array and check both candidate number's count

Time Complexity : O(n)

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate1=0,candidate2=0;
        int count1=0,count2=0;
        
        for(auto x:nums){
          if(x==candidate1){
              count1++;
          }else if(x==candidate2){
              count2++;
          }else if(count1==0){
              candidate1=x;
              count1++;
          }else if(count2==0){
              candidate2=x;
              count2++;
          }else{
              count1--;
              count2--;
          }
        }
        
        count1=0,count2=0;
        
        for(auto x:nums){
            if(x==candidate1) count1++;
            else if(x==candidate2) count2++;
        }
        vector<int> ans;
        if(count1>n/3) ans.push_back(candidate1);
        if(count2>n/3) ans.push_back(candidate2);

        return ans;
    }
};
