class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int, int>> pos(26);

        for(char ch = 'a'; ch <= 'z'; ch++) {
            int col = (ch - 'a') % 5;
            int row = (ch - 'a') / 5;
            pos[ch - 'a'] = {row, col};
        }

        int row = 0, col = 0;
        string ans = "";

        for(const char& ch : target) {
           int newRow = pos[ch - 'a'].first;
           int newCol = pos[ch - 'a'].second;

           while(row > newRow) { ans += 'U'; row--; }
           while(col > newCol) { ans += 'L'; col--; }
           while(row < newRow) { ans += 'D'; row++; }
           while(col < newCol) { ans += 'R'; col++; }

           ans += '!';
        }

        return ans;
    }
};