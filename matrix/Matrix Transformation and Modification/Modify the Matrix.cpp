class Solution {
private:
    int getMax(vector<vector<int>>& matrix, int cols) {
        int rows = matrix.size(), maxi = INT_MIN;

        for(int i = 0; i < rows; i++) {
            maxi = max(maxi, matrix[i][cols]);
        }
        return maxi;
    }
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = getMax(matrix, j);
                }
            }
        }
        return matrix;
    }
};