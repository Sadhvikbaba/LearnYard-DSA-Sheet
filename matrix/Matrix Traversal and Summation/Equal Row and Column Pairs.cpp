class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        map<vector<int>, int> mpp;

        for(const vector<int>& it : grid) mpp[it]++;

        for(int i = 0; i < n; i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                temp.push_back(grid[j][i]);
            }
            ans += mpp[temp];
        }
        return ans;
    }
};