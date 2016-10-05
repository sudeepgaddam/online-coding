/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/


class Solution {
public:
   void genSubset(int num, vector<int>& nums, set<vector<int>> &res) {
        vector<int> tmp;
        for(int i=0;i<32;i++) {
            if ((num >> i) & 0x1) 
                tmp.push_back(nums[i]);
        }    
        sort(tmp.begin(), tmp.end());
        res.insert(tmp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        
        set<vector<int>> res;
        int nsize = nums.size();
        int pow = 1 << nsize;
        
        
        for(int i=0;i<pow;i++) {
            genSubset(i,nums, res);
            
        }
        
        
        return vector<vector<int>>(res.begin(), res.end());
    }
};
