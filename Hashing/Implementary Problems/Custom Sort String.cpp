class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mpp;

        for(char& ch : s) mpp[ch]++;

        string ans = "";

        for(char& ch : order) {
            string a(mpp[ch], ch);
            ans += a;
            mpp.erase(ch);
        }

        for(auto& it : mpp) {
            string a(it.second, it.first);
            ans += a;
        }
        return ans;
    }
};