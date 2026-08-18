class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size(), ans = 0;

        for(const vector<int>& arr : grid) {
            int ind = lower_bound(arr.rbegin(), arr.rend(), 0) - arr.rbegin();
            ans += ind;
        }
        
        return ans;
    }
};