class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rows = grid.size(), cols = grid[0].size();
        int size = rows * cols;
        vector<int> arr(size);
        int rem = grid[0][0] % x;

        for(int i = 0; i < size; i++) {
            arr[i] = grid[i / cols][i % cols];
            if(arr[i] % x != rem) return -1;
        }

        nth_element(arr.begin(), arr.begin() + size / 2, arr.end());
        int median = arr[size / 2], ans = 0;

        for(const int& it : arr) {
            ans += abs(it - median) / x;
        }

        return ans;
    }
};