class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size(), left = 0, right = 0, ans = 0;
        long long pro = 1;

        while(right < n) {
            pro *= nums[right++];

            while(left < right && pro >= k) {
                pro /= nums[left++];
            }
            ans += (right - left);
        }
        return ans;
    }
};