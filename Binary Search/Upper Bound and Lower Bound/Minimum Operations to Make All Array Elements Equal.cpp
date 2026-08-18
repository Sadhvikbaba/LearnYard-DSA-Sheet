class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> ans;

        for(const long long& it : queries) {
            int ind = lower_bound(nums.begin(), nums.end(), it) - nums.begin();

            long long left = it * ind - prefix[ind], right = (prefix[n] - prefix[ind]) - 1ll * it * (n - ind);

            ans.emplace_back(left + right);
        }
        return ans;
    }
};