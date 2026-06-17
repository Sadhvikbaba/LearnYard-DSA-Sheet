class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int rows, int cols) {
        int n = arr.size();
        if(rows * cols != n) return {};
        vector<vector<int>> matrix(rows, vector<int>(cols));

        for(int i = 0; i < n; i++) {
            matrix[i / cols][i % cols] = arr[i];
        }
        return matrix;
    }
};