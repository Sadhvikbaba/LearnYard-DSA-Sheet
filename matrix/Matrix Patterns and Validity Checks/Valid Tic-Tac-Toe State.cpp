class Solution {
private:
    bool win(vector<string>& board, char p) {
        int diag1 = 0, diag2 = 0;
        for(int i = 0; i < 3; i++) {
            int row = 0, col = 0;
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == p) {
                    row++;
                    if(i == j) diag1++;
                    if(i + j == 2) diag2++;
                }
                if(board[j][i] == p) {
                    col++;
                }
                if(row == 3 || col == 3 || diag1 == 3 || diag2 == 3) return true;
            }
        }
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int X = 0, O = 0;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] =='X') X++;
                else if(board[i][j] == 'O') O++;

            }
        }
        if(O > X || X > O + 1) return false;
        bool XWin = win(board, 'X');
        if(XWin && X != O + 1) return false;
        bool OWin = win(board, 'O');
        if(OWin && X != O) return false;

        if(XWin && OWin) return false;
        return true;
    }
};