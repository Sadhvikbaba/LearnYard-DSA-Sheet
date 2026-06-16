class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> diff(n + 1), ans;

        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                int l = max(0, i - k);
                int r = min(n - 1, i + k);
                diff[l]++;
                diff[r + 1]--;
            }
        }

        if(diff[0]) ans.push_back(0);

        for(int i = 1; i < n ; i++) {
            diff[i] += diff[i - 1];
            if(diff[i]) ans.push_back(i);
        }
        return ans;
    }
};