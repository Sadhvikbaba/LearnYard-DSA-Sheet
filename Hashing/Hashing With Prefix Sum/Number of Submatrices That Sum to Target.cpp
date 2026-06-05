class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = 0;

        for(int top = 0; top < rows; top++) {
            vector<int> colSum(cols,0);
            for(int bottom = top; bottom < rows; bottom++) {
                for(int i = 0; i < cols; i++) colSum[i] += matrix[bottom][i];
                unordered_map<int, int> mpp;
                mpp.reserve(cols * 2);
                mpp[0] = 1;
                int sum = 0;
                for(const int& it : colSum) {
                    sum += it;
                    int req = sum - target;
                    auto temp = mpp.find(req);
                    if(temp != mpp.end()) ans += temp -> second;
                    mpp[sum]++;
                }
            }
        }
        return ans;
    }
};