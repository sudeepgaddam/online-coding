/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.


*/

/*
There are multiple solutions to this problem
Below is only one kind of solution
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> a;
        int size=nums.size();
        if (size==0){return false;}
        a.insert(nums[0]);
        for (int i=1;i<size;i++){
            if (a.find(nums[i]) != a.end()) return true;
            a.insert(nums[i]);
        }
        
        return false;
    }
};
