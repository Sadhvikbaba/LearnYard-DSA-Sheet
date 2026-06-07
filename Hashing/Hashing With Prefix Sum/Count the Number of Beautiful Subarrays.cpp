class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int prefixXor = 0;
        long long ans = 0;
        unordered_map<int, int> mpp;
        mpp.reserve(nums.size() * 2);
        mpp[0] = 1;

        for(const int& it : nums) {
            prefixXor ^= it;
            int target =  prefixXor;
            auto temp = mpp.find(target);
            if(temp != mpp.end()) ans += temp -> second;
            mpp[prefixXor]++;
        }
        return ans;
    }
};