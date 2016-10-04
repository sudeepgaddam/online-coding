/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


*/


/*
todo: This is Just one way of solving it, Which I am comfortable of thinking.
Have to look into other ways in leetcode forum and try to get ideas from there
*/

class Solution {
public:
   void genSubset(int num, vector<int>& nums, vector<vector<int>> &res) {
        vector<int> tmp;
        for(int i=0;i<32;i++)
            if ((num >> i) & 0x1) 
                tmp.push_back(nums[i]);
        
        res.push_back(tmp);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        int nsize = nums.size();
        int pow = 1 << nsize;
        
        for(int i=0;i<pow;i++) genSubset(i,nums, res);
        
        return res;
    }
};
