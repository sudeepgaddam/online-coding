/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num_zeros = 0;
        
        for(int i=0;i<nums.size();i++) {
            if(!nums[i]) {
                num_zeros++;
            } else {
                nums[i-num_zeros] = nums[i];
            }
            
        }
        
        for(int j=nums.size()-1;j>nums.size()-num_zeros-1;j--) nums[j]=0;
        
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int next_nonzero = 0;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i]) {
                std::swap(nums[i],nums[next_nonzero]);
                next_nonzero++;
            }
            
        }
        
    }
};
