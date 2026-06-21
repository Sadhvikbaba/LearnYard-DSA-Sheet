class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> ans(cols);

        for(int i = 0; i < cols; i++) {
            int col = i, row;
            for(row = 0; row < rows; row++) {
                if(col + 1 < cols && grid[row][col] == 1 && grid[row][col + 1] != -1) col++;
                else if(col - 1 >= 0 && grid[row][col] == -1 && grid[row][col - 1] != 1) col--;
                else break;
            }
            if(row == rows) ans[i] = col;
            else ans[i] = -1;
        }
        return ans;
    }
};