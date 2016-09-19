/*

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
Subscribe to see which companies asked this question

/*
Knuth Shuffle Pseudocode:
#include <cstdlib>
#include <algorithm>
#include <iterator>
 
template<typename RandomAccessIterator>
void knuthShuffle(RandomAccessIterator begin, RandomAccessIterator end) {
  for(unsigned int n = end - begin - 1; n >= 1; --n) {
    unsigned int k = rand() % (n + 1);
    if(k != n) {
      std::iter_swap(begin + k, begin + n);
    }
  }
}


*/

*/

class Solution {
    
    private: 
    vector<int> immutable_nums;
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        this->immutable_nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        this->nums = immutable_nums;
        
        return this->nums;
        
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        for(int i=n-1;i>0;i--) {
            int rand_num = rand()%(i+1);
            swap(nums[i],nums[rand_num]);
            
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
