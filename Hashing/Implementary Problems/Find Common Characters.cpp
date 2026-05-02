class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       int n = words.size();

       vector<int> freq(26, INT_MAX);

       for(string& word : words){
        vector<int> temp(26, 0);

        for(char ch : word)temp[ch - 'a']++;

        for(int i = 0; i < 26; i++) freq[i] = min(freq[i], temp[i]);
       }

       vector<string> ans;

       for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                ans.push_back(string(1, 'a' + i));
                freq[i]--;
            }
       }

       return ans;
    }
};