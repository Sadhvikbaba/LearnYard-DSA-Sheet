class Solution {
private:
    vector<vector<int>> sumContribution, countContribution;
    void func(vector<vector<int>>& mat, int r, int c, int threshold) {

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 2; j++) {
                if(abs(mat[i + r][j + c] - mat[i + r][j + c + 1]) > threshold) return;
            }
        }
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                if(abs(mat[i + r][j + c] - mat[i + r + 1][j + c]) > threshold) return;
            }
        }
        long long sum = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                sum += mat[r + i][c + j];
                countContribution[r + i][c + j]++;
            }
        }
        int avg = sum / 9;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                sumContribution[r + i][c + j] += avg;
            }
        }
    }
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int rows = image.size(), cols = image[0].size();

        sumContribution.resize(rows, vector<int>(cols));
        countContribution.resize(rows, vector<int>(cols));

        for(int i = 0; i < rows - 2; i++) {
            for(int j = 0; j < cols - 2; j++) {
                func(image, i, j, threshold);
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(countContribution[i][j] == 0) {
                    sumContribution[i][j] = image[i][j];
                } else sumContribution[i][j] /= countContribution[i][j];
            }
        }
        return sumContribution;
    }
};