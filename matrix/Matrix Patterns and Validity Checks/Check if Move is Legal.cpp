class Solution {
private:
    bool check(vector<vector<char>>& board, int r, int c, int dr, int dc, char color) {
        int rows = board.size(), cols = board[0].size();
        bool seenOpp = false;
        char opp = (color == 'W') ? 'B' : 'W';
        for(int i = 1; true; i++) {
            int row = r + i * dr, col = c + i * dc;
            if(row < 0 || row >= rows || col < 0 || col >= cols) return false;
            if(board[row][col] == '.') return false;
            if(board[row][col] == opp) seenOpp = true;
            else if(board[row][col] == color) return seenOpp;
        }
        return false;
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(!i && !j) continue;
                if(check(board, rMove, cMove, i, j, color)) return true;
            }
        }
        return false;
    }
};