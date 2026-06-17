class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0, n = word1.size(), m = word2.size();
        string ans = "";

        while(i < n && j < m) {
            if(word1[i] == word2[j]) {
                if(lexicographical_compare(word1.begin() + i, word1.end(), word2.begin() + j, word2.end())) ans.push_back(word2[j++]);
                else ans.push_back(word1[i++]);
            } else if(word1[i] < word2[j]) {
                ans.push_back(word2[j]);
                j++;
            } else {
                ans.push_back(word1[i]);
                i++;
            }
        }

        while(i < n) ans.push_back(word1[i++]);
        while(j < m) ans.push_back(word2[j++]);

        return ans;
    }
};