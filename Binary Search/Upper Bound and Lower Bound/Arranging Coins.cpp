class Solution {
public:
    int arrangeCoins(long long n) {
        long long low = 0, high = n, ans = -1;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            long long val = (1ll * mid * (mid + 1)) / 2;

            if(val <= n) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        return (ans == -1) ? 0 : ans;
    }
};