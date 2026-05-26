class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            vector<bool> check(n + 2, false);
            check[nums[i]] = true;
            for(int j = i + 1; j < n; j++) {
                if(check[nums[j]]) {
                    ans += cnt;
                    continue;
                }
                bool left = check[nums[j] - 1], right = check[nums[j] + 1];

                if(!left && !right) cnt++;
                else if(left && right) cnt--;
                check[nums[j]] = true;
                ans += cnt;
            }
        }
        return ans;
    }
};