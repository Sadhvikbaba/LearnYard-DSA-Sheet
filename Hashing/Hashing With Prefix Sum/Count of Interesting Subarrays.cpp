class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<bool> arr(n, false);
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k) arr[i] = true;
        }
        long long ans = 0, sum = 0;
        unordered_map<long long, long long> mpp;
        mpp[0] = 1;

        for(const bool& it : arr) {
            sum = (sum + it) % modulo;
            long long target = (sum - k + modulo) % modulo;
            auto temp = mpp.find(target);
            if(temp != mpp.end()) ans += temp -> second;
            mpp[sum]++;
        }
        return ans;
    }
};