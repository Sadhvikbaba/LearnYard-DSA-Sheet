class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.size();

        while(j < n) {
            while(j < n && s[j] != ' ')j++;
            reverse(s.begin() + i, s.begin() + j);
            j++;
            i = j;
        }
        return s;
    }
};