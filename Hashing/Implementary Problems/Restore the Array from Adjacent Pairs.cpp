class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mpp;

        for(const auto& it : nums) {
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
        }

        vector<int> ans;

        for(const auto& it : mpp) {
            if(it.second.size() == 1) {
                int curr = it.first, prev = -1;
                while(ans.size() != mpp.size()) {
                    ans.push_back(curr);

                    int next;
                    if(mpp[curr].size() == 1) next = mpp[curr][0];
                    else next = (mpp[curr][0] == prev) ? mpp[curr][1] : mpp[curr][0];

                    prev = curr;
                    curr = next;
                }
                break;
            }
        }
        return ans;
    }
};