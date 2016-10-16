/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

@todo: do O(nlgn) solution

*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //Two ptr problem
        //Add a new number at position i in every step.
        //After adding, Try to move the first ptr towards right while still the sum>=s
        
        
        int size = nums.size();
        int first = 0;
        int sum=0;
        bool succ = false;
        int res=INT_MAX;
        for(int i=0;i<size;i++) {
            sum+=nums[i];
            while((sum>=s) && (first<=i)) {
                succ= true;
                sum-=nums[first];
                res=min(res, i-first+1);
                first++;
            }
            
        }
        if(!succ) return 0;
        return res;
    }
};
