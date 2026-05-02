class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> st;
        vector<int> ans(k, 0);

        for(const auto& it : logs) {
            st[it[0]].insert(it[1]);
        }

        for(const auto& it : st){
            ans[it.second.size() - 1]++;
        }

        return ans;
    }
};