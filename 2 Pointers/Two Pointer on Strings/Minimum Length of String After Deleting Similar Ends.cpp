class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1, n = s.size();

        while(i < j && s[i] == s[j]) {
            char ch = s[i];

            while(i <= j && s[i] == ch) i++;
            while(i <= j && s[j] == ch) j--;
        }
        return j - i + 1;
    }
};