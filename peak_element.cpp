class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int tot = nums.size();
        if (nums[0] > nums[1]) {return 0;
        } 
        if(nums[tot-1] > nums[tot-2]) {return tot-1;}
        for(int i=1;i<tot-1;i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {return i;
            }
        }
    }
};
