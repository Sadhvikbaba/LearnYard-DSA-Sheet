class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), l = 0, r = 0, cnt = 0, ans = 0;
        vector<int> hash(26);
        unordered_map<string, int> mpp;
        while(r < minSize) {
            hash[s[r] - 'a']++;
            if(hash[s[r++] - 'a'] == 1) cnt++;
        }
        if(cnt <= maxLetters) mpp[s.substr(0, minSize)]++;

        while(r < n) {

            hash[s[l] - 'a']--;
            if(hash[s[l++] - 'a'] == 0) cnt--;

            hash[s[r] - 'a']++;
            if(hash[s[r++] -'a'] == 1)cnt++;

            if(cnt <= maxLetters) mpp[s.substr(l, minSize)]++;
        }
        for(const auto& [str, val] : mpp) {
            ans = max(ans, val);
        }
        return ans;
    }
};