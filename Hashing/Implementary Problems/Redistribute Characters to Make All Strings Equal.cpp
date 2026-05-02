class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> mpp(26, 0);
        int n = words.size();

        for(string& str : words){
            for(char& ch : str) mpp[ch - 'a']++;
        }

        for(int& it : mpp) if(it % n != 0) return false;

        return true;
    }
};