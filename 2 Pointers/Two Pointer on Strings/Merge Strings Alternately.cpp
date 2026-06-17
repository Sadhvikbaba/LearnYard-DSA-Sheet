class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans ="";
        int i = 0, j = 0, n = word1.size(), m = word2.size();

        while(i < n && j < m) {
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }
        while(i < n) ans.push_back(word1[i++]);
        while(j < m) ans.push_back(word2[j++]);
        return ans;
    }
};