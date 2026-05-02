class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        map<int, int> mpp;

        for(auto& it : items1) mpp[it[0]] += it[1];
        for(auto& it : items2) mpp[it[0]] += it[1];

        for(auto& [a, b] : mpp){
            ans.push_back({a, b});
        }

        return ans;
    }
};