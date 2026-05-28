class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int freq[100001] = {}, count[100001] = {};
        int max_freq = 0, len = 1, res = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            int it = nums[i];
            int old_c = count[it];
            if(old_c > 0) freq[old_c]--;
            count[it]++;
            freq[count[it]]++;

            max_freq = max(max_freq, count[it]);
            int len = i + 1;
            bool valid = false;

            if(max_freq == 1) valid = true;
            else if(freq[max_freq] == 1 && max_freq + 1LL * freq[max_freq - 1] * (max_freq - 1) == len ) valid = true;
            else if(freq[1] == 1 && (1ll + 1ll * freq[max_freq] * max_freq == len)) valid = true;

            if(valid) res = len;
            len++;
        }

        return res;
    }
};