class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mpp;
        int mini = INT_MAX;

        for(const int& it : basket1) {
            mini = min(mini, it);
            mpp[it]++;
        }

        for(const int& it : basket2) {
            mini = min(mini, it);
            mpp[it]--;
        }

        vector<int> extra1, extra2;

        for(const auto& it : mpp) {
            int temp = abs(it.second);
            if(temp & 1) return -1;

            if(it.second > 0) extra1.insert(extra1.end(), temp / 2, it.first);
            else extra2.insert(extra2.end(), temp / 2, it.first);
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        long long ans = 0;
        int n = extra1.size();

        for(int i = 0; i < n; i++) {
            ans += min(2 * mini, min(extra1[i], extra2[i]));
        }

        return ans;
    }
};