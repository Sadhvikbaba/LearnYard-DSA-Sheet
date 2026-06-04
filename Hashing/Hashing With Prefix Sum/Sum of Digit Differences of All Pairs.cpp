class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int digits = 0;
        int x = nums[0];

        while(x) {
            digits++;
            x /= 10;
        }

        long long ans = 0;
        int power = 1;

        for(int i = 0; i < digits; i++) {
            vector<int> freq(10, 0);
            int pro = 0;
            for(const int& it : nums) {
                int digit = (it / power) % 10;
                ans += pro++ - freq[digit]++;
            }
            power *= 10;
        }
        return ans;
    }
};