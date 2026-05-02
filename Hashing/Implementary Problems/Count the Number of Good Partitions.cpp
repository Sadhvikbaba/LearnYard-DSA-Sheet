class Solution {
private:
    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++) mpp[nums[i]] = i;

        int maxLast = 0;
        int segments = 0;
        int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            maxLast = max(maxLast, mpp[nums[i]]);
            if(i == maxLast) segments++;
        }

        return modPow(2, segments - 1, MOD);
    }
};