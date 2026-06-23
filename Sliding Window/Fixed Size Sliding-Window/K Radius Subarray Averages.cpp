class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int n = nums.size();
        if(2 * k + 1 > n) return vector<int>(n, -1);
        vector<int> ans(n, -1);

        int left = 0, right = 0;
        long long sum = 0;

        for(; right < n && right < 2 * k + 1; right++) {
            sum += nums[right];
        }
        long long avg = sum / (2 * k + 1);
        ans[k] = avg;

        while(right < n) {
            sum += nums[right++];
            sum -= nums[left++];
            
            avg = sum / (2 * k + 1);
            ans[left + k] = avg;
        }
        return ans;
    }
};