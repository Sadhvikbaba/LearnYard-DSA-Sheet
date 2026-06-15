class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0, odd = 1, n = nums.size();

        while(even < n && odd < n) {
            if(!(nums[even] & 1)) even += 2;
            else if(nums[odd] & 1) odd += 2;
            else swap(nums[even], nums[odd]);
        }
        return nums;
    }
};