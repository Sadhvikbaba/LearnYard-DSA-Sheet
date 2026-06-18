class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<bool> rowMat(rows), colMat(rows);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    rowMat[i] = true;
                    colMat[j] = true;
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            if(rowMat[i]) {
                for(int j = 0; j < cols; j++) matrix[i][j] = 0;
            }
        }

        for(int j = 0; j < cols; j++) {
            if(colMat[j]) {
                for(int i = 0; i < rows; i++) matrix[i][j] = 0;
            }
        }
    }
};