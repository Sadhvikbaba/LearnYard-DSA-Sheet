class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k, n = s.size();

        vector<bool> seen(need);

        int allBits = need - 1, mask = 0, cnt = 0;

        for(int i = 0; i < n; i++) {
            mask = ((mask << 1) & allBits) | (s[i] - '0');

            if(i >= k - 1 && !seen[mask]) {
                seen[mask] = true;
                cnt++;
            if(cnt == need) return true;
            }
        }
        return false;
    }
};