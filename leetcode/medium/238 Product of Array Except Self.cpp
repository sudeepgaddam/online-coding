/*

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)


*/

/*
1. Did it in two passes.
2. In first pass, for every index i, Do the cumulative product from the end except num[i] and store in out[i]
3. In second pass, for every index i, multiply out[i] with cumulative product of nums[0]..nums[i-1].
4. This perfectly gives the expected result without using any extra space and O(n) time.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n_size = nums.size();
        vector<int> out(n_size,1);
        for(int i=n_size-2;i>=0;i--) out[i] = nums[i+1]*out[i+1];
        int cum = nums[0];
        for(int i=1;i<n_size;i++) {
            out[i] = cum*out[i];
            cum = cum*nums[i];
        }
        return out;
    }
};
