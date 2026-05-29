class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp.reserve(nums.size() * 2);
        mpp[0] = 1;
        int count = 0, sum = 0;

        for(const auto& it : nums) {
            sum += it;
            auto temp = mpp.find(sum - k);
            if(temp != mpp.end()) count += temp -> second;
            mpp[sum]++;
        }
        return count;
    }
};