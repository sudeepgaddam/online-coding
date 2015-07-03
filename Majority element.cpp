class Solution {
public:
int phase_one(vector<int> &nums){
   int maj = nums[0];
   int n = nums.size();
   int count =1;
    for (int i=1;i<n;i++){
        if (nums[i] !=maj) {
            count--;
        } else {count++;}
        if (count <=0) {
            maj = nums[i];
            count =1;
        }
    }
    return maj;
}
bool validate_maj(int maj, vector<int>& nums){
    int count =0;
    for (auto a: nums) {
        if (a == maj) count++;
    }
    if (count > nums.size()/2) 
    {return true;} 
    else {return false;}
}
    int majorityElement(vector<int>& nums) {
        int temp = phase_one(nums);
        if (validate_maj(temp,nums)) {cout<<temp;}
        return temp;
    }
};
