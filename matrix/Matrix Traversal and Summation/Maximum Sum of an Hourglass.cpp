class Solution {
private:
    long long func(vector<vector<int>>& grid, int r, int c) {
        return 1ll * grid[r][c] + grid[r][c + 1] + grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2];
    }
public:
    int maxSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        long long ans = INT_MIN;

        for(int i = 0; i < rows - 2; i++) {
            for(int j = 0; j < cols - 2; j++) {
                ans = max(ans, func(grid, i, j));
            }
        }
        return ans;
    }
};