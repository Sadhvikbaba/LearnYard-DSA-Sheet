class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;

        for(const int& it : spells) {
            long long target = (success + it - 1) / it;
            int ind = lower_bound(potions.begin(), potions.end(), target) - potions.begin();

            ans.emplace_back(n - ind);
        }

        return ans;
    }
};