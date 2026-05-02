class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> mp = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };

        string ans = "";
        int n = text.size();

        for(int i = 0; i < n; i++){
            if(text[i] == '&'){
                int j = i;

                while(j < n && text[j] != ';') j++;

                if(j < n){
                    string sub = text.substr(i, j - i + 1);

                    if(mp.count(sub)){
                        ans += mp[sub];
                        i = j;
                        continue;
                    }
                }
            }

            ans += text[i];
        }

        return ans;
    }
};