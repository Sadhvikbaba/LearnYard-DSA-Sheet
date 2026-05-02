class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mpp;
        int n = strs.size();

        if(strs.size() == 0) return {{""}};
        if(strs.size() == 1) return {strs};

        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto& it : mpp){
            vector<string> temp;
            for(int& i : it.second){
                temp.push_back(strs[i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};