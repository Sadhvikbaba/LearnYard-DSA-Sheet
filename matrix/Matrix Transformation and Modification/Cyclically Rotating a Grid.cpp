class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        int layers = min(rows, cols) / 2;

        for(int l = 0; l < layers; l++) {
            vector<int> temp;
            int top = l, bottom = rows - l - 1, left = l, right = cols - l - 1;

            for(int i = left; i < right; i++) temp.push_back(grid[top][i]);
            for(int i = top; i < bottom; i++) temp.push_back(grid[i][right]);
            for(int i = right; i >= left + 1; i--) temp.push_back(grid[bottom][i]);
            for(int i = bottom; i >= top + 1; i--) temp.push_back(grid[i][left]);

            int val = k % temp.size();

            reverse(temp.begin(), temp.begin() + val);
            reverse(temp.begin() + val, temp.end());
            reverse(temp.begin(), temp.end());

            int idx = 0;

            for(int i = left; i < right; i++) grid[top][i] = temp[idx++];
            for(int i = top; i < bottom; i++) grid[i][right] = temp[idx++];
            for(int i = right; i >= left + 1; i--) grid[bottom][i] = temp[idx++];
            for(int i = bottom; i >= top + 1; i--) grid[i][left] = temp[idx++];

        }

        return grid;
    }
};