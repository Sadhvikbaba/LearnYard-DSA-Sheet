class Solution {

int func(vector<int>& nums, int n) {
    int low = 0, high = nums.size() - 1, ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] <= n) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    if(ans == -1) return 0;
    return ans + 1;
}
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++) nums[i] += nums[i - 1];

        for(const int& it : queries) {
            ans.push_back(func(nums, it));
        }

        return ans;
    }
};