class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long)n * (n - 1) / 2;

        unordered_map<long long, long long> freq;
        long long good = 0;

        for(int i = 0; i < n; i++){
            long long key = nums[i] - i;

            if(freq.count(key)) good += freq[key];
            freq[key]++;
        }

        return total - good;
    }
};