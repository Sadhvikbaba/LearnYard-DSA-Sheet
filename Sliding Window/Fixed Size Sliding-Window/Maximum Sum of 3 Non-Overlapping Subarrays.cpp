class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preWin;
        long long sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        preWin.push_back(sum);

        for(int i = k; i < n; i++) {
            sum -= nums[i - k];
            sum += nums[i];
            preWin.push_back(sum);
        }
        n = preWin.size();

        vector<int> left(n), right(n);
        left[0] = 0;

        for(int i = 1; i < n; i++) {
            if(preWin[i] > preWin[left[i - 1]]) left[i] = i;
            else left[i] = left[i - 1];
        }

        right.back() = n - 1;

        for(int i = n - 2; i >= 0; i--) {
            if(preWin[i] >= preWin[right[i + 1]]) right[i] = i;
            else right[i] = right[i + 1];
        }
        int mid;
        vector<int> ans(3);
        sum = 0;

        for(mid = k; mid < n - k; mid++) {
            int l = left[mid - k];
            int r = right[mid + k];
            long long temp = 1ll * preWin[l] + preWin[r] + preWin[mid];

            if(temp > sum) {
                sum = temp;
                ans = {l, mid, r};
            }
        }
        return ans;
    }
};