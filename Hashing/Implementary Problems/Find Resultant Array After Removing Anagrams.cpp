class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for(string& str : words){
            string temp = str;
            sort(temp.begin(), temp.end());

            if(ans.empty()) ans.push_back(str);
            else {
                string prev = ans.back();
                sort(prev.begin(), prev.end());

                if(prev != temp) ans.push_back(str);
            }
        }
        return ans;
    }
};