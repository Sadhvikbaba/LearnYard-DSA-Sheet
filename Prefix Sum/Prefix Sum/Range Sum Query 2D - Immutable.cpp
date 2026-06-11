class NumMatrix {
private:
    vector<vector<long long>> prefixMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        prefixMatrix.resize(rows + 1, vector<long long>(cols + 1, 0));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                prefixMatrix[i + 1][j + 1] = 1ll * matrix[i][j] + prefixMatrix[i][j + 1] + prefixMatrix[i + 1][j] - prefixMatrix[i][j];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return (1ll * prefixMatrix[r2 + 1][c2 + 1] - prefixMatrix[r1][c2 + 1] - prefixMatrix[r2 + 1][c1] + prefixMatrix[r1][c1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */