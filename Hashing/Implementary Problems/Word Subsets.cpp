class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mpp(26, 0);
        int n = words1.size();

        for(string& str : words2){
            vector<int> temp(26, 0);
            for(char ch : str){
                temp[ch - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                mpp[i] = max(mpp[i], temp[i]);
            }
        }

        vector<string> ans;

        for(int i = 0; i < n; i++){
            vector<int> temp(26, 0);
            for(char& ch : words1[i]) {
                temp[ch - 'a']++;
            }

            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(temp[i] < mpp[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(words1[i]);
        }

        return ans;
    }
};