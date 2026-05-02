class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mpp;
        int ans = 0;

        for(char it : s)mpp[it]++;

        for(auto& it : mpp){
            if(ans == 0) ans = it.second;
            else if(ans != it.second) return false;
        }

        return true;
    }
};