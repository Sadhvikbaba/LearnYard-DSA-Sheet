class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        int n = rows * cols;
        vector<int> temp;
        k %= n;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                temp.push_back(grid[i][j]);
            }
        }

        reverse(temp.begin(), temp.end());
        reverse(temp.begin(), temp.begin() + k);
        reverse(temp.begin() + k, temp.end());

        for(int i = 0; i < n; i++) {
            grid[i / cols][i % cols] = temp[i];
        }
        return grid;
    }
};