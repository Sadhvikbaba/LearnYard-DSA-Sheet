class Solution {
private:
    int func(vector<int>& arr, int x) {
        int cnt = 0;
        for(int i = 0; i < 50; i++) {
            cnt += arr[i];
            if(cnt >= x) return i - 50;
        }
        return 0;
    }
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> cnt(101), ans;

        auto func = [&]() {
            int cur = 0;

            for(int i = 0; i < 50; i++) {
                cur += cnt[i];
                if(cur >= x)
                    return i - 50;
            }

            return 0;
        };

        while(right < k) {
            cnt[nums[right++] + 50]++;
        }
        ans.push_back(func(cnt, x));

        while(right < n) {
            cnt[nums[right++] + 50]++;
            cnt[nums[left++] + 50]--;
            ans.push_back(func(cnt, x));
        }
        return ans;
    }
};