class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> copy = nums1;

        sort(copy.begin(), copy.end());
        const int MOD = 1e9 + 7, n = nums1.size();

        long long total = 0, best = 0;

        for(int i = 0; i < n; i++) {
            long long org = abs(nums1[i] - nums2[i]);
            total += org;

            auto it = lower_bound(copy.begin(), copy.end(), nums2[i]);

            if(it != copy.end()) best = max(best, org - abs(*it - nums2[i]));
            if(it != copy.begin()) best = max(best, org - abs(*(--it) - nums2[i]));
        }

        return (total - best) % MOD;

    }
};