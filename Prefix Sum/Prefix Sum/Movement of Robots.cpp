class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> count(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') count[i] = 1ll * nums[i] - d;
            else count[i] = 1ll * nums[i] + d;
        }
        sort(count.begin(), count.end());

        long long ans = 0;
        long long prefix = 0;

        for(int i = 0; i < n; i++) {
            ans =  (ans + (i * count[i] - prefix)) % (1000000007);
            prefix += count[i];
        }

        return ans;
    }
};