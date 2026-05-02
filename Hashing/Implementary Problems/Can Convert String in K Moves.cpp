class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int> count(26, 0);

        for(int i = 0; i < n; i++) {
            int diff = (t[i] - s[i] + 26) % 26;
            if(diff == 0) continue;

            count[diff]++;
        }
        for(int i = 1; i < 26; i++) {
            if(count[i] > 0) {
                int maxMove = i + 26 * (count[i] - 1);
                if(maxMove > k) return false;
            }
        }

        return true;
    }
};