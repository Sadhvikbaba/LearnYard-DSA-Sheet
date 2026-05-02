class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(const int& it : nums) mpp[it]++;

        vector<vector<int>> ans;

        for(const auto& [num, count] : mpp) {
            for(int i = 0; i < count; i++){
                if(ans.size() <= i) ans.push_back({});
                ans[i].push_back(num);
            }
        }
        return ans;

    }
};