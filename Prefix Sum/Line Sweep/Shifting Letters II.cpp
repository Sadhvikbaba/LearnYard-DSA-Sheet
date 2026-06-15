class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> mpp(n + 1);

        for(const vector<int>& it : shifts) {
            if(it[2] == 1) {
                mpp[it[0]]++;
                mpp[it[1] + 1]--;
            } else {
                mpp[it[0]]--;
                mpp[it[1] + 1]++;
            }
        }

        for(int i = 1; i < n; i++) {
            mpp[i] += mpp[i - 1];
        }

        for(int i = 0; i < n; i++) {
            int shift = ((mpp[i] % 26) + 26) % 26;
            int pos = (s[i] - 'a' + shift) % 26;
            s[i] = pos + 'a';
        }

        return s;
    }
};