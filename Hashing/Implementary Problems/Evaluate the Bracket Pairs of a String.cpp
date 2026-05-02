class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for (const auto& it : knowledge) {
            mpp[it[0]] = it[1];
        }

        string ans;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                i++; 
                string key;

                while (i < n && s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }

                if (mpp.count(key)) {
                    ans += mpp[key];
                } else {
                    ans += '?';
                }
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};