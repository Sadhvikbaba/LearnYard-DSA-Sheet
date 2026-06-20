class Solution {
private:
    int add(vector<vector<char>>& grid, int row, int col) {
        int ans = 0;
        for(int i = row; i < row + 2; i++) {
            for(int j = col; j < col + 2; j++) {
                if(grid[i][j] == 'W') ans++;
            }
        }
        return ans;
    }
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                int val = add(grid, i, j);
                if(val == 0 || val == 1 || val == 3 || val == 4) return true;
            }
        }
        return false;
    }
};