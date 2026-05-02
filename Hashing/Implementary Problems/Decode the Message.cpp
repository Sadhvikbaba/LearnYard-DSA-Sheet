class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mpp;
        mpp[' '] = ' ';
        int n = key.size();
        int temp = 0;

        for(int i = 0; i < n; i++){
            if(mpp.find(key[i]) == mpp.end()){
                mpp[key[i]] = temp + 'a'; 
                temp++;
            } 
        }

        string ans;

        for(char ch : message){
            ans.push_back(mpp[ch]);
        }

        return ans;
    }
};