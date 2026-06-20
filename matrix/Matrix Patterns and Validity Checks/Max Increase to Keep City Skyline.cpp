class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        vector<int> maxCols(cols, INT_MIN), maxRows(rows, INT_MIN);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                maxRows[i] = max(maxRows[i], grid[i][j]); 
                maxCols[j] = max(maxCols[j], grid[i][j]); 
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int val = min(maxRows[i], maxCols[j]);
                ans += val - grid[i][j];
            }
        }

        return ans;
    }
};