class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mpp;
        map<string, char> rev;

        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word){
            words.push_back(word);
        }

        if(words.size() != pattern.size()) return false;

        for(int i = 0; i < pattern.size(); i++){
            char p = pattern[i];
            string w = words[i];

            if(mpp.count(p)){
                if(mpp[p] != w) return false;
            } else {
                mpp[p] = w;
            }

            if(rev.count(w)){
                if(rev[w] != p) return false;
            } else {
                rev[w] = p;
            }
        }

        return true;
    }
};