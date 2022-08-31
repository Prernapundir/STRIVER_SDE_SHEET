/*

Approach :

Hare and tortoise Method :
-----------------------------

1. Firstly take two pointers slow and fast
2. Move slow by one step and fast by two step , the point where they will meet = collision point
{becoz cycle appears , duplicate exists in the array}
3. Now start moving slow from head and fast from collison point by one step = entrance point of cycle

Time Complexity : O(n)

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        
        // iteration to get collision point
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        slow=nums[0];
        
        // iteration to get duplication number , entrance point of cycle
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return slow;
    }
};
