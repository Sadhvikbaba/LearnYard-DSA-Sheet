class Solution {
public:
    string sortString(string s) {
        int n = s.size();
        string ans= "";
        vector<int> check(26, 0);

        for(char& ch : s) check[ch - 'a']++;

        while(n){
            for(int i = 0; i < 26; i++){
                if(check[i]) {
                    check[i]--;
                    ans.push_back(i + 'a');
                    n--;
                }
            }

            for(int i = 25; i >= 0; i--){
                if(check[i]) {
                    check[i]--;
                    ans.push_back(i + 'a');
                    n--;
                }
            }
        }
        return ans;
    }
};