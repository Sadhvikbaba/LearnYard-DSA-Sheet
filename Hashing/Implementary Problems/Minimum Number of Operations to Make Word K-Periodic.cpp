class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> mpp;
        int n = word.size();

        for(int i = 0; i < n; i += k) {
            string temp = word.substr(i, k);
            mpp[temp]++;
        }
        int maxi = 0;

        for(const auto& [temp, it] : mpp) {
            maxi = max(maxi, it);
        }

        return (n / k) - maxi ;
    }
};