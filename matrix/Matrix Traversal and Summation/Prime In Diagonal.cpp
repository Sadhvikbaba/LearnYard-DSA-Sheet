class Solution {
private:
    bool isPrime(int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size();
        for (int i = 0; i < n; i++) {
            if(isPrime(mat[i][i])) ans = max(ans, mat[i][i]);
            if(isPrime(mat[i][n - i - 1])) ans = max(ans, mat[i][n - i - 1]);
        }
        return ans;
    }
};