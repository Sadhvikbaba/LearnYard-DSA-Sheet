class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0LL);
        long long ans = LONG_MAX;
        int n = beans.size();

        for(int i = 0; i < n; i++) {
            long long keep = 1ll * beans[i] * (n - i);
            ans = min(ans, total - keep);
        }

        return ans;
    }
};