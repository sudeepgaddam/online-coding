//Given an array of integers and an integer k, find out whether there there are two distinct indices i and j
//in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 

class Solution {
public:

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int prev,len = nums.size();
        unordered_map<int,int>mm;


        //fill map with numbers positions
        for(int i=0;i<len;i++){

            if(mm.find(nums[i])==mm.end()){
                mm[nums[i]] = i;
            }else{
                prev = mm[(nums[i])];
                if(i-prev<=k)return true;
                mm[nums[i]] = i;
            }
        }        

        return false;
    }
};
