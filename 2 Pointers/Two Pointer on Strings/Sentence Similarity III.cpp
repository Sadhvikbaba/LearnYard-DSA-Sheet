class Solution {
private:
    vector<string> split(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word) words.push_back(word);
        return words;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> a = split(s1), b = split(s2);

        if(a.size() < b.size()) swap(a, b);
        int n = a.size(), m = b.size();
        int i = 0, j = 0;

        while(i < m && a[i] == b[i]) i++;
        while(j < m - i && a[n - j - 1] == b[m - j - 1]) j++;

        return i + j >= m;
    }
};