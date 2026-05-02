class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for(const auto& [count, arr] : mpp) {
            for(int i = 0; i < arr.size(); i += count) {
                ans.push_back({arr.begin() + i, arr.begin() + i + count});
            }
        }
        return ans;
    }
};