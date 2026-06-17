class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int lastSeen = -1, n = s.size();
        vector<int> ans(n, INT_MAX);

        for(int i = 0; i < n; i++) {
            if(lastSeen == -1) ans[i] = INT_MAX;
            if(s[i] == c) {
                lastSeen = i;
                ans[i] = 0;
            } else if(lastSeen != -1){
                ans[i] = min(ans[i], i - lastSeen);
            }
        }

        lastSeen = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == c) {
                lastSeen = i;
            } else {
                if(lastSeen != -1)ans[i] = min(ans[i], lastSeen - i);
            }
        }
        return ans;
    }
};