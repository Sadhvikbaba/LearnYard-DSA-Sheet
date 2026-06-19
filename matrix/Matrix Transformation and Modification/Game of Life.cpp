class Solution {
private:
    int cntN(int n, int m, vector<vector<int>>& board) {
        int ans = 0, rows = board.size(), cols = board[0].size();

        for(int i = n - 1; i <= n + 1; i++) {
            for(int j = m - 1; j <= m + 1; j++) {
                if(i == n && j == m) continue;
                if(i >= 0 && j >= 0 && i < rows && j < cols) {
                    if(board[i][j] == 1 or board[i][j] == -1) ans++;
                }
            }
        }
        return ans;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int cnt = cntN(i, j, board);
                if(board[i][j]) {
                    if(cnt < 2 || cnt > 3) board[i][j] = -1;
                } else if(cnt == 3) board[i][j] = 2;
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == 2) board[i][j] = 1; 
            }
        }
    }
};