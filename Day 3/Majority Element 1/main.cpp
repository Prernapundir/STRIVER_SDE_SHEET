
/*

Approach 

Moore's Voting Algorithm 
----------------------

1. Take two variables count and candidate
2. Iterate over array , if current element equals to candidate , increase count
   else decrease count and aslo if at any point count becomes 0 , set candidate to curren element and count to 1
3. Final ans will be candidate which will be more than n/2 times in array

Time complexity: O(n)

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        
        for(auto i: nums){
            // If equal to candidate increse the count
            if(i==candidate) count++;
            else if(count==0){  // when count becomes zero , set the candidate and count to 1
                candidate=i;
                count=1;
            }else count--; //else decrease the count
        }
         
        
        return candidate;
    }
};
