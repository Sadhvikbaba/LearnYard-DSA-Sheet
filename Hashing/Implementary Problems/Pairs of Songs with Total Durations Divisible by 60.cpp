class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mpp(60, 0);
        int ans = 0;

        for(const int& it : time) {
            int rem = it % 60;
            int need = (60 - rem) % 60;

            ans += mpp[need];
            mpp[rem]++;
        }
        return ans;
    }
};