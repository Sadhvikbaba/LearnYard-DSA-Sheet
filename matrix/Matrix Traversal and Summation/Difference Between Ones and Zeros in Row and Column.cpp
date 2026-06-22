class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> onesRow(rows), onesCol(cols);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j]) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                grid[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - cols - rows;
            }
        }
        return grid;
    }
};