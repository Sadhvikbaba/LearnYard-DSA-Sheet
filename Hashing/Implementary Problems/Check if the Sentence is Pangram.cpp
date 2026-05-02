class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.size() < 26) return false;
        vector<bool> mpp(26, false);

        for(char& ch : s){
            mpp[ch - 'a'] = true;
        }

        for(bool it : mpp)if(!it)return false;

        return true;
    }
};