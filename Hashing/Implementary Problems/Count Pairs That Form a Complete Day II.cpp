class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> mpp(24, 0);

        for(const int& it : hours) mpp[it % 24]++;

        for(int i = 1; i < 12; i++) {
            ans += mpp[i] * mpp[24 - i];
        }

        int n = mpp[0];
        ans += n * 1ll * (n - 1) / 2;

        n = mpp[12];
        ans += n * (n - 1) / 2;

        return ans;
    }
};