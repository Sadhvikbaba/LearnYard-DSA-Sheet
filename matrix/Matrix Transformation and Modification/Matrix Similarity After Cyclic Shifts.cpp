class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        k = k % mat[0].size();
        int rows = mat.size(), cols = mat[0].size();
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(mat[i][(j + k) % cols] != mat[i][j]) return false;
            }
        }
        return true;
    }
};