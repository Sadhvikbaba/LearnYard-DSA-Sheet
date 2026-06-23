class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mpp(26);
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        int n = s.size(), cnt = 0;

        for(const char& it : p) {
            if(mpp[it - 'a'] == 0)cnt++;
            mpp[it - 'a']++;
        }

        for(int i = 0; i < p.size(); i++) { 
            mpp[s[i] - 'a']--;
            if(mpp[s[i] - 'a'] == 0)cnt--;
        }
        if(cnt == 0) ans.push_back(0);
        int r = p.size(), l = 0;

        while(r < n) {
            char ch = s[r++];
            mpp[ch - 'a']--;
            if(mpp[ch - 'a'] == 0) cnt--;

            mpp[s[l] - 'a']++;
            if(mpp[s[l] - 'a'] == 1) cnt++;
            l++;
            if(cnt == 0) ans.push_back(l);
        }
        return ans;
    }
};