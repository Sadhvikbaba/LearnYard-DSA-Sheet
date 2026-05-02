class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26, 0);
        int ans = 0;

        for(char ch : chars) count[ch - 'a']++;

        for(string& word : words){
            vector<int> freq(26, 0);
            bool isValid = true;

            for(char ch : word){
                freq[ch - 'a']++;
                if(freq[ch - 'a'] > count[ch - 'a']){
                    isValid = false;
                    break;
                }
            }

            if(isValid) ans += word.size();
        }

        return ans;
    }
};