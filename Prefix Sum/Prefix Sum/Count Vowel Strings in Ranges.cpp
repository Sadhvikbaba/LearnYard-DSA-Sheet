class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> count, ans;
        int sum = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(const string& word : words) {
            if(vowels.find(word[0]) != vowels.end() && vowels.find(word[word.size() - 1]) != vowels.end()) {
                sum++;
            }
            count.push_back(sum);
        }

        for(const auto& it : queries) {
            if(it[0] == 0) ans.push_back(count[it[1]]);
            else ans.push_back(count[it[1]] - count[it[0] - 1]);
        }
        return ans;
    }
};