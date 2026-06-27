class Solution {
private:
    int func(vector<int>& nums, int x) {
        int right = 0, len = 0, n = nums.size(), ans = 0;

        while(right < n) {
            if(nums[right++] <= x) {
                len++;
                ans += len;
            } else len = 0;
        }
        return ans;
    }
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return func(nums, right) - func(nums, left - 1);
    }
};