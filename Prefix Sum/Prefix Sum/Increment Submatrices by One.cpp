class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for(const auto& it : queries) {
            matrix[it[0]][it[1]]++;
            if(it[2] + 1 < n) matrix[it[2] + 1][it[1]]--;
            if(it[3] + 1 < n) matrix[it[0]][it[3] + 1]--;
            if(it[2] + 1 < n && it[3] + 1 < n) matrix[it[2] + 1][it[3] + 1]++;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i > 0) matrix[i][j] += matrix[i - 1][j];
                if(j > 0) matrix[i][j] += matrix[i][j - 1];
                if(j > 0 && i > 0) matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }

        return matrix;

    }
};