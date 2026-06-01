#include<numeric>

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = total % p, n = nums.size();

        if(rem == 0) return 0;

        unordered_map<int, int> mpp;
        mpp.reserve(n * 2); // by just adding this line it went runtime beats from 45% to 99.5% in leetcode
        mpp[0] = -1;
        int sum = 0, mini = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;
            int target = (sum - rem + p) % p;
            auto temp = mpp.find(target);
            if(temp != mpp.end()) {
                mini = min(mini, i - temp -> second);
            }
            mpp[sum] = i;
        }
        if(mini == n) return -1;

        return mini;
    }
};