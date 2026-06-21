class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                grid[i][j] += (i ? grid[i - 1][j] : 0) + 
                (j ? grid[i][j - 1] : 0) -
                (j && i ? grid[i - 1][j - 1] : 0);

                if(grid[i][j] <= k) ans++;
                else break;
            }
            if(i && grid[i - 1][0] > k) break;
        }
        return ans;
    }
};