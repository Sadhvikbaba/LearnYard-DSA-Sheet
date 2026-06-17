class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j) {
            s[i++] = s[j--] = min(s[i], s[j]);
        }
        return s;
    }
};