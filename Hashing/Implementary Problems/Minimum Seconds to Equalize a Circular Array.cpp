class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        mpp.reserve(n);

        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(const auto& it : mpp) {
            const vector<int>& temp = it.second;
            int sz = temp.size();

            int maxGap = temp[0] + n - temp.back();

            for(int i = 1; i < sz; i++) maxGap = max(maxGap, temp[i] - temp[i - 1]);

            ans = min(ans, maxGap / 2);
        }

        return ans;
    }
};