class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mpp;
        int maxi = 1;

        for(int& it : nums) mpp[it]++;

        for(auto& it : mpp) {
            if(it.first == 1) continue;
            int length = 1 ;
            long long value = it.first;
            while (mpp[value] >= 2) {
                long long next = value * value;

                if (next > 1e18 || mpp.find(next) == mpp.end()) break;

                length += 2;
                value = next;
            }
            maxi = max(maxi, length);
        }

        if (mpp.count(1)) {
            int c = mpp[1];
            int ones = (c % 2 == 0) ? c - 1 : c;
            maxi = max(maxi, ones);
        }

        return maxi;
    }
};