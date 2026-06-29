class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, ans = 0;
        long long sum = 0;

        for(int right = 0; right < n; right++) {
            sum += nums[right];

            long long cost = 1ll * nums[right] * (right - left + 1) - sum;

            while(cost > k) {
                sum -= nums[left++];
                cost = 1ll * nums[right] * (right - left + 1) - sum;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};