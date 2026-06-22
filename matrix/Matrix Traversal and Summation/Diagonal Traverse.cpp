class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> ans;
        int size = rows + cols - 1;

        for(int i = 0; i < size; i++) {
            int size = ans.size();
            int r = (i < cols) ? 0 : i - cols + 1;
            int c = i - r;

            while(r < rows && c >= 0) ans.push_back(mat[r++][c--]);

            if(i % 2 == 0) reverse(ans.begin() + size, ans.end());
        }
        return ans;
    }
};