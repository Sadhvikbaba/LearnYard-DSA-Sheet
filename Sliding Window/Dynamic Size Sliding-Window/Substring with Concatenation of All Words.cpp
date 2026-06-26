class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen = words[0].size(), n = s.size(), m = words.size();
        unordered_map<string, int> mpp;
        mpp.reserve(m);

        if(wordLen * m > s.size()) return {};

        for(const string& str : words) mpp[str]++;

        for(int i = 0; i < wordLen; i++) {
            unordered_map<string, int> window;
            window.reserve(m);
            int left = i, match = 0;

            for(int right = i; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                auto it = mpp.find(word);

                if(it == mpp.end()) {
                    window.clear();
                    match = 0;
                    left = right + wordLen;
                } else {
                    window[word]++;
                    match++;

                    while(window[word] > it -> second) {
                        string temp = s.substr(left, wordLen);
                        window[temp]--;
                        left += wordLen;
                        match--;
                    }
                }

                if(match == m) {
                    ans.push_back(left);
                    string temp = s.substr(left, wordLen);
                    window[temp]--;
                    left += wordLen;
                    match--;
                }
            }
        }
        return ans;
    }
};