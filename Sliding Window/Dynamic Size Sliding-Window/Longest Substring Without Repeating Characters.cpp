class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        vector<int>hash(256, -1);

        int l = 0, r = 0;

        while(r < s.size()){
            if(hash[s[r]] != -1)l = max(l, hash[s[r]] + 1);

            int len = r - l + 1;

            maxLen = max(len, maxLen);

            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};