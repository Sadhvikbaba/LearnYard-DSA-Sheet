class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<bool> mRow(10, false);
            vector<bool> mCol(10, false);
            for(int j = 0; j < 9; j++) {

                if(board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    if(mRow[val])return false;
                    mRow[val] = true;
                }

                if(board[j][i] != '.') {
                    int val = board[j][i] - '0';
                    if(mCol[val])return false;
                    mCol[val] = true;
                }
            }
        }

        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3) {
                vector<bool> seen(10, false);
                for(int k = 0; k < 9; k++){
                    char ch = board[i + k / 3][j + k % 3];
                    if(ch == '.') continue;
                    int val = ch - '0';

                    if(seen[val]) return false;
                    seen[val] = true;
                }
            }
        }

        return true;
    }
};