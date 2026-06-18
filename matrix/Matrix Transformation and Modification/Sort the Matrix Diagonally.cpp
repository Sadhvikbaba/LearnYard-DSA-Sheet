class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> temp;
        int i, j;

        for(int k = -(rows - 1); k <= cols - 1; k++) {
            if(k >= 0) { i = 0; j = k; } 
            else { i = -k; j = 0; }

            for(; i < rows && j < cols; i++, j++) {
                temp.push_back(mat[i][j]);
            }

            sort(temp.begin(), temp.end());
            int ind = 0;
            if(k >= 0) { i = 0; j = k; } 
            else { i = -k; j = 0; }

            for(; i < rows && j < cols; i++, j++) {
                mat[i][j] = temp[ind++];
            }
            temp.clear();
        }

        return mat;
    }
};