class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int ans = -1, n = s.size();

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';

            if(first[idx] == -1) first[idx] = i;
            else ans = max(ans, i - first[idx] - 1);
        }
        return ans;
    }
};