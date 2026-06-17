class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1, n = word.size();
        for(int i = 0; i < n; i++) {
            if(word[i] == ch) {
                idx = i + 1;
                break;
            }
        }
        if(idx != -1) reverse(word.begin(), word.begin() + idx);
        return word;
    }
};