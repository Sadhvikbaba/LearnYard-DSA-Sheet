class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        long long lsum = 0, rsum = 0;
        vector<int> prefix(n), suffix(n), ans(n);

        for(int i = 0; i < n; i++) {
            lsum += nums[i];
            rsum += nums[n - i - 1];
            prefix[i] = lsum;
            suffix[n - i - 1] = rsum;
        }

        for(int i = 0; i < n; i++) {
            int left = i * nums[i] - prefix[i];
            int right = suffix[i] - (n - i - 1) * nums[i];

            ans[i] = right + left;
        }

        return ans;
    }
};