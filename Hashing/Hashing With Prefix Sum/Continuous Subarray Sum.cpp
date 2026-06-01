class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            sum = (1ll * sum + nums[i]) % k;
            auto it = mpp.find(sum);
            if(it != mpp.end()) {
                if(i - it->second >= 2)return true;
            }else mpp[sum] = i;
        }
        return false;
    }
};