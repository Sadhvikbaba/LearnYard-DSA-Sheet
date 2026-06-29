class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int target = total - x;

        if(target < 0) return -1;
        if(target == 0) return nums.size();

        int left = 0, ans = -1, n = nums.size();
        long long sum = 0;

        for(int right = 0; right < n; right++) {
            sum += nums[right];
            while(sum > target) sum -= nums[left++];

            if(sum == target) ans = max(ans, right - left + 1);
        }
        return (ans == -1) ? -1 : n - ans;
    }
};