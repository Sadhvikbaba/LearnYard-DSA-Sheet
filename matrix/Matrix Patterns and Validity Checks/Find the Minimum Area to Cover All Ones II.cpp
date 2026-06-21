class Solution {
private:
    int area(int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
        int minRow = INT_MAX, maxRow = INT_MIN, minCol = INT_MAX, maxCol = INT_MIN;

        for(int i = r1; i <= r2; i++) {
            for(int j = c1; j <= c2; j++) {
                if(grid[i][j]) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        if(minRow == INT_MAX) return INT_MAX / 3;
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        int ans = INT_MAX;

        for(int r1 = 0; r1 < rows - 2; r1++) {
            for(int r2 = r1 + 1; r2 < rows - 1; r2++) {
                int a1 = area(0, 0, r1, cols - 1, grid);
                int a2 = area(r1 + 1, 0, r2, cols - 1, grid);
                int a3 = area(r2 + 1, 0, rows - 1, cols - 1, grid);

                ans = min(ans, a1 + a2 + a3);
            }
        }

        for(int c1 = 0; c1 < cols - 2; c1++) {
            for(int c2 = c1 + 1; c2 < cols - 1; c2++) {
                int a1 = area(0, 0, rows - 1, c1, grid);
                int a2 = area(0, c1 + 1, rows - 1, c2, grid);
                int a3 = area(0, c2 + 1, rows - 1, cols - 1, grid);

                ans = min(ans, a1 + a2 + a3);
            }
        }
        int a,b,d;

        for(int r = 0; r < rows - 1; r++) {
            for(int c = 0; c < cols - 1; c++) {
                a = area(0, 0, r, cols - 1, grid);
                b = area(r + 1, 0, rows - 1, c, grid);
                d = area(r + 1, c + 1, rows - 1, cols - 1, grid);

                ans = min(ans, a + b + d);

                a = area(0, 0, rows - 1, c, grid);
                b = area(0, c + 1, r, cols - 1, grid);

                ans = min(ans, a + b + d);

                a = area(0, 0, r, c, grid);
                b = area(0, c + 1, r, cols - 1, grid);
                d = area(r + 1, 0, rows - 1, cols - 1, grid);

                ans = min(ans, a + b + d);

                b = area(r + 1, 0, rows - 1, c, grid);
                d = area(0, c + 1, rows - 1, cols - 1, grid);

                ans = min(ans, a + b + d);

            }
        }
        return ans;
    }
};