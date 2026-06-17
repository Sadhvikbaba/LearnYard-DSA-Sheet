class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowel = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        vector<int> ids;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(vowel.find(s[i]) != vowel.end()) ids.push_back(i);
        }
        int i = 0, j = ids.size() - 1;

        while(i < j) {
            swap(s[ids[i]], s[ids[j]]);
            i++;
            j--;
        }
        return s;
    }
};