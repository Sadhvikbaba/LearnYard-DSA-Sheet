class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, pairs = 0;
        int n = nums.size(), left = 0;
        unordered_map<int, int> mpp;
        mpp.reserve(100000);

        for(int right = 0; right < n; right++) {

            auto it = mpp.find(nums[right]);
            if(it != mpp.end()) {
                pairs += it -> second;
                it -> second++;
            } else {
                mpp[nums[right]]++;
            }

            while(pairs >= k) {
                ans += n - right;
                auto it = mpp.find(nums[left]);

                it -> second--;
                pairs -= it -> second;
                left++;
            }
        }
        return ans;
    }
};