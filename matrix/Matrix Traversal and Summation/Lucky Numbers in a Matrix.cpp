class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<pair<int, int>> minRow(rows,{INT_MAX, -1}), maxCol(cols, {INT_MIN, -1});
        vector<int> ans;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                if(minRow[i].first > matrix[i][j]) minRow[i] = {matrix[i][j], j};
                if(maxCol[j].first < matrix[i][j]) maxCol[j] = {matrix[i][j], i};
            }
        }
        for(const auto& [val, col] : minRow) {
            if(val == maxCol[col].first) ans.push_back(val);
        }
        return ans;
    }
};