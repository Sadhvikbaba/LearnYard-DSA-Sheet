class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mpp(k, 0);
        int sum = 0, cnt = 0;
        mpp[0] = 1;

        for(int& it: nums) {
            sum = ((sum + it) % k + k) % k;
            cnt += mpp[sum];
            mpp[sum]++;
        }
        return cnt;
    }
};