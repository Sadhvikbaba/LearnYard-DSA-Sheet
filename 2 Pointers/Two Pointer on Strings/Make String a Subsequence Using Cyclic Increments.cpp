class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0, n = str1.size(), m = str2.size();
        while(j < m && i < n) {
            char a = str1[i], b = str2[j];
            if((a == b) || ((a - 'a' + 1) % 26 + 'a') == b) {
                i++;
                j++;
            } else i++;
        }
        return j == m;
    }
};