class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> mat1, mat2;
        int rows = img1.size(), cols = img2.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(img1[i][j]) mat1.push_back({i,j});
                if(img2[i][j]) mat2.push_back({i,j});
            }
        }

        for(auto& [r1, c1] : mat1) {
            for(auto &[r2, c2] : mat2) {
                int row = r2 - r1;
                int col = c2 - c1;
                int key = (row + 30) * 100 + (col + 30);
                mpp[key]++;
            }
        }

        int ans = 0;

        for(auto& [a, b] : mpp) {
            ans = max(ans, b);
        }
        return ans;
    }
};