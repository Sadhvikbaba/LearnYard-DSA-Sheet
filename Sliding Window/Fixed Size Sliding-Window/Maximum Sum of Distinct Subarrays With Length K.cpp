class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        vector<int> cnt(100001);
        int left = 0, right = 0, n = nums.size(), count = 0;
        long long sum = 0, ans = 0;

        while(right < k) {
            cnt[nums[right]]++;
            if(cnt[nums[right]] == 1) count++;
            sum += nums[right++];
        }
        if(count == k) ans = max(sum, ans);

        while(right < n) {
            cnt[nums[left]]--;
            if(cnt[nums[left]] == 0) count--;
            sum -= nums[left++];
            cnt[nums[right]]++;
            if(cnt[nums[right]] == 1)count++;
            sum += nums[right++];

            if(count == k) ans = max(ans, sum);
        }
        return ans;
    }
};