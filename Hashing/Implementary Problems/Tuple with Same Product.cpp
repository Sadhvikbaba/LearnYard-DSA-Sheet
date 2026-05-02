class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                mpp[nums[i] * nums[j]]++;
            }
        }

        for(const auto& it : mpp) {
            int f = it.second;
            if(f >= 2) {
                ans += f * (f - 1) * 4;
            }
        }

        return ans;
    }
};